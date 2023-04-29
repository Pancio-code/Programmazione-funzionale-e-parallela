// =====================================================================
//  art.cl
// =====================================================================

//  Author:         (c) 2017 -- --
//  Created:        Jan 23, 2017

//  Last changed:   $Date: 2017/01/23 --:--:-- $
//  Changed by:     $Author: -- $
//  Revision:       $Revision: 1.00 $


#define IDX(x,y,w) ((y)*(w)+(x))

__kernel void art(__global unsigned char* in, 
                     __global unsigned char* out, 
                     int h, int w) {

    int x = get_global_id(0);
    int y = get_global_id(1);

    if (x >= w || y >= h) return;
    
    unsigned char c;
    
	if (x < w/2)
		if (y < h/2) c = in[IDX(x, y,   w)];
		else         c = in[IDX(x, h-y, w)];
	else
		if (y < h/2) c = in[IDX(w-x, y,   w)];
		else         c = in[IDX(w-x, h-y, w)];
	out[IDX(x, y, w)] = c;
}

