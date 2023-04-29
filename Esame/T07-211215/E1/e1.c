#include "e1.h"
#include <immintrin.h>


// ---------------------------------------------------------------------
// matmul
// ---------------------------------------------------------------------
// SSE version

static void add_prod(const short* src, short* dst, short x, int n) {
    int j;
    __m128i vsrc;
    __m128i vdst;
    __m128i xv = _mm_set1_epi16(x);
    for (j=0; j + 7 <n; j+=8) {
		vsrc = _mm_loadu_si128((const __m128i*)(src+j));
		vdst = _mm_loadu_si128((const __m128i*)(dst+j));
		vsrc = _mm_mullo_epi16(vsrc,xv);
		vdst = _mm_add_epi16(vsrc,vdst);
		_mm_store_si128((__m128i*)(dst+j),vdst);
	}
    for(; j < n; j++) dst[j] += x * src[j];
}

void matmul(const short** a, const short** b, short** c, int n) {
    int i, j, k;
    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j) c[i][j] = 0;
    for (i=0; i<n; ++i)
        for (k=0; k<n; ++k)
            add_prod(b[k], c[i], a[i][k], n);
}


// ---------------------------------------------------------------------
// matmul_seq
// ---------------------------------------------------------------------
// sequential version

static void add_prod_seq(const short* src, short* dst, short x, int n) {
    int j;
    for (j=0; j<n; ++j) dst[j] += x * src[j];
}

void matmul_seq(const short** a, const short** b, short** c, int n) {
    int i, j, k;
    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j) c[i][j] = 0;
    for (i=0; i<n; ++i)
        for (k=0; k<n; ++k) 
            add_prod_seq(b[k], c[i], a[i][k], n);
}
