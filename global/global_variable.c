#include<stdio.h>
static int data = 2222;

void jump()
{
	printf("szbaijie--------------- %d\n", data);	
}

int main() 
{
	data = 1111;
	printf("szbaijie=============== %d\n", data);
	data = 3333;
	jump();

	return 0;
}


