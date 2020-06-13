#include <stdio.h>
#include <string.h>

//用指针作为函数返回值时需要注意的一点是，函数运行结束后会销毁在它内部定义的所有局部数据，包括局部变量、局部数组和形式参数，函数返回的指针请尽量不要指向这些数据
char *strlong(char *str1, char *str2){//指针函数
	//int n = 100;return &n;//不能定义局部变量
	if(strlen(str1) >= strlen(str2)){
		return str1;
	}else{
		return str2;
	}
}

int main(){
	char str1[30], str2[30], *str;
	gets(str1);
	gets(str2);
	str = strlong(str1, str2);
	printf("Longer string:= %s\n", str);

	return 0;
}
