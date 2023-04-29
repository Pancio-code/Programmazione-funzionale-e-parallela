// =====================================================================
//  main.c
// =====================================================================

//  Author:         (c) 2017 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Jan 22, 2016

//  Last changed:   $Date: 2017/01/22 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "blend.h"
#include "pgm.h"


#define IDX(x,y,w) ((y)*(w)+(x))


// ---------------------------------------------------------------------
// get_real_time
// ---------------------------------------------------------------------
double get_real_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec*1E-06;
}


// ---------------------------------------------------------------------
// panic
// ---------------------------------------------------------------------
void panic(char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}


// ---------------------------------------------------------------------
// blend_seq
// ---------------------------------------------------------------------
// sequential version
void blend_seq(const unsigned char* in1,
               const unsigned char* in2,
               unsigned char** out,
               unsigned w1, unsigned h1,
               unsigned w2, unsigned h2,
               unsigned* w, unsigned* h) {
    unsigned x, y;
    *w = w1 < w2 ? w1 : w2;
    *h = h1 < h2 ? h1 : h2;
    *out = malloc((*w)*(*h));
    if (*out == NULL) panic("out of memory");
    for (x = 0; x < *w; ++x)
        for (y = 0; y < *h; ++y)
            (*out)[IDX(x,y,*w)] =
                (y % 2 == 0 && x % 2 == 0) ||
                (y % 2 != 0 && x % 2 != 0) ?
                in1[IDX(x,y,w1)]:
                in2[IDX(x,y,w2)];
}


// ---------------------------------------------------------------------
// run_test
// ---------------------------------------------------------------------
// perform test

void run_test(const unsigned char* in1, const unsigned char* in2,
              unsigned w1, unsigned h1, unsigned w2, unsigned h2,
              unsigned char** out_res, unsigned* w_res, unsigned* h_res,
              char* msg) {

    double start, t, t_ok;
    unsigned char *out, *out_ok;
    unsigned w, h, w_ok, h_ok;

    // compute sequentially
    start = get_real_time();
    blend_seq(in1, in2, &out_ok, w1, h1, w2, h2, &w_ok, &h_ok);
    t_ok = get_real_time() - start;

    // compute in parallel
    start = get_real_time();
    if (blend(in1, in2, &out, w1, h1, w2, h2, &w, &h) != 0)
        panic("error in parallel blend function");
    t = get_real_time() - start;

    // validate our results
    printf("%s\n", msg);
    printf("    Sequential took %.3f msec\n",    t_ok*1E03);
    printf("    Parallel took %.3f msec\n", t*1E03);
    printf("    Correctness test: %s\n",
                    w_ok == w && h_ok == h && memcmp(out, out_ok, w_ok*h_ok)==0 ?
					"PASSED" : "FAILED");
    *out_res = out;
    *w_res = w;
    *h_res = h;

    // cleanup
	free(out_ok);
}


// ---------------------------------------------------------------------
// load_image
// ---------------------------------------------------------------------
void load_image(const char* in_path, unsigned char** in, unsigned* w, unsigned* h) {
    printf("Open image file 1: %s\n", in_path);
    int err = pgm_load(in, h, w, in_path);
    if (err) panic("failed to load input image file");
    printf("Loaded %dx%d image 1\n", *w, *h);
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char** argv) {

    char*     in_path1;          // input image pathname 1
    char*     in_path2;          // input image pathname 2
    char*     out_path;          // output image pathname

    unsigned char *in1, *in2, *out; // in/out image buffers
    unsigned  w1, h1, w2, h2, w, h; // in/out image sizes

    // args count check
    if (argc < 3) {
        printf("Usage: %s <input-file1> <input-file2> <output-file>\n", argv[0]);
        return 1;
    }

    // set parameters
    in_path1   = argv[1];
    in_path2   = argv[2];
    out_path   = argv[3];

    // load image files in pgm format
    load_image(in_path1, &in1, &w1, &h1);
    load_image(in_path2, &in2, &w2, &h2);

    // run test
    run_test(in1, in2,  w1, h1, w2, h2, &out, &w, &h, "Running test");

    // save output image
    printf("    Saving image: %s (%ux%u)\n", out_path, w, h);
    int err = pgm_save(out, h, w, out_path);
    if (err) panic("failed to save output image file");

	free(out);

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
