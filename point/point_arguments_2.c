#include<stdio.h>

void swap1(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap2(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x = 1,y = 2;
	printf("x:=%d y:=%d\n",x,y);
	swap1(x,y);//c语言是以传值的方式把参数值传递给被调函数，因此被调用函数不能修改主调函数中变量的值。
	printf("swap value x:=%d y:=%d fail\n",x,y);

	swap2(&x,&y);
	printf("swap value x:=%d y:=%d succeed\n",x,y);
	return 0;
}
