// tuolaji.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern "C"

void delay(long miliseconds) {
	long t1=clock(),t2;
	while (t2<t1+miliseconds) t2=clock();
}

int main(int argc, char* argv[])
{
	int i=0;
	while (true) {
		for (int k=0;k<i;k++) printf(" ");
		printf("        _______  ○\n");
		for (k=0;k<i;k++) printf(" ");
		printf("        |     | _∣ˉˉ＼\n");
		for (k=0;k<i;k++) printf(" ");
		printf("﹡﹡﹡﹡ˉ◎ˉˉ≧≧≧≧ˉ◎\n");
		delay(200);
		system("cls");
		i++;
	}
	return 0;
}