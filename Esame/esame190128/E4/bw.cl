#define IDX(x,y,w) ((y)*(w)+(x))

__kernel void bw(__global unsigned char* in, 
                     __global unsigned char* out, 
                     int h, int w,unsigned char threshold) {

    int x = get_global_id(0);
    int y = get_global_id(1);

    if (x >= w || y >= h) return;

    unsigned char pixel = in[IDX(x,y,w)];
    if(pixel >= threshold) pixel = 255;
    else pixel = 0;
    out[IDX(x,y,w)] = pixel;
}
