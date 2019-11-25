#include<stdio.h>
#include<stdlib.h>

/*structure declare*/
struct str_func{
	int a;
	int b;
	int (*add)(int a, int b);
	int (*sub)(int a, int b);
	int (*compare)(int a, int b);
};

int add(int a, int b){
	return a+b;
}

int sub(int a, int b){
	return a - b;
}

int compare(int a, int b){
	if (a>b)
		return a;
	else 
		return b;
}

/*create a structure and init*/
struct str_func test = {
	.a = 5,
	.b = 7,
	.add = add,              //function pointer point to function
	.sub = sub,
	.compare = compare,
};

int main(){
	if (test.compare)
		printf("a b max = %d\n",(test.compare(test.a,test.b)));
	if (test.compare)
		printf("a add b = %d\n",(test.add(test.a,test.b)));
	if (test.compare)
		printf("a sub b = %d\n",(test.sub(test.a,test.b)));
	return 0;
}

