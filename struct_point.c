#include<stdio.h>

struct study_s {
	int num;
	char name[10];
} name[] = {
	{1, "zhangsan"},
	{2, "lisi"},
};

struct study_s name2 = {
	.num = 3,
	.name = "wangwu",	
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

int main() 
{
	jump();
	jump_2();

	return 0;
}


