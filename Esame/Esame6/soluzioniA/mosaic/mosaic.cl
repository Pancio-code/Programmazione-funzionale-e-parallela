// =====================================================================
//  mosaic.cl
// =====================================================================

//  Author:         (c) 2017 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Feb 13, 2017

//  Last changed:   $Date: 2016/02/10 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $

#define IDX(x,y,w) ((y)*(w)+(x))

__kernel void mosaic(__global unsigned char* in, 
                     __global unsigned char* out, 
                     int w, int ow, int oh, 
                     int bw, int bh,
                     __global unsigned* perm,
                     unsigned tile_size) {

    int x = get_global_id(0);
    int y = get_global_id(1);
    
    if (x >= ow || y >= oh) return;
    
    unsigned bx = x / tile_size;
    unsigned by = y / tile_size;
    unsigned bi = IDX(bx, by, bw);
    unsigned bj = perm[bi];
    unsigned bxo = bj % bw;
    unsigned byo = bj / bw;
    unsigned xo = bxo*tile_size + x % tile_size;
    unsigned yo = byo*tile_size + y % tile_size;
    out[IDX(xo, yo, ow)] = in[IDX(x,y,w)];
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
