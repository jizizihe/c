#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct study_s {
	int num;
	int *num_2;
	char name[10];
};

int main ()
{
	struct study_s *ip=NULL;        /* 指针变量的声明 */
	int var = 100;

	ip = (struct study_s *)malloc(sizeof(struct study_s));	
	ip->num = 2;
	ip->num_2 = &var;
	printf("-----------------------------:\n");
	printf("Address stored in ip variable: %d\n", ip->num);
	printf("Address stored in ip variable: %p\n", &ip->num );
	printf("Address stored in ip variable: %p\n", &ip);
	printf("Address stored in ip variable: %p\n", ip);
	/* get point * value */
	printf("-----------------------------:\n");
	printf("Address stored in ip variable: %p\n", ip->num_2);
	printf("Address stored in ip variable: %p\n", &var);
	printf("Address stored in ip variable: %p\n", &ip->num_2 );
	printf("Address stored in ip variable: %d\n", *ip->num_2 );
	printf("-----------------------------:\n");
	printf("Address stored in ip variable: %p\n", &ip);
	printf("Address stored in ip variable: %p\n", ip);

	return 0;
}
