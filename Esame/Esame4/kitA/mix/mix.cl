#define IDX(x,y,w) ((y)*(w)+(x))

__kernel void mymix(__global unsigned char* in1,
					 __global unsigned char* in2,
                     __global unsigned char* out, 
                    unsigned w1, unsigned w2, 
                     int w, int h) {

    int x = get_global_id(0);
    int y = get_global_id(1);

    if (x >= w || y >= h) return;

    unsigned pixel = (in1[IDX(x,y,w1)] + in2[IDX(x,y,w2)]) / 2;
    out[IDX(x,y,w)] = pixel;
}
