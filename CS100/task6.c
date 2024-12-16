#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[1000][1000];
int x[1000];
int PC;

int main()
{
    int i,j;
    scanf("%d",&PC);
    getchar();
    for(i=0;i<PC;i++)
    {
        gets(str[i]);
    }
        for(j=0;j<PC;j++)
        {
            if(str[j][0]==108)//let
            {
                int k = str[j][5]-'0';
                int len = strlen(str[j]);
                char num[1000];
                strncpy(num,str[j]+7,len);
                x[k] = atoi(num);
            }

            else if(str[j][0]==97)//add
            {
                int a = str[j][5]-'0';
                int b = str[j][8]-'0';
                int c = str[j][11]-'0';
                x[a] = x[b] + x[c];
            }

            else if(str[j][0]==116)//sub
            {
                int a = str[j][5]-'0';
                int b = str[j][8]-'0';
                int c = str[j][11]-'0';
                x[a] = x[b] - x[c];
            }

            else if(str[j][0]==109)//mul
            {
                int a = str[j][5]-'0';
                int b = str[j][8]-'0';
                int c = str[j][11]-'0';
                x[a] = x[b] * x[c];
            }

            else if(str[j][0]==100)//div
            {
                int a = str[j][5]-'0';
                int b = str[j][8]-'0';
                int c = str[j][11]-'0';
                x[a] = x[b] / x[c];
            }

            else if(str[j][0]==98)//bge
            {
                int a = str[j][5]-'0';
                int b = str[j][8]-'0';
                int linelen = strlen(str[j]);
                char line[1000];
                strncpy(line,str[j]+10,linelen);
                int line_no = atoi(line);
                if(x[a]>=x[b])
                {
                    j = line_no-2;
                    continue;
                }
                else
                {
                    continue;
                }
            }
                        
            else if(str[j][0]==112)//print
            {
                int k = str[j][7]-'0';
                printf("x%d = %d\n", k, x[k]);
            }
        }

return 0;
}