// =====================================================================
//  inrange.c
// =====================================================================

//  Author:         (c) 2018 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Jan 30, 2018

//  Last changed:   $Date: 2018/01/30 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <immintrin.h>
#include "inrange.h"

#define CMIN(a,b) ((a)<(b) ? (a):(b))


// ---------------------------------------------------------------------
// inrange
// ---------------------------------------------------------------------
// SSE version

int inrange(const short* min, unsigned minn,
            const short* v,   unsigned n,
            const short* max, unsigned maxn) {

    int i;
    __m128i minv, vv, maxv, res, res2;

    n = CMIN(n, CMIN(minn, maxn));

    for (i=0; i+7<n; i+=8) {
        minv = _mm_loadu_si128((__m128i const*)(min+i));
        vv   = _mm_loadu_si128((__m128i const*)(v+i));
        maxv = _mm_loadu_si128((__m128i const*)(max+i));
        res  = _mm_cmpgt_epi16(vv, minv);
        res2 = _mm_cmpeq_epi16(vv, minv);
        res  = _mm_add_epi16(res, res2);
        if (!_mm_test_all_ones(res)) return 0;
        res  = _mm_cmpgt_epi16(maxv, vv);
        res2 = _mm_cmpeq_epi16(maxv, vv);
        res  = _mm_add_epi16(res, res2);
        if (!_mm_test_all_ones(res)) return 0;
    }

    for (; i<n; ++i)
        if (v[i]<min[i] || v[i]>max[i]) return 0;

    return 1;
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
