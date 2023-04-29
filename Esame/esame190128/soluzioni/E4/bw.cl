#define IDX(x,y,w) ((y)*(w)+(x))

__kernel void bw(__global unsigned char* in, 
                 __global unsigned char* out, 
                 int h, int w,
                 unsigned char threshold) {

    int x = get_global_id(0);
    int y = get_global_id(1);

    if (x >= w || y >= h) return;

    out[IDX(x,y,w)] = in[IDX(x,y,w)] < threshold ? 0 : 255;
}
