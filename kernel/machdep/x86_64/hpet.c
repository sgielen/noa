/*-
 * Copyright (c) 2010 The Noa Project, http://noaproject.org/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <kernel.h>
#include <machdep.h>
#include <stdint.h>

#define	HPET_REG_CONFIG		0x10
#define	    HPET_LEG_RT_CNF	0x02
#define	    HPET_ENABLE_CNF	0x01
#define	HPET_REG_COUNTER	0xf0

static inline uint64_t
hpet_read(unsigned int reg)
{

	return (*(volatile uint64_t *)(0x0fed000f0 + reg));
}

static inline void
hpet_write(unsigned int reg, uint64_t value)
{

	*(volatile uint64_t *)(0x0fed000f0 + reg) = value;
}

void
hpet_init(void)
{
	uint64_t reg;
	uint64_t s1, s2;
	int same = 0;

	/* Disable the counter. */
	reg = hpet_read(HPET_REG_CONFIG);
	reg &= ~(HPET_LEG_RT_CNF|HPET_ENABLE_CNF);
	hpet_write(HPET_REG_CONFIG, reg);
	
	/* Reset the counter value. */
	hpet_write(HPET_REG_COUNTER, 0);

	/* Re-enable the counter. */
	reg |= HPET_ENABLE_CNF;
	hpet_write(HPET_REG_CONFIG, reg);

	/* See whether the hardware actually works. */
	s1 = hpet_read(HPET_REG_COUNTER);
	for (;;) {
		s2 = hpet_read(HPET_REG_COUNTER);
		if (s1 != s2)
			break;
		if (++same == 1000)
			panic("HPET timer missing");
	}
}
