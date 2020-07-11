#include <stdio.h>
#define NUM 10
#define NUM1 20
#define NUM2 -30

int main(){
#if NUM == 10 || NUM == 20 //#if 后面跟的是“整型常量表达式”
	printf("NUM: %d\n", NUM);
#else
	printf("NUM Error\n");
#endif

#if (defined NUM1 &&  defined NUM2) // #ifdef 和 #ifndef 后面跟的只能是一个宏名，不能是其他的
	//代码A
	printf("NUM1: %d, NUM2: %d\n", NUM1, NUM2);
#else
	//代码B
	printf("Error\n");
#endif

	return 0;
}
