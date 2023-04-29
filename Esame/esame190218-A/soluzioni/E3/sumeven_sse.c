#include "sumeven.h"
#include <immintrin.h>

int sumeven_sse(const int* v, int n) {
    int i, s = 0, buf[4];
    __m128i vs = _mm_setzero_si128();
    for (i=0; i<n; i+=4) {
        __m128i vv = _mm_loadu_si128((const __m128i*)(v+i));
        vs = _mm_add_epi32(vs, vv);
    }
    _mm_storeu_si128((__m128i*)buf, vs);
    for (; i<n; i+=2) s += v[i];
    return s + buf[0] + buf[2];
}
