// =====================================================================
//  main.c
// =====================================================================

//  Author:         (c) 2017 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Feb 13, 2017

//  Last changed:   $Date: 2017/02/13 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "inrange.h"

#define N       50000000
#define SEED    971
#define MIN     50
#define MAX     80


// ---------------------------------------------------------------------
// inrange_seq
// ---------------------------------------------------------------------
// sequential version

static int inrange_seq(const short* data, unsigned n, short min, short max) {
    int i;
    for (i=0; i<n; ++i) 
        if (data[i]<min || data[i]>max) return 0;
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
static void do_test(short* data, int n, short min, short max, int test_no) {

    double start, tseq, tsse;
    int rseq, rsse;

    printf("\nTest #%d\n", test_no);

    // sequential
    start = get_real_time();
    rseq  = inrange_seq(data, N, min, max);
    tseq  = get_real_time()-start;

    // SSE
    start = get_real_time();
    rsse  = inrange(data, N, min, max);
    tsse  = get_real_time()-start;

    printf("- result: %d [correct: %d]\n", rsse, rseq);
    printf("- sequential version: %.2f msec\n", tseq*1000);
    printf("- SSE version: %.2f msec\n", tsse*1000);
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char** argv) {

    int i;
    short *data = malloc(N*sizeof(short));
    assert(data != NULL);

    printf("Input array of size %lu MB\n", N*sizeof(short)/(1024*1024));

    // init data
    srand(SEED);
    data[0] = MIN;
    for (i=1; i<N-1; ++i) data[i] = MIN + rand() % (MAX-MIN);
    data[N-1] = MAX;

    do_test(data, N, MIN,    MAX,    1);
    do_test(data, N, MIN,    MAX-1,  2);
    do_test(data, N, MIN+1,  MAX,    3);
    do_test(data, N, MIN-10, MAX+10, 4);

    free(data);
    
    return 0;
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
