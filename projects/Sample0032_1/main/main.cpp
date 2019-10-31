// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "function.h"

char* lineptr[MAXLINES];


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

