#include <stdio.h>
#include<string.h>

//asc码对照表：48～57为0到9十个阿拉伯数字，
//65～90为26个大写英文字母
int main()
{
    char plate[100];
    int date[100];
    char week[100];
    int len =0;
    int lastdigit;
    for(int i=0;i<3;i++)
    {
        scanf("%s %d/%d %s",&plate[0],&date[0],&date[1],&week[0]);
        len=strlen(plate);
        int flag=0;
        for(int i=0;i<len;i++)//判断是否存在I或O
        {
            if(plate[i]==73||plate[i]==79)
            {flag=1;break;}
            else
            continue;
        }
        if(flag)
        {printf("This number is invalid.\n");continue;}

        if(len==6)//新能源
        {
            if(plate[0]==68||plate[0]==70||plate[5]==68||plate[5]==70)
                {   int num=0;
                    for(int i=0;i<len;i++)
                    {
                        if(48<=plate[i]&&plate[i]<=57)
                        num++;
                    }
                    if(num==5)
                    {printf("This car is allowed to drive.\n");
                    continue;}
                    else
                    {
                        printf("This number is invalid.\n");
                        continue;
                    }
                }
            else
            {printf("This number is invalid.\n");
            continue;}
        }
        else if(len==5)
        {

            if(48<=plate[0]&&plate[0]<=57&&48<=plate[1]&&plate[1]<=57&&48<=plate[2]&&plate[2]<=57&&48<=plate[3]&&plate[3]<=57&&48<=plate[4]&&plate[4]<=57)//普通纯数字
            lastdigit = plate[4]-48;

          else if(48<=plate[4]&&plate[4]<=57&&plate[0]==84||plate[0]==88&&48<=plate[1]&&plate[1]<=57&&48<=plate[2]&&plate[2]<=57&&48<=plate[3]&&plate[3]<=57)//出租车
            {
                printf("This car is allowed to drive.\n");
                continue;
            }

           else if(plate[0]!=84&&plate[0]!=88&&65<=plate[0]&&plate[0]<=90&&48<=plate[1]&&plate[1]<=57&&48<=plate[2]&&plate[2]<=57&&48<=plate[3]&&plate[3]<=57&&48<=plate[4]&&plate[4]<=57)//普通开头字母
            {
                lastdigit = plate[4]-48;
            }
         else if(65<=plate[4]&&plate[4]<=90&&48<=plate[1]&&plate[1]<=57&&48<=plate[2]&&plate[2]<=57&&48<=plate[3]&&plate[3]<=57&&48<=plate[0]&&plate[0]<=57)//普通结尾字母
            {
                lastdigit = plate[3]-48;
            }

      else if(plate[0]!=84&&plate[0]!=88&&65<=plate[0]&&plate[0]<=90&&65<=plate[1]&&plate[1]<=90&&48<=plate[2]&&plate[2]<=57&&48<=plate[3]&&plate[3]<=57&&48<=plate[4]&&plate[4]<=57)//私人定制连续字母(1,2)
            {   
         if(65<=plate[2]&&plate[2]<=90&&plate[2]==plate[3]&&plate[3]==plate[4])
                {printf("This number is invalid.\n");
                continue;}
         else
                lastdigit = plate[4]-48;
            }

         else if(65<=plate[1]&&plate[1]<=90&&65<=plate[2]&&plate[2]<=90&&48<=plate[0]&&plate[0]<=57&&48<=plate[3]&&plate[3]<=57&&48<=plate[4]&&plate[4]<=57)//私人定制连续字母(2,3)
            {   
                lastdigit = plate[4]-48;
            }
           
         else if(65<=plate[2]&&plate[2]<=90&&65<=plate[3]&&plate[3]<=90&&48<=plate[0]&&plate[0]<=57&&48<=plate[1]&&plate[1]<=57&&48<=plate[4]&&plate[4]<=57)//私人定制连续字母(3,4)
            {
                 lastdigit = plate[4]-48;
            }
            
            else if(65<=plate[3]&&plate[3]<=90&&65<=plate[4]&&plate[4]<=90&&48<=plate[0]&&plate[0]<=57&&48<=plate[1]&&plate[1]<=57&&48<=plate[2]&&plate[2]<=57)//私人定制连续字母(4,5)
            {                   
               if(plate[0]==plate[1]&&plate[1]==plate[2])
                {
                    printf("This number is invalid.\n");
                    continue;
                }
                else
                lastdigit = plate[2]-48;
                }

            else if(65<=plate[0]&&plate[0]<=90&&48<=plate[1]&&plate[1]<=57&&48<=plate[2]&&plate[2]<=57&&48<=plate[3]&&plate[3]<=57&&65<=plate[4]&&plate[4]<=90)//私人定制一头一尾字母
            {
				if(plate[1]==plate[2]&&plate[2]==plate[3])
                {
                    printf("This number is invalid.\n");
                    continue;
                }
                else{
                lastdigit = plate[3]-48;
                }
            }

             
         else if(48<=plate[0]&&plate[0]<=57&&65<=plate[1]&&plate[1]<=90&&48<=plate[2]&&plate[2]<=57&&48<=plate[3]&&plate[3]<=57&&48<=plate[4]&&plate[4]<=57)//私人定制第二位字母
            {
                if(plate[2]==plate[3]&&plate[3]==plate[4])
                {   
                    printf("This number is invalid.\n");
                    continue;
                }
             else
                 lastdigit = plate[4]-48;
            }

           else if(48<=plate[0]&&plate[0]<=57&&48<=plate[1]&&plate[1]<=57&&65<=plate[2]&&plate[2]<=90&&48<=plate[3]&&plate[3]<=57&&48<=plate[4]&&plate[4]<=57)//私人定制第三位字母
            {
                                lastdigit = plate[4]-48;
            }
			else
            {
             printf("This number is invalid.\n");
              continue;
            }
        }
       else
       {
           printf("This number is invalid.\n");
           continue;
       }

            if(week[0]== 'S')//周末
            printf("This car is allowed to drive.\n");
            else if(week[0]!='S')//工作日
            { 
                if(date[1]%2==0)//偶数天
                {
                    if(lastdigit%2==0)
                    printf("This car is allowed to drive.\n");
                    else
                    printf("This car is not allowed to drive.\n");
                }
                else if(date[1]%2!=0)//奇数天
                {
                    if(lastdigit%2==0)
                    printf("This car is not allowed to drive.\n");
                    else
                    printf("This car is allowed to drive.\n");
                }
            }
            
    }   
    return 0;
}
