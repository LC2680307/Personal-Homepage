#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main1()
{
    int numoflecture;
    int hour1[100],minute1[100];
    int hour2[100],minute2[100];
    int ih[100],im[100];
    int jm[100],jh[100];
    float moodlevel=100.0;


    printf("How many lectures today?\n");
    scanf("%d", &numoflecture);
    hour1[numoflecture] = 22;
    minute1[numoflecture] = 0;
    for(int i=0;i<(numoflecture);i++)
    {
    scanf("%d:%d-%d:%d",&hour1[i],&minute1[i],&hour2[i],&minute2[i]);
    }
    for(int i=0;i<(numoflecture);i++)
    {
    ih[i] = hour2[i] - hour1[i];
    im[i] = minute2[i] - minute1[i];
    jh[i+1] = hour1[i+1] - hour2[i];
    jm[i+1] = minute1[i+1] - minute2[i];
    if(im[i] < 0)
    {
        im[i] = 60 + im[i];
        ih[i]--;
    }
    if(ih[i] <= 0)
    {
        moodlevel = moodlevel - 0.4*im[i];
    }
        else
        {
           moodlevel = moodlevel - 0.4*60 - 0.8*((60*(ih[i]-1))+im[i]);
        }
    if (moodlevel <= 0)
    {
        printf("Gezi Wang has been sent to hospital.\n");
        exit(0);
    }
    if(jm[i+1]<0)
    {
        jm[i+1] = 60 + jm[i+1];
        jh[i+1]--;
    }

    moodlevel = moodlevel + 0.5*jm[i+1] + 0.5*60*jh[i+1];

    if (moodlevel >= 100)
    {
        moodlevel = 100;
    }
    }

    printf("His mood level is %.1f at the end of the day.\n", moodlevel);
    return 0;
}





