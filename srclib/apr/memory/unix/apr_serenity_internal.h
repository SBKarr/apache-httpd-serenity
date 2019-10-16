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

#ifndef APR_SERENITY_INTERNAL_H
#define APR_SERENITY_INTERNAL_H

#include "apr_serenity.h"

#ifdef __cplusplus
extern "C" {
#endif


void *serenity_alloc(void *, size_t);
void serenity_free(void *, void *, size_t);

void serenity_pool_create(apr_pool_t *);
void serenity_pool_destroy(apr_pool_t *);

void serenity_node_allocated(void *, void *, size_t s, void *);
void serenity_node_free(void *, void *, size_t s);

#ifdef __cplusplus
}
#endif

#endif /* APR_SERENITY_INTERNAL_H */
