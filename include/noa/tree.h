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

#ifndef _NOA_TREE_H_
#define	_NOA_TREE_H_

/*
 * An unbalanced binary tree.
 */

#define	TREE_HEAD(name, type)						\
struct name {								\
	struct type	*th_head;					\
}

#define	TREE_ENTRY(type)						\
struct {								\
	struct type	*te_left;					\
	struct type	*te_right;					\
	struct type	**te_parent;					\
}

#define	TREE_INIT(head) do {						\
	(head)->th_head = NULL;						\
} while (0)

#define	TREE_COMPAR_NUMERICAL(name, etype, field, keytype)		\
static inline int							\
name(struct etype *e, keytype c)					\
{									\
	if (e->field > c)						\
		return (-1);						\
	else if (e->field < c)						\
		return (1);						\
	return (0);							\
}

#define	TREE_FUNCS(prefix, htype, etype, field, compar, keytype)	\
static inline struct etype *						\
prefix ## _lookup(struct htype *h, keytype k)				\
{									\
	struct etype *e;						\
	int c;								\
	for (e = h->th_head; e != NULL;) {				\
		c = compar(e, k);					\
		if (c > 0)						\
			e = e->field.te_left;				\
		else if (c < 0)						\
			e = e->field.te_right;				\
		else							\
			return (e);					\
	}								\
	return (NULL);							\
}									\
									\
static inline void							\
prefix ## _insert(struct htype *h, struct etype *e, cookie_t k)		\
{									\
	struct etype **p;						\
	int c;								\
	p = &h->th_head;						\
	while (*p != NULL) {						\
		c = compar(*p, k);					\
		if (c > 0)						\
			p = &(*p)->field.te_left;			\
		else							\
			p = &(*p)->field.te_right;			\
	}								\
	e->field.te_left = NULL;					\
	e->field.te_right = NULL;					\
	e->field.te_parent = p;						\
	*p = e;								\
}									\
									\
static inline struct etype *						\
__ ## prefix ## _min(struct etype *e)					\
{									\
	while (e->field.te_left != NULL)				\
		e = e->field.te_left;					\
	return (e);							\
}									\
									\
static inline void							\
prefix ## _remove(struct etype *e)					\
{									\
	struct etype *s;						\
	if (e->field.te_left == NULL) {					\
		*e->field.te_parent = e->field.te_right;		\
	} else if (e->field.te_right == NULL) {				\
		*e->field.te_parent = e->field.te_left;			\
	} else {							\
		s = __ ## prefix ## _min(e->field.te_right);		\
		*e->field.te_parent = s;				\
		*s->field.te_parent = s->field.te_right;		\
		s->field.te_left = e->field.te_left;			\
		s->field.te_right = e->field.te_right;			\
	}								\
}

#endif /* !_NOA_TREE_H_ */
