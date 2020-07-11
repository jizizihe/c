#include<stdio.h>

enum DAY
{
	MON=1, TUE, WED, THU, FRI, SAT, SUN
};

int main()
{
	enum DAY day;
	// 遍历枚举元素
	for (day = MON; day <= SUN; day++) {
		printf("枚举元素的值：%d \n", day);
	}
	
	scanf("%d", &day);
	switch (day)
	{
		case 1://因为day是整形，枚举MON=1,这里写MON与1都是一样的。
			printf("今天是星期一\n");
			break;
		case TUE:
			printf("今天是星期二\n");
			break;
		case WED:
			printf("今天是星期三\n");
			break;
		case THU:
			printf("今天是星期四\n");
			break;
		case FRI:
			printf("今天是星期五\n");
			break;
		case SAT:
			printf("今天是星期六\n");
			break;
		case SUN:
			printf("今天是星期天\n");
			break;
		default:
			printf("error!!!\n");
	}

	return 0;
}
