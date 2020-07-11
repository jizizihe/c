#include <stdio.h>
#include <string.h>

int str_comp(const char *m,const char *n);//声明一个函数 str_comp，该函数有两个 const char 类型的指针，函数的返回值为 int 类型
void comp(char *a,char *b,int (*str)(const char *,const char*));//声明一个函数 comp ,注意该函数的第三个参数，是一个函数指针

int main()
{
	char str1[20];//声明一个字符数组
	char str2[20];
	
	printf("please input str1:= ");
	gets(str1);//从键盘上输入字符，直至接受到换行符或EOF时停止，并将读取的结果存放在buffer指针所指向的字符数组中。
	printf("please input str2:= ");
	gets(str2);
	comp(str1, str2, str_comp);//函数指针 p 作为参数传给 comp 函数
	
	//int (*p)(const char *,const char *) = str_comp;//声明并初始化一个函数指针，该指针所指向的函数有两个 const char 类型的指针，且返回值为 int 类型
	//comp(str1, str2, p);//函数指针 p 作为参数传给 comp 函数

	return 0;
}

int str_comp(const char *m,const char *n)
{
	if(strcmp(m,n) == 0)//库函数 strcmp 用于比较两个字符串: m=n 返回0，m>n 返回正数，m<n 返回负数
		return 0;
	else
		return 1;
}

//回调函数
void comp(char *a,char *b,int (*pstr)(const char *,const char*))
{
	if((*pstr)(a,b) == 0)
		printf("str1 = str2\n");
	else
		printf("str1 != str2\n");
}
