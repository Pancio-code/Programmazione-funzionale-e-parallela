#include "sumeven.h"

int sumeven(const int* v, int n) {
    int i, s = 0;
    for (i=0; i<n; i+=2) s += v[i]; 
    return s;
}
