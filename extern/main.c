#include <stdio.h>

int count ;
extern void write_extern();//将定义外部变量的函数一起编译，可调用外部变量。

int main()
{
	count = 5;
	write_extern();
}

