#include <immintrin.h>
#include "e2.h"


// ---------------------------------------------------------------------
// count_occ
// ---------------------------------------------------------------------
// SSE version

int count_occ(const char* v, int n, char x) {
    int i, cnt = 0;
    unsigned char cntv[16];
    __m128i vv,xv,cmpv,vcnt;
    xv =_mm_set1_epi8(x);
    __m128i vone = _mm_set_epi8(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
    vcnt = _mm_setzero_si128();
    for(i=0; i + 15 < n ; i+=16) {
		vv = _mm_loadu_si128((const __m128i*)(v+i));
		cmpv = _mm_cmpeq_epi8(vv,xv);
		cmpv = _mm_add_epi8(cmpv, vone);
		vcnt = _mm_add_epi8(vcnt,cmpv);
		if (i % 255 == 0) {
			_mm_storeu_si128((__m128i*)cntv,vcnt);
			for(int j = 0; j < 16;j++) cnt += cntv[j];
			vcnt = _mm_setzero_si128();		
		}
	}
	
    for (; i<n; ++i) cnt += v[i] == x;
    
    _mm_storeu_si128((__m128i*)cntv,vcnt);
    for(int j = 0; j < 16;j++) cnt += cntv[j];
    return cnt;
}


// ---------------------------------------------------------------------
// count_occ_seq
// ---------------------------------------------------------------------
// sequential version

int count_occ_seq(const char* v, int n, char x) {
    int i, cnt = 0;
    for (i=0; i<n; ++i) cnt += v[i] == x;
    return cnt;
}
