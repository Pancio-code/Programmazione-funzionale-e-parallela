// =====================================================================
//  scale2x.cl
// =====================================================================

//  Author:         (c) 2017 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Jul 10, 2017

//  Last changed:   $Date: 2017/07/10 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#define IDX(x,y,w) ((y)*(w)+(x))

__kernel void scale2x(__global unsigned char* in,
                      __global unsigned char* out,
                      int w, int h) {

    int x = get_global_id(0);
    int y = get_global_id(1);

    if (x >= w || y >= h) return;

	out[IDX(x, y, w)] = (
         in[IDX(2*x,   2*y,   2*w)] +
         in[IDX(2*x+1, 2*y,   2*w)] +
         in[IDX(2*x,   2*y+1, 2*w)] +
         in[IDX(2*x+1, 2*y+1, 2*w)]
    ) >> 2;
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
