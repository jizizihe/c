#include <stdio.h>

int main ()
{
	int x =1, y = 2, z[10]={0};
	/* 指针只能指向特定类型的对象，例外：void类型的指针可以存放任何类型的指针，但它不能访问自身*/
	int *p; /* ip is a pointer to int */

	p = &x; /* ip now points to x */
	printf("&x:= %p p:= %p\n", &x, p);	
	y = *p; /* y is now 1 */
	printf("y:= %d\n", y);	
	*p = 0; /* x is now 0 */
	printf("x:= %d\n", x);	
	p = &z[0]; /* ip now points to z[0] */
	printf("&z[0]:= %p p:= %p *p:=%d\n", &z[0], p, *p);	

	y = *p +1;
	printf("y:= %d\n", y);	
	++*p; 
	printf("*p:= %d\n", *p);	
	(*p)++;//(*p)++括号是必需的，否则，将对p进行加1运算，而不是对p指向的对象进行加1运算。类似于*与++这样的一元描述符遵循从右到左的顺序
	printf("*p:= %d\n", *p);	

	return 0;
}
