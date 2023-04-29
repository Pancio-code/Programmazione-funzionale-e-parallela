#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sumeven.h"

#define N 1000
#define M 1000000

double get_real_time() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec*1E-06;
}

int main(int argc, char* argv[]) {

    int i, n = N, m = M;
    int res, res_sse, *v;
    double start, tseq, tsse;

    if (argc >= 3) {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }

    // allocate test array
    v = malloc(n*sizeof(int));
    assert(v != NULL);

    // init test data
    for (i=0; i<n; ++i) v[i] = 128 + (i%-3 + 1)*(i % 35);

    // cache warmup
    res = sumeven(v, n);
    res_sse = sumeven_sse(v, n);

    // sequential code
    start = get_real_time();
    for (i=0; i<m; ++i)
        res = (res << 1) ^ sumeven(v, n);
    tseq = get_real_time() - start;

    // parallel code
    start = get_real_time();
    for (i=0; i<m; ++i)
        res_sse = (res_sse << 1) ^ sumeven_sse(v, n);
    tsse = get_real_time() - start;

    printf("Tempo seq: %f sec\n", tseq);
    printf("Tempo sse: %f sec\n", tsse);
    printf("Speedup: %2.1fx\n", tseq/tsse);
    printf("Res %-3d [corretto: %-3d] - %s\n", res_sse, res, res_sse==res ? "OK" : "KO");

    free(v);

    return 0;
}
