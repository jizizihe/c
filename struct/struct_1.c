#include<stdio.h>

struct study_s {
	int num;
	char name[10];
} name[] = {//结构体数组
	{1, "zhangsan"},
	{2, "lisi"},
};

struct study_s name2 = {//定义struct study_s类型的变量name2。
	.num = 3,
	.name = "wangwu",	
}; 

struct {
	int age;
	char score;
} name3 = {//name123都是结构体变量，并进行初始化,需要分配存储空间，如果没有，只是一个结构体轮廓。
	.age = 18,
	.score = 100,
};

void jump()
{
	int i;

	for(i = 0; i < 2; i++) {
		printf("szbaijie---------------%d %s\n", name[i].num, name[i].name);	
	}
}

void jump_2()
{
	printf("szbaijie---------------%d %s\n", name2.num, name2.name);	
}

void jump_3()
{
	printf("age:= %d score:= %d\n", name3.age, name3.score);
}

int main() 
{
	jump();
	jump_2();
	jump_3();

	return 0;
}


