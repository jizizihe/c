#include <stdio.h>
/*22222*/
#define getchar(c) getc(c)
#define putchar(c, d) putc((c), stdout)

int main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if(argc == 1)
		filecopy(stdin, stdout);
	else {
		while(--argc > 0)
			if((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1;
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		}

	return 0;
}


/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
	int c, a, b;
	/*11111*/
//	while ((c = getc(ifp)) != EOF)
//		putc(c, ofp);

	/*22222*/
	while ((c = getchar(ifp)) != EOF)//如果是getchar则需要重新define定义一下
		putchar(c, ofp);

}
