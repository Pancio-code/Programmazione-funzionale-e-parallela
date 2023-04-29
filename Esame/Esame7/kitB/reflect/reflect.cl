// =====================================================================
//  reflect.cl
// =====================================================================

//  Author:         (c) 2017 -- --
//  Created:        Jan 23, 2017

//  Last changed:   $Date: 2017/01/23 --:--:-- $
//  Changed by:     $Author: -- $
//  Revision:       $Revision: 1.00 $

#define IDX(x,y,w) ((y)*(w)+(x))

__kernel void reflect(__global unsigned char* in,
                      __global unsigned char* out,
                      unsigned w,
                      unsigned l) {


    int x = get_global_id(0);
    int y = get_global_id(1);

    if (x >= l|| y >= l) return;

	if (x+y<l) out[IDX(x, y, l)] = in[IDX(x, y, w)];
	else       out[IDX(x, y, l)] = in[IDX(l-y+1, l-x+1, w)];
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
