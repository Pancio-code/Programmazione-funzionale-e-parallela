// =====================================================================
//  mix.c
// =====================================================================

//  Author:         (c) 2018 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Jan 30, 2018

//  Last changed:   $Date: 2018/01/30 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include "mix.h"
#include <stdlib.h>

#define LOCAL_SIZE  32
#define KERNEL_NAME "mymix"
#define MIN(a,b) ((a) < (b) ? (a) : (b))


// ---------------------------------------------------------------------
// mix
// ---------------------------------------------------------------------
// data-parallel GPU version

void mix(unsigned char*  in1, int  w1, int  h1,
         unsigned char*  in2, int  w2, int  h2,
         unsigned char** out, int* ow, int* oh,
         clut_device* dev, double* td) {

    int       err;      // error code
    cl_kernel kernel;   // execution kernel
    cl_mem    din1;     // input first matrix on device
    cl_mem    din2;     // input second matrix on device
    cl_mem    dout;     // output matrix on device
    cl_event  evt;      // performance measurement event

    // size of the output image
    *oh = MIN(h1,h2);
    *ow = MIN(w1,w2);

    // allocate output image on host
    *out = malloc((*ow)*(*oh)*sizeof(unsigned char));
    if (*out == NULL) clut_panic("failed to allocate output matrix on host");

    // create the compute kernel
    kernel = clCreateKernel(dev->program, KERNEL_NAME, &err);
    clut_check_err(err, "failed to create kernel");

    // allocate input matrix on device as a copy of input matrix on host
    din1 = clCreateBuffer(dev->context,
                         CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
                         w1*h1*sizeof(unsigned char), in1, NULL);
    if (!din1) clut_panic("failed to allocate input matrix 1 on device memory");

    // allocate input matrix on device as a copy of input matrix on host
    din2 = clCreateBuffer(dev->context,
                         CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
                         w2*h2*sizeof(unsigned char), in2, NULL);
    if (!din2) clut_panic("failed to allocate input matrix 2 on device memory");

    // allocate output matrix on device
    dout = clCreateBuffer(dev->context,
                          CL_MEM_WRITE_ONLY,
                          (*ow)*(*oh)*sizeof(unsigned char), NULL, NULL);
    if (!dout) clut_panic("failed to allocate output matrix on device memory");

    // set the arguments to our compute kernel
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &din1);
    err  = clSetKernelArg(kernel, 1, sizeof(cl_mem), &din2);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &dout);
    err |= clSetKernelArg(kernel, 3, sizeof(int), &w1);
    err |= clSetKernelArg(kernel, 4, sizeof(int), &w2);
    err |= clSetKernelArg(kernel, 5, sizeof(int), ow);
    err |= clSetKernelArg(kernel, 6, sizeof(int), oh);
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
    clReleaseMemObject(din1);
    clReleaseMemObject(din2);
    clReleaseMemObject(dout);
    clReleaseKernel(kernel);
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
