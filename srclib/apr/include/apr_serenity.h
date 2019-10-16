/**
Copyright (c) 2017-2019 Roman Katuntsev <sbkarr@stappler.org>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
**/

#ifndef APR_SERENITY_H
#define APR_SERENITY_H

#include "apr_pools.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct serenity_memaddr_t serenity_memaddr_t;
typedef struct serenity_allocmngr_t serenity_allocmngr_t;

typedef void *(*serenity_alloc_fn) (void *, size_t, void *);
typedef void (*serenity_free_fn)(void *, void *, size_t, void *);

typedef void (*serenity_pool_fn) (apr_pool_t *, void *);
typedef void (*serenity_node_alloc_fn) (void *, void *, size_t, void *, void *);
typedef void (*serenity_node_free_fn) (void *, void *, size_t, void *);

struct serenity_memaddr_t {
	uint32_t size;
	serenity_memaddr_t *next;
	void *address;
};

struct serenity_allocmngr_t {
	apr_pool_t *pool;
	serenity_memaddr_t *buffered;
	serenity_memaddr_t *free_buffered;

	uint32_t tag;
	const void *ptr;

	size_t alloc_buffer;
	size_t allocated;
	size_t returned;
	size_t opts;
};

serenity_allocmngr_t *serenity_allocmngr_get(apr_pool_t *);
void serenity_allocmngr_clear(apr_pool_t *, serenity_allocmngr_t *);

void serenity_set_alloc_fn(serenity_alloc_fn, serenity_free_fn, void *);
void serenity_set_pool_ctrl_fn(serenity_pool_fn on_create, serenity_pool_fn on_free, void *);
void serenity_set_node_ctrl_fn(serenity_node_alloc_fn on_alloc, serenity_node_free_fn on_free, void *);
const char *serenity_pool_get_tag(apr_pool_t *);

#ifdef __cplusplus
}
#endif

#endif /* APR_SERENITY_H */
