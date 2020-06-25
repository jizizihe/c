#include <stdio.h>
int main()
{
	char c[100];

	while(1) {	
		/*编译会报警告，gets()在获取输入时，\
		 * 如果无限输入会造成栈空间溢出，程序返回时，不能正确找到返回地址。
		 */
		//gets(c)
		//puts(c);

		/*fgets是安全的，不会输入过长的字符串导致溢出，
		 * 因为它只接受它能存的最大字符数，其余的丢掉。
		 */
		fgets(c, sizeof(c), stdin);
		fputs(c, stdout);
	}
	return 0;
}
