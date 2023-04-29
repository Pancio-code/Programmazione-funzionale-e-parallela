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
    int i;
    __m128i datav;
    __m128i resv;
    __m128i resv1;
    __m128i minv = _mm_set_epi16(min,min,min,min,min,min,min,min);
    __m128i maxv = _mm_set_epi16(max,max,max,max,max,max,max,max);
    for (i=0; i + 7 <n; i+=8) {
		datav = _mm_loadu_si128((__m128i*)(data+i));
		resv = _mm_cmpgt_epi16(datav,minv);
		resv1 = _mm_cmpeq_epi16(datav,minv);
		resv = _mm_add_epi16(resv,resv1);
		if(!_mm_test_all_ones(resv)) return 0;
		resv = _mm_cmplt_epi16(datav,maxv);
		resv1 = _mm_cmpeq_epi16(datav,maxv);
		resv = _mm_add_epi16(resv,resv1);
		if(!_mm_test_all_ones(resv)) return 0;
	}
	for(; i < n;i++) 
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
