#define IDX(x,y,w) ((y)*(w)+(x))

__kernel void px4(__global unsigned char* in, 
                  __global unsigned char* out, 
                  int h, int w) {

    int x = get_global_id(0)*2;
    int y = get_global_id(1)*2;

    if (x >= w || y >= h) return;

    unsigned char pixel = in[IDX(x,y,w)];
    out[IDX(x,y,w)]     = pixel;
    out[IDX(x+1,y,w)]   = pixel;
    out[IDX(x,y+1,w)]   = pixel;
    out[IDX(x+1,y+1,w)] = pixel;
}
