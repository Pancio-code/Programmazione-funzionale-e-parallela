#include "minmax.h"

void minmax(const unsigned char* v, int n, unsigned char* pmin, unsigned char* pmax){
    int i;
    *pmax = 0x00; // minimo valore unsigned char
    *pmin = 0xFF; // massimo valore unsigned char
    for (i=0; i<n; ++i) {
        if (v[i] > *pmax) *pmax = v[i];
        if (v[i] < *pmin) *pmin = v[i];
    }
}
