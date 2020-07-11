#include <stdio.h>

/* 函数声明 */
void func1(void);

static int count=10;        /* 全局变量 - static 是默认的 */

int main()
{
	while (count--) {
		func1();
	}
	return 0;
}

void func1(void)
{
	/* 'thingy' 是 'func1' 的局部变量 - 只初始化一次
	 * 每次调用函数 'func1' 'thingy' 值不会被重置。
	 * 所以，在局部变量内用static来定义变量，其实就是定义全局变量。
	 */                
	static int thingy=5;
	thingy++;
	printf(" thingy 为 %d ， count 为 %d\n", thingy, count);
}

