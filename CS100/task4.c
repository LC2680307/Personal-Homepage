#include <stdio.h>
#include <stdlib.h>

void FindSecondMaxAndMin(int* secondMax, int* secondMin)
{
    int i,a[10000],t,j,N;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        {
        scanf("%d",&a[i]);
        }
    for(j=1;j<N;j++)
        {
            for(i=0;i<j;i++)
            {
                if(a[i]>a[j])
                {
                    t=a[i];a[i]=a[j];a[j]=t;
                }
            }
        }
    *secondMax = a[N-2];
    *secondMin = a[1];
    return;
}

int main()
{
    int secondMax, secondMin;
    FindSecondMaxAndMin(&secondMax, &secondMin);
    printf ("%d %d\n", secondMax, secondMin);
    return 0;
}