// =====================================================================
//  rand_perm.c
// =====================================================================

//  Author:         (c) 2013 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Feb 13, 2017

//  Last changed:   $Date: 2017/02/13 15:00:07 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <stdlib.h>
#include <assert.h>
#include "rand_perm.h"


typedef struct {
    unsigned key;
    int rnd;
} item_t;


// ---------------------------------------------------------------------
// cmp
// ---------------------------------------------------------------------
static int cmp(const void* ap, const void* bp) {
    item_t* a = (item_t*)ap;
    item_t* b = (item_t*)bp;
    return a->rnd - b->rnd;
}


// ---------------------------------------------------------------------
// rand_perm
// ---------------------------------------------------------------------
unsigned* rand_perm(unsigned n) {

    int i;

    unsigned* p = malloc(n*sizeof(unsigned));
    assert(p != NULL);

    item_t* a = malloc(n*sizeof(item_t));
    assert(a != NULL);
    
    srand(13);
    
    for (i=0; i<n; i++) {
        a[i].key = i;
        a[i].rnd = rand();
    }
    
    qsort(a, n, sizeof(item_t), cmp);    

    for (i=0; i<n; i++) p[i] = a[i].key;
    
    free(a);

    return p;
}



// Copyright (C) 2017 Camil Demetrescu

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
// USA
