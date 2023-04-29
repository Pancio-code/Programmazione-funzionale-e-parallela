#include <immintrin.h>
#include "e2.h"
#include <stdio.h>


// ---------------------------------------------------------------------
// count_occ
// ---------------------------------------------------------------------
// SSE version

int count_occ(const char* v, int n, char x) {
    int i, cnt = 0;
    unsigned char mcnt[16];
    __m128i vv;
    __m128i resv;
    __m128i xv = _mm_set1_epi8(x);
    __m128i vone = _mm_set1_epi8(1);
    __m128i mcntv = _mm_setzero_si128();
    for (i=0; i + 15 < n; i += 16) {
		if (i % 256 == 0) {
			_mm_store_si128((__m128i*)mcnt, mcntv);
			for (int j=0; j<16; j++) cnt += mcnt[j];
			mcntv = _mm_setzero_si128();		
		}
		vv = _mm_loadu_si128((const __m128i*) (v + i));
		resv = _mm_cmpeq_epi8(xv,vv);
		resv = _mm_add_epi8(resv,vone);
		mcntv = _mm_add_epi8(mcntv,resv);
	}
    for (; i<n; ++i) cnt += v[i] != x;
    
	_mm_store_si128((__m128i*)mcnt, mcntv);
	for (int j=0; j<16; j++) cnt += mcnt[j];
    return n - cnt;


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


