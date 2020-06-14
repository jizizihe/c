#include<stdio.h>
#include<string.h>

struct Test
{
	int age;
	char name[16];
	double score;
}std1;

struct Test struct_fun(int age,char *name,double score){//结构体函数
	struct Test Student;

	Student.age=age;
	//Student->name=name; 错误，字符串不能直接赋值,可以初始化
	strcpy(Student.name,name);
	Student.score=score;

	return Student;
}
void output_fun1(int age,char *name,double score){
	std1.age=age;
	strcpy(std1.name,name);
	std1.score=score;
	printf("output_fun1 :\n");
	printf("age:= %d, name:= %s, score:= %.2f\n",std1.age,std1.name,std1.score);
}
//结构体函数输出
void output_fun2(struct Test stu){
	printf("output_fun2 :\n");
	printf("age:= %d, name:= %s, score:= %.2f\n",stu.age,stu.name,stu.score);
}

void main(){
	output_fun1(15,"xiaoming",89);

	struct Test p=struct_fun(17,"xiaohong",80);
	output_fun2(p);
}
