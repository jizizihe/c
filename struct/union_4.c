#include <stdio.h>
#include <string.h>

union Data//共用同一内存区域,与结构体各成员占用不同内存不同。其类型定义和结构体一样。
{
	int i;
	float f;
	char  str[20];
	short t;
	char c;
};

int main( )
{
	union Data data;        

	//测试内存区域
	printf("%d, %d\n", sizeof(data), sizeof(union Data) );//数据空间由占用内存最大的成员决定
	data.i = 10;
    data.f = 220.5;
    strcpy( data.str, "C Programming");
	printf( "data.str:=%s  data.i:=%d  data.f:=%f\n", data.str, data.i, data.f);//运行时i,f数据被破坏，所以只保留最后赋值的，说明共同同一内存区域。
	//同一时间只用一个变量，便能正确打印。这也是共用体的主要目的。
	strcpy( data.str, "C Programming");
	printf( "data.str:= %s\n", data.str);
	data.i = 10;
	printf( "data.i:= %d\n", data.i);
	data.f = 220.5;
	printf( "data.str:=%s  data.i:=%d  data.f:=%f\n", data.str, data.i, data.f);
	data.t = 0x1111;
	printf( "data.str:=%s  data.i:=%d  data.f:=%f  data.t:= %x\n", data.str, data.i, data.f, data.t);
	//内存分布情况
	data.i = 0x22222222;
	printf( "data.t:=%x  data.i:=%x data.c:=%x\n", data.t, data.i, data.c);
	data.t = 0x1111;
	printf( "data.t:=%x  data.i:=%x data.c:=%x\n", data.t, data.i, data.c);
	data.c = '9';//'9'在ascii码表中十六进制是39。
	printf( "data.t:=%x  data.i:=%x data.c:=%c\n", data.t, data.i, data.c);//从大到小，可以看到内存不断被后面的值覆盖，相互影响

	return 0;
}
