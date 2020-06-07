#include <stdio.h>  
#include <stdlib.h>
struct TEST  
{  
	int x,y;  
	int (*func)(int,int); //函数指针  
};  

int func(int x,int y)  
{  
	return x+y;  
}  

void main()  
{  
	struct TEST *test = NULL;  

	test = (struct TEST *)malloc(sizeof(struct TEST));
	//test.func=&add2; //结构体函数指针赋值  
	test->func = func;
	printf("func(3,4)=%d\n",test->func(3,4));  
}  
