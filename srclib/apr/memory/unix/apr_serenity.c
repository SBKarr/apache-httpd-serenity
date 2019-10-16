/**
Copyright (c) 2019 Roman Katuntsev <sbkarr@stappler.org>

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

#include "apr_serenity.h"
#include "apr_serenity_internal.h"

static serenity_alloc_fn s_serenity_alloc = NULL;
static serenity_free_fn s_serenity_free = NULL;
static void *s_serenity_mem_ptr = NULL;

static serenity_pool_fn s_serenity_pool_create = NULL;
static serenity_pool_fn s_serenity_pool_destroy = NULL;
static void *s_serenity_pool_ptr = NULL;

static serenity_node_alloc_fn s_serenity_node_alloc = NULL;
static serenity_node_free_fn s_serenity_node_free = NULL;
static void *s_serenity_node_ptr = NULL;

void * serenity_alloc(void *ptr, size_t s) {
	if (s_serenity_alloc) {
		return s_serenity_alloc(ptr, s, s_serenity_mem_ptr);
	} else {
		return malloc(s);
	}
}
void serenity_free(void *ptr, void *vp, size_t s) {
	if (s_serenity_free) {
		s_serenity_free(ptr, vp, s, s_serenity_mem_ptr);
	} else {
		free(vp);
	}
}

void serenity_pool_create(apr_pool_t *p) {
    serenity_allocmngr_clear(p, &p->alloc_manager);
	if (s_serenity_pool_create) {
		s_serenity_pool_create(p, s_serenity_pool_ptr);
	}
}

void serenity_pool_destroy(apr_pool_t *p) {
	if (s_serenity_pool_destroy) {
		s_serenity_pool_destroy(p, s_serenity_pool_ptr);
	}
}

void serenity_node_allocated(void *alloc, void *node, size_t s, void *owner) {
	if (s_serenity_node_alloc) {
		s_serenity_node_alloc(alloc, node, s, owner, s_serenity_node_ptr);
	}
}

void serenity_node_free(void *alloc, void *node, size_t s) {
	if (s_serenity_node_free) {
		s_serenity_node_free(alloc, node, s, s_serenity_node_ptr);
	}
}

APR_DECLARE(serenity_allocmngr_t *) serenity_allocmngr_get(apr_pool_t *p) {
	if (!p) {
		return NULL;
	}

	return &p->alloc_manager;
}

APR_DECLARE(void) serenity_allocmngr_clear(apr_pool_t *p, serenity_allocmngr_t *mngr) {
	memset(mngr, 0, sizeof(serenity_allocmngr_t));
	mngr->pool = p;
}

APR_DECLARE(void) serenity_set_alloc_fn(serenity_alloc_fn alloc_fn, serenity_free_fn free_fn, void *ptr) {
	s_serenity_alloc = alloc_fn;
	s_serenity_free = free_fn;
	s_serenity_mem_ptr = ptr;
}

APR_DECLARE(void) serenity_set_pool_ctrl_fn(serenity_pool_fn on_create, serenity_pool_fn on_free, void *ptr) {
	s_serenity_pool_create = on_create;
	s_serenity_pool_destroy = on_free;
	s_serenity_pool_ptr = ptr;
}

APR_DECLARE(void) serenity_set_node_ctrl_fn(serenity_node_alloc_fn on_alloc, serenity_node_free_fn on_free, void *ptr) {
	s_serenity_node_alloc = on_alloc;
	s_serenity_node_free = on_free;
	s_serenity_node_ptr = ptr;
}

APR_DECLARE(const char *) serenity_pool_get_tag(apr_pool_t *p) {
	if (!p || !p->tag) {
		return NULL;
	}

	return p->tag;
}
