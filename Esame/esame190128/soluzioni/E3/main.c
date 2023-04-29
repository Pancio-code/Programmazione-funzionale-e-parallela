#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "minmax.h"

#define N 1000
#define M 1000000

double get_real_time() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec*1E-06;
}

int main(int argc, char* argv[]) {

    int i, n = N, m = M;
    unsigned char min, max, min_sse, max_sse, *v;
    double start, tseq, tsse;

    if (argc >= 3) {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }

    // allocate test array
    v = malloc(n*sizeof(unsigned char));
    assert(v != NULL);

    // init test data
    for (i=0; i<n; ++i) v[i] = 128 + (i%-3 + 1)*(i % 35);
    v[n/4] = 23;
    v[3*n/4] = 203;

    // cache warmup
    minmax(v, n, &min, &max);
    minmax_sse(v, n, &min_sse, &max_sse);

    // sequential code
    start = get_real_time();
    for (i=0; i<m; ++i)
        minmax(v, n, &min, &max);
    tseq = get_real_time() - start;

    // parallel code
    start = get_real_time();
    for (i=0; i<m; ++i) {
        min_sse = max_sse = 9;
        minmax_sse(v, n, &min_sse, &max_sse);
    }
    tsse=  get_real_time() - start;

    printf("Tempo seq: %f sec\n", tseq);
    printf("Tempo sse: %f sec\n", tsse);
    printf("Speedup: %2.1fx\n", tseq/tsse);
    printf("Min %-3d [corretto: %-3d] - %s\n", min_sse, min, min_sse==min ? "OK" : "KO");
    printf("Max %-3d [corretto: %-3d] - %s\n", max_sse, max, max_sse==max ? "OK" : "KO");

    free(v);

    return 0;
}
