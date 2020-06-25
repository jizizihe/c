#include <stdio.h>
#include <ctype.h>
int main() /* lower: convert input to lower case*/
{
	int c;//EOF是-1，所以需要将c定义为int形
	
	while ((c = getchar()) != EOF)//getchar与putchar,只能输出单个字符，没有自动换行，需要按回车键，在stdio.h中定义
		putchar(tolower(c));//tolower把大写字母转换成小写字母并将其他字符原样返回，在ctype.h中定义,toupper为转换为大写。
	
	return 0;
}
