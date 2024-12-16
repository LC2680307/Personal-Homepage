#include <stdio.h>
#include<stdlib.h>

void DrawSquare(int size)
{
    int hollow,i;
    for(i=0;i!=size;i++) //第一行
    {
        putchar('*');
    }
    putchar('\n');
    hollow = size - 2; //空心部分
    for(i=0;i!=hollow;i++)
    {
        int j;
        putchar('*');
        for(j=0;j!=hollow;j++)
        {
            putchar(' ');
        }
        printf("*\n"); //竖直部分
    }
    for(i=0;i!=size;i++)
    {
    putchar('*'); //最后一行
    }
    putchar('\n');
    return;
}

void DrawDiamond(int size)
{    
int i,j;
    for(i = 0;i < size; ++i) { //上半部分
        for(j = 0;j <= size - i - 2; ++j) printf(" "); //每行前导空格
        printf("*"); //上半左侧
        for(j = 0; j < 2 * i - 1; ++j) printf(" "); //内部空格
        if(i) printf("*"); //上半右侧
        printf("\n");
    }
    for(i = size - 2;i >= 0; --i) { //下半部分
        for(j = 0;j <= size - i - 2; ++j) printf(" "); //每行前导空格
        printf("*"); //上半左侧
        for(j = 0; j < 2 * i - 1; ++j) printf(" "); //内部空格
        if(i) printf("*"); //上半右侧
        printf("\n");
    }
    return;
}


void DrawHexagon(int size)
{
	for (int i = 0;i < size;i++) 
    {
		if (i == 0) {
            for (int j = 0;j <size-1;j++) {
			printf(" "); //第一行前导空格
		    }
		}
		printf("*"); //第一行
	}
	printf("\n");
	for (int i = 1;i < size;i++)
    {
		for (int j = 0;j <=size-i-2;j++) {
			printf(" "); //上半部分前导空格
		}
		printf("*"); //上半部分左侧
		for (int k = 0;k < size+2*i-2;k++) {
			printf(" "); //内部空格
		}
		printf("*"); //上半部分右侧
		printf("\n");
	}
	for (int i = size-2;i >0;i--) 
    {
		for (int j = 0;j <= size - i - 2;j++) {
			printf(" "); //下半部分前导空格
		}
		printf("*"); //下半部分左侧
		for (int k = 0;k < size + 2 * i - 2;k++) {
			printf(" "); //内部空格
		}
		printf("*"); //下半部分右侧
		printf("\n");
	}
	for (int i = 0;i < size;i++) 
    {
		if (i == 0) {
			for (int j = 0;j < size-1;j++) {
				printf(" "); //最后一行前导空格
			}
		}
		printf("*"); //最后一行
	}
    return;
}


int main()
{
    int shape, size;
    scanf("%d %d", &shape, &size);
    
    // 1 for square, 2 for diamond, 3 for hexagon.
    switch(shape){
    case 1:
        DrawSquare(size);
        break;
    case 2:
        DrawDiamond(size);
        break;
    case 3:
        DrawHexagon(size);
        break;
    default:
        return -1;
    }
    return 0;
}