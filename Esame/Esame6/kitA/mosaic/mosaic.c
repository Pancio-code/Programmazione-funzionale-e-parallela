// =====================================================================
//  mosaic.c
// =====================================================================

//  Author:         (c) 2017 ...
//  License:        See the end of this file for license information
//  Created:        Feb 14, 2017

//  Last changed:   $Date: 2017/02/14 --:--:-- $
//  Changed by:     $Author: ... $
//  Revision:       $Revision: 1.00 $


#include "mosaic.h"
#include "rand_perm.h"
#include <stdlib.h>

#define LOCAL_SIZE  8
#define KERNEL_NAME "mosaic"

// ---------------------------------------------------------------------
// mosaic
// ---------------------------------------------------------------------
// data-parallel GPU version

void mosaic(unsigned char* in, int w, int h, 
            unsigned char** out, int* ow, int* oh,
            unsigned tile_size, clut_device* dev, double* td) {


    int       err;      // error code
    cl_kernel kernel;   // execution kernel
    cl_mem    din;      // input matrix on device
    cl_mem    dout;     // output matrix on device
    cl_event  evt;      // performance measurement event
    cl_mem    dperm;
    
    
    *ow = w - w % tile_size;
    *oh = h - h % tile_size;
    
        unsigned bw = *ow / tile_size; // number of horizontal tiles
    unsigned bh = *oh / tile_size; // number of vertical tiles

    unsigned* perm = rand_perm(bw*bh);
        // allocate output matrix
    *out = malloc((*ow)*(*oh)*sizeof(unsigned char));
    if (*out == NULL) clut_panic("failed to allocate input matrix on device memory");

    // create the compute kernel
    kernel = clCreateKernel(dev->program, KERNEL_NAME, &err);
    clut_check_err(err, "failed to create kernel");

    // allocate input matrix on device as a copy of input matrix on host
    din = clCreateBuffer(dev->context, 
                         CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, 
                         h*w*sizeof(unsigned char), in, NULL);
    if (!din) clut_panic("failed to allocate input matrix on device memory");

    // allocate permutation array on device as a copy of permutation array on host
    dperm = clCreateBuffer(dev->context, 
                         CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, 
                         bw*bh*sizeof(unsigned int), perm, NULL);
    if (!dperm) clut_panic("failed to allocate input matrix on device memory");
    
    // no longer in use
    free(perm);

    // allocate output matrix on device
    dout = clCreateBuffer(dev->context, 
                          CL_MEM_WRITE_ONLY, 
                          (*oh)*(*ow)*sizeof(unsigned char), NULL, NULL);
    if (!dout) clut_panic("failed to allocate output matrix on device memory");


    // set the arguments to our compute kernel
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &din);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &dout);
    err |= clSetKernelArg(kernel, 2, sizeof(int), &h);
    err |= clSetKernelArg(kernel, 3, sizeof(int), &w);
    err |= clSetKernelArg(kernel, 4, sizeof(int), oh);
    err |= clSetKernelArg(kernel, 5, sizeof(int), ow);
    err |= clSetKernelArg(kernel, 6, sizeof(int), &tile_size);
    err |= clSetKernelArg(kernel, 7, sizeof(cl_mem), &dperm);
    clut_check_err(err, "failed to set kernel arguments");

    // execute the kernel over the range of our 2D input data set
    size_t local_dim[]  = { LOCAL_SIZE, LOCAL_SIZE };
    size_t global_dim[] = { *ow, *oh };
    global_dim[0] = ((global_dim[0]+LOCAL_SIZE-1)/LOCAL_SIZE)*LOCAL_SIZE; // round up
    global_dim[1] = ((global_dim[1]+LOCAL_SIZE-1)/LOCAL_SIZE)*LOCAL_SIZE; // round up

    err = clEnqueueNDRangeKernel(dev->queue, kernel, 2, 
                                 NULL, global_dim, local_dim, 0, NULL, &evt);
    clut_check_err(err, "failed to execute kernel");

    // copy result from device to host
    err = clEnqueueReadBuffer(dev->queue, dout, CL_TRUE, 0, 
                              (*ow)*(*oh)*sizeof(unsigned char), *out, 0, NULL, NULL);
    clut_check_err(err, "failed to read output result");

    // return kernel execution time
    *td = clut_get_duration(evt);

    // cleanup
    clReleaseMemObject(din);
    clReleaseMemObject(dout);
   clReleaseMemObject(dperm);
    clReleaseKernel(kernel);
}


// Copyright (C) 2017 ...

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
