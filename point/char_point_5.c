#include<stdio.h>

void my_strcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0');
}

int main()
{	
	char *p = "now is the time";//定义一个指针，字符串也是数组，所以这里是p为字符数组，*p='n'
	char *p2;

	char src[40] = "today is nice day";//定义一个数组
	char dest[40];
	
	printf("数组：\n");	
	my_strcpy(dest, src);//数组src始终指向同一个存储位置，数组中单个字符可以进行修改。
	//my_strcpy(p2, p); //会报错：p是一个指针，初值指向一个字符串变量，之后它可以修改指向它的地址，不能修改字符串的内容，结果是没有定义的。
	printf("dest value:= %s\n", dest);	

	printf("指针：\n");	
	printf("打印字符 *p:= %c\n", *p); //打印字符*p, 指向开头的n, 通过地址p++，来访问后面的内容。
	printf("打印字符串 p:= %s\n", p); //打印字符串p。
	printf("打印字符串 p2:= ");
	while (*p != '\0'){
		p2 = p;//修改指向的p2的地址，以达到修改值的效果。
		printf("%c", *p2);
		p++;
		p2++;
	};
	printf("\n");

	return 0;
}


