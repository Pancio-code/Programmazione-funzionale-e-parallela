// =====================================================================
//  inrange.c
// =====================================================================

//  Author:         (c) 2018 ---
//  License:        See the end of this file for license information
//  Created:        Jan 30, 2018

//  Last changed:   $Date: 2018/01/30 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include "inrange.h"
#include <immintrin.h>

// ---------------------------------------------------------------------
// inrange
// ---------------------------------------------------------------------
// SSE version

int inrange(const short* min, unsigned minn,
            const short* v,   unsigned n,
            const short* max, unsigned maxn) {

    int i;
    if(minn < n) n = minn;
    if(maxn < n) n = maxn;

    __m128i vmin;
    __m128i vmax;
    __m128i vv;
    __m128i gt;
    __m128i eq;
    __m128i resv;
    
    for (i=0; i+7 < n; i += 8) {
        vmin = _mm_loadu_si128((__m128i*)(min+i));
        vmax = _mm_loadu_si128((__m128i*)(max+i));
        vv = _mm_loadu_si128((__m128i*)(v+i));
        gt = _mm_cmpgt_epi16(vv,vmin);
        eq = _mm_cmpeq_epi16(vmin,vv);
        resv = _mm_add_epi16(gt,eq);
        if(_mm_test_all_ones(resv) != 1) return 0;
        
        gt = _mm_cmpgt_epi16(vmax,vv);
        eq = _mm_cmpeq_epi16(vmax,vv);
        resv = _mm_add_epi16(gt,eq);
        if(_mm_test_all_ones(resv) != 1) return 0;
    }
    
    for (; i<n; i++) {
		if (v[i]<min[i] || v[i]>max[i]) return 0;
	}

    return 1;
}


// Copyright (C) 2018 ---

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
