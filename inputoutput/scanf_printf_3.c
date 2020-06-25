#include<stdio.h>
int main()
{
	/*int a, b;
	scanf("%d %d", &a, &b);//输入间必须有空格
	printf("a=%d, b=%d\n", a, b);

	char c, d;
	//scanf("%c%c", &c, &d);//输入a b间有空格，只输出a
	scanf("%c %c", &c, &d);//输入ab或者a b，都能输出a b
	printf("c=%c d=%c\n", c, d);

	char e[10], f[10];//输入间必须有空格
	scanf("%s %s", e, f);//数组不加地址符号。
	printf("e=%s f=%s\n", e, f);
	*/

	double g, h;
	scanf("%lf %lf", &g, &h);//输入间必须有空格，并且%f是单精度，double是双精度，输出gh为0，没有接受输入数据。
	printf("g=%f h=%f\n", g, h);//printf既可以输出float与double型，根据“默认提升参数规则”，float型会被提升为double型，因此printf只能看到双精度数。

	return 0;
}
