#include <stdio.h>

int main(){
    int *p = NULL;
    printf("p address:= %d\n",p);//可以看到指针指向内存地址0, 内存地址0有一个特别重要的意义，它表明改指针不指向一个可访问的内存位置。

    return 0;
}
