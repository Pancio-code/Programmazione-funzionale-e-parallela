// =====================================================================
//  inrange.c
// =====================================================================

//  Author:         (c) 2017 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Feb 13, 2017

//  Last changed:   $Date: 2017/02/13 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <immintrin.h>
#include "inrange.h"


// ---------------------------------------------------------------------
// inrange
// ---------------------------------------------------------------------
// SSE version

int inrange(const short* data, unsigned n, short min, short max) {

    __m128i minv, maxv, datav, res;
    int i;

    minv = _mm_set_epi16(min-1,min-1,min-1,min-1,min-1,min-1,min-1,min-1);
    maxv = _mm_set_epi16(max+1,max+1,max+1,max+1,max+1,max+1,max+1,max+1);

    for (i=0; i+7<n; i+=8) {
        datav = _mm_loadu_si128((__m128i const*)(data+i));
        res   = _mm_cmpgt_epi16(datav, minv);
        if (!_mm_test_all_ones(res)) return 0;
        res   = _mm_cmpgt_epi16(maxv, datav);
        if (!_mm_test_all_ones(res)) return 0;
    }

    for (;i<n; ++i)
        if (data[i]<min || data[i]>max) return 0;

    return 1;
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
