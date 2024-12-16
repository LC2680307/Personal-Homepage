#include <stdio.h>

int ColorMap(float minVal, float maxVal, int maxValColor, float val)
{
    int R,G,B;
    int result;
    int lx,mx,hx;
    lx=maxValColor&0xFF;
    mx=maxValColor>>8&0xFF;
    hx=maxValColor>>16&0xFF;
    R = (val-minVal)/(maxVal-minVal)*lx;
    G = (val-minVal)/(maxVal-minVal)*mx;
    B = (val-minVal)/(maxVal-minVal)*hx;
    result = R+G*16*16+B*16*16*16*16;
    return result;
}

int main()
{
    float minVal, maxVal, val;
    int maxValColor;
    scanf("%f %f %x %f", &minVal, &maxVal, &maxValColor, &val);
    int color = ColorMap(minVal, maxVal, maxValColor, val);
    printf ("0x%x\n", color);
    return 0;
}

