// =====================================================================
//  main.h
// =====================================================================

//  Author:         (c) 2019 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Feb 17, 2019
 
//  Last changed:   $Date: 2019/02/27 15:00:07 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <stdio.h>
#include <stdlib.h>

#include "clut.h"
#include "pgm.h"
#include "px4.h"

#define IMAGE_DIR       "images/"
#define RESULT_DIR      "results/"
#define IMAGE_FILE      "colosseo"
#define IMAGE_EXT       ".pgm"
#define PROG_NAME       "px4.cl"
#define MAX_LEN         1024
#define THRESHOLD       128


// ---------------------------------------------------------------------
// equal
// ---------------------------------------------------------------------
// compare two matrices

int equal(unsigned char* a, unsigned char* b, int rows, int cols) {
    int i, j, res = 1;
    for (i=0; i<rows; i++)
        for (j=0; j<cols; j++) 
            if (a[i*rows+j] != b[i*rows+j]) {
                printf("a[i,j] - b[i*rows+j]=%d\n", 
                       a[i*rows+j]-b[i*rows+j]);
                res = 0;
            }
    return res;
}


// ---------------------------------------------------------------------
// px4_host
// ---------------------------------------------------------------------
// sequential CPU version executed on host

void px4_host(unsigned char* in, unsigned char* out, 
             int h, int w, double* t) {

    int x, y;

    // get initial time
    double start = clut_get_real_time();

    // scan pixels of input image
    for (y=0; y+1<h; y+=2)
        for (x=0; x+1<w; x+=2) {
            unsigned char pixel = in[y*w+x];
            out[y*w+x]       = pixel;
            out[(y+1)*w+x]   = pixel;
            out[y*w+x+1]     = pixel;
            out[(y+1)*w+x+1] = pixel;
        }

    // get elapsed time
    *t = clut_get_real_time() - start;
}


// ---------------------------------------------------------------------
// run_test
// ---------------------------------------------------------------------
// perform convolution transformation test on input matrix

void run_test(unsigned char* in, unsigned char* out, int h, int w,
              clut_device* dev, char* msg) {

    double t, td;

    // allocate correct output matrix on host
	unsigned char* out_ok = malloc(h*w*sizeof(unsigned char));
	if (out_ok == NULL) 
		clut_panic("failed to allocate output matrices on host");

    // compute darken on host
    px4_host(in, out_ok, h, w, &t);

    // compute darken on device
    px4(in, out, h, w, &td, dev);

    // validate our results
    printf("%s\n", msg);
    printf("    CPU took %.3f msec\n", t*1E03);
    printf("    Device took %.3f msec\n", td*1E03);
    printf("    Correctness test: %s\n", equal(out, out_ok, h, w) ? 
										 "PASSED" : "FAILED");    

    // cleanup
	free(out_ok);
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char** argv) {

    clut_device     dev;                // device structure
    unsigned char*  in;                 // input matrix on host
    unsigned char*  out;                // output matrix on host
    char*           img_file;			// image file name
    int             h, w;               // number of rows and columns
    int             err;                // misc vars
    char            in_path[MAX_LEN];   // pathname of input image file
    char            out_path[MAX_LEN];  // pathname of output image file

    // set image file name
    if (argc > 1) img_file = argv[1];
    else          img_file = IMAGE_FILE;

    // open device
    clut_open_device(&dev, PROG_NAME);

    // build pathname of input image file
    sprintf(in_path, "%s%s%s", IMAGE_DIR, img_file, IMAGE_EXT);

    // load image file in pgm format
    printf("Open image file: %s\n", in_path);
    err = pgm_load(&in, &h, &w, in_path);
    if (err) clut_panic("failed to load input image file");
    else     printf("Loaded %dx%d image\n", h, w);

    // print device info
    clut_print_device_info(&dev);

    // allocate output matrix on host
    out = malloc(h*w*sizeof(unsigned char));
    if (out == NULL) clut_panic("failed to allocate output matrix on host");

    // run test
    run_test(in, out, h, w, &dev, "Running test");

    // build pathname of output image file
    sprintf(out_path, "%s%s-px4%s", 
                RESULT_DIR, img_file, IMAGE_EXT);

    // save output image
    printf("    Saving image: %s\n", out_path);
    err = pgm_save(out, h, w, out_path);
    if (err) clut_panic("failed to save output image file");

    // cleanup
    free(in);
    free(out);
    clut_close_device(&dev);
    
    return 0;
}


// Copyright (C) 2019 Camil Demetrescu
  
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA
