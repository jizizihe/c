#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{//typedef用来为复杂的声明定义简单的别名
	char name[10];
	int age;
	int score;  
} message;

struct message2 {
	char name2[10];
	int age2;
};

int main(){
	message mess = {"jzzh",16,100};//初始化数组，通过typedef别名后不用写struct了。
	message *p = &mess;
	struct message2 *p2;//不加struct会报错。

	printf("message name:= %s\n",p->name);
	printf("message score:= %d\n",p->score);
	/*新建一个message2数据结构的对象，为其分配message2结构所占用的内存空间。
	 * sizeof(struct message2)为该对象在内存中占用多少内存空间，让malloc函数分配同样的空间。
	 * 不主动分配内存，指针不知道指向地址,一般选用上面方式给指针赋值。*/
	p2 = (struct message2 *)malloc(sizeof(struct message2));//需要头文件：#include<stdlib.h>
	//p2->name2 = "test";//不能直接赋值，因为数组名是一个指针，指向数组首元素的地址，这样赋值就是修改地址。
	strcpy(p2->name2, "test");//需要头文件：#include<string.h> 
	p2->age2 = 18;
	printf("message2 name:= %s\n",p2->name2);
	printf("message2 age:= %d\n",p2->age2);

	return 0;
}
