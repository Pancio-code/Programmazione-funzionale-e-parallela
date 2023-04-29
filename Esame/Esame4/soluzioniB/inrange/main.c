// =====================================================================
//  main.c
// =====================================================================

//  Author:         (c) 2018 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Jan 30, 2018

//  Last changed:   $Date: 2017/02/13 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "inrange.h"

#define N         50000000
#define M         1000
#define SEED      971
#define MIN       50
#define MAX       80
#define DELTA     10
#define CMIN(a,b) ((a)<(b) ? (a):(b))


// ---------------------------------------------------------------------
// inrange_seq
// ---------------------------------------------------------------------
// sequential version

static
int inrange_seq(const short* min, unsigned minn,
                const short* v,   unsigned n,
                const short* max, unsigned maxn) {
    int i;
    n = CMIN(n, CMIN(minn, maxn));
    for (i=0; i<n; ++i)
        if (v[i]<min[i] || v[i]>max[i]) return 0;
    return 1;
}


// ---------------------------------------------------------------------
// get_real_time
// ---------------------------------------------------------------------
double get_real_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec*1E-06;
}


// ---------------------------------------------------------------------
// do_test
// ---------------------------------------------------------------------
static void do_test(const short* min, unsigned minn,
                    const short* v,   unsigned n,
                    const short* max, unsigned maxn, int test_no) {

    double start, tseq, tsse;
    int rseq, rsse;

    printf("\nTest #%d\n", test_no);

    // sequential
    start = get_real_time();
    rseq  = inrange_seq(min, minn, v, n, max, maxn);
    tseq  = get_real_time()-start;

    // SSE
    start = get_real_time();
    rsse  = inrange(min, minn, v, n, max, maxn);
    tsse  = get_real_time()-start;

    printf("- result: %d [expected: %d]\n", rsse, rseq);
    printf("- sequential version: %.2f msec\n", tseq*1000);
    printf("- SSE version: %.2f msec\n", tsse*1000);
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char** argv) {

    int i;
    short *min = malloc(N*sizeof(short));
    short *v   = malloc(N*sizeof(short));
    short *max = malloc(N*sizeof(short));
    assert(min != NULL);
    assert(v   != NULL);
    assert(max != NULL);

    printf("Input arrays of size %lu MB\n", N*sizeof(short)/(1024*1024));

    // init data
    srand(SEED);
    for (i=0; i<N; ++i) {
        v[i] = MIN + rand() % (MAX-MIN);
        if (i<N-M) {
            min[i] = v[i]-(1+rand() % DELTA);
            max[i] = v[i]+(1+rand() % DELTA);
        }
        else {
            min[i] = v[i]+((rand() % DELTA));
            max[i] = v[i]-((rand() % DELTA));
        }
    }

    do_test(min, N-M, v, N,   max, N,   1); // res == 1
    do_test(min, N,   v, N-M, max, N,   2); // res == 1
    do_test(min, N,   v, N,   max, N-M, 3); // res == 1
    do_test(min, N,   v, N,   max, N,   4); // res == 0

    free(min);
    free(v);
    free(max);

    return 0;
}


// Copyright (C) 2018 Camil Demetrescu

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
