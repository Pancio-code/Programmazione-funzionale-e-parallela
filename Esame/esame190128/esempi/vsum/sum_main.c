#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sum.h"

#define N 1000
#define M 10000000

int main(int argc, char* argv[]) {
    int i, n = N, m = M, *v, s = 0;

    if (argc >= 3) {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }

    v = malloc(n*sizeof(int));
    assert(v != NULL);

    for (i=0; i<n; ++i) v[i] = i+1;

    for (i=0; i<m; ++i) s += sum(v, n)/n;

    printf("sum = %d\n", s);

    free(v);

    return 0;
}
