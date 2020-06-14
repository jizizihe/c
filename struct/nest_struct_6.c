#include<stdio.h>

struct Nest1{
	//struct Nest test1;//自引用结构体，内部嵌套自己的结构体，以此下去，无限嵌套，无法确定结构体长度，编译会报错。
	struct Nest1 *test1;//自引用结构体不可以嵌套自己这个类型的变量，可以嵌套指针，由于指针长度确定，编译器不会报错。
	int value1;
};

struct Nest2{
	struct Nest1 test2;//相互引用结构体，因为NEST的结构体长度能确定，所以这里可以不使用指针，编译器不会报错。
	int value2;
};

int main()
{
	struct Nest1 *p1;
	struct Nest2 *p2;

	struct Nest1 test_p1 = {p2, 11};
	p1 = &test_p1;

	struct Nest2 test_p2 = {p1, 22};
	p2 = &test_p2;

	
	printf("p1 value1:= %d\n", p1->value1);
	printf("p2 value1:=%d value2:= %d\n", p2->test2.value1, p2->value2);//赋值给p1的结构体中value1,p2结构体的value2没有被赋值

	struct Nest2 test_p3 = {p1, 22, 33};
	struct Nest2 *p3 = &test_p3;
	printf("p3 value1:=%d value2:= %d\n", p3->test2.value1, p3->value2);//p3能正确对value2进行赋值
	

	return 0;
}
