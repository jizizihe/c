#include <stdio.h>
int main(){
	int a =100;
	int *p1 = &a;
	int **p2 = &p1;
	int ***p3 = &p2;
	
	printf("address: &a = %p, &p1 = %p, &p2 = %p, &p3 = %p\n", &a, &p1, &p2, &p3);
	printf("address: &a = %p, p1 = %p, p2 = %p, p3 = %p\n", &a, p1, p2, p3);
	printf("address: &a = %p, p1 = %p, *p2 = %p, **p3 = %p\n\n", &a, p1, *p2, **p3);
	printf("valye: a = %d, *p1 = %d, **p2 = %d, ***p3 = %d\n", a, *p1, **p2, ***p3);

	return 0;
}
