#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int  main()
{    int i,a;
     int b[33];
    ~scanf("%x", &a);
           for(i=31;i>=0;i--)
                b[31-i]=(a&1<<i?1:0);
           int sign = b[0];
           int exponent = 0;
           double fraction = 0; 
           for(i=1;i<=7;i++)
                exponent += b[i]*pow(2,7-i);
           for(i=8;i<=31;i++)
                fraction += b[i]*pow(2,7-i);
           int E = 63;
           float V = pow(-1,sign)*(1+fraction)*pow(2,exponent-E);
    printf("The number converts to %f\n", V);
     return 0;
}
