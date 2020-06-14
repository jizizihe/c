#include <stdio.h>
#include <string.h>

/* 定义简单的结构 */
struct
{
	unsigned int widthValidated;
	unsigned int heightValidated;
} status1;

/* 定义位域结构 */
struct
{
	/* status 变量将占用 4 个字节的内存空间，但是只有 2 位被用来存储值。
	 * 如果您用了 32 个变量，每一个变量宽度为 1 位，那么 status 结构将使用 4 个字节，
	 * 但只要您再多用一个变量，如果使用了 33 个变量，那么它将分配内存的下一段来存储第 33 个变量，
	 * 这个时候就开始使用 8 个字节 */
	unsigned int widthValidated : 1;//占一位,
	unsigned int heightValidated : 1;
} status2;

struct
{
	unsigned int age : 3;//占三位
} Age;

int main( )
{
	printf( "Memory size occupied by status1 : %d\n", sizeof(status1));
	printf( "Memory size occupied by status2 : %d\n", sizeof(status2));

	Age.age = 4;
	printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
	printf( "Age.age : %d\n", Age.age );

	Age.age = 7;
	printf( "Age.age : %d\n", Age.age );

	Age.age = 8; // 二进制表示为 1000 有四位，超出规定的位数，返回0;
	printf( "Age.age : %d\n", Age.age );

	return 0;
}

