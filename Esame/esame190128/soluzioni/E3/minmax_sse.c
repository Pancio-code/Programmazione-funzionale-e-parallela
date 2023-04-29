#include "minmax.h"
#include <immintrin.h>

void minmax_sse(const unsigned char* v, int n, unsigned char* pmin, unsigned char* pmax){

    int i;
    unsigned char min[16];
    unsigned char max[16];
    __m128i vmin = _mm_set1_epi8(0xFF);
    __m128i vmax = _mm_set1_epi8(0x00);
    *pmin = 0xFF;
    *pmax = 0x00;

    for (i=0; i + 15 < n; i += 16) {
        __m128i vv = _mm_loadu_si128((const __m128i*)(v+i));
        vmin = _mm_min_epu8(vmin, vv);
        vmax = _mm_max_epu8(vmax, vv);
    }

    for (; i<n; ++i) {
        if (v[i] < *pmin) *pmin = v[i];
        if (v[i] > *pmax) *pmax = v[i];
    }

    _mm_storeu_si128((__m128i*)min, vmin);
    _mm_storeu_si128((__m128i*)max, vmax);

    for (i=0; i<16; ++i) {
        if (min[i] < *pmin) *pmin = min[i];        
        if (max[i] > *pmax) *pmax = max[i];
    }
}
