#ifndef __MINMAX__
#define __MINMAX__

void minmax(const unsigned char* v, int n, unsigned char* pmin, unsigned char* pmax);
void minmax_sse(const unsigned char* v, int n, unsigned char* pmin, unsigned char* pmax);

#endif
