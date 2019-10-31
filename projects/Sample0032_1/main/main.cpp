// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "function.h"

#define MAXLINES 5000
char* lineptr[MAXLINES];

/*
入力行をソートする
*/
int main()
{
	int nlines;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else{
		printf("error\n");
		return 1;
	}
	return 0;
}

