#include "sum.h"
#include <immintrin.h>

#if 1
#define STEP    4
#define VEC     __m128i
#define LOAD    _mm_loadu_si128
#define ADD     _mm_add_epi32
#define STORE   _mm_storeu_si128
#else
#define STEP    8
#define VEC     __m256i
#define LOAD    _mm256_loadu_si256
#define ADD     _mm256_add_epi32
#define STORE   _mm256_storeu_si256
#endif

int sum(int* v, int n) {
    int i, s = 0;
    int c[STEP] = { 0 };
    VEC vc = LOAD((const VEC*)c);

    for (i=0; i+STEP-1 < n; i += STEP) {
        VEC vv = LOAD((const VEC*)(v+i));
        vc = ADD(vc, vv);
    }

    for (; i<n; ++i) c[0] += v[i];

    STORE((VEC*)c, vc);

    for (i=0; i<STEP; ++i) s += c[i];

    return s;
}
