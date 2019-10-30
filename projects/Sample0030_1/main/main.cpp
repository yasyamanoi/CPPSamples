// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "function.h"

/*
文字列をtからsにコピーする（ポインタ版２）
*/
void strcpy2(char* s, const char* t) {
	while ((*s++ = *t++) != '\0')
		;
}

void printarr(char* parr) {
	while (parr != nullptr) {
		cout << *parr << endl;
	}
}

int main()
{
	char* parray[5]{};

	parray[0] = alloc(10);
	strcpy2(parray[0], "hello");

	parray[1] = alloc(10);
	strcpy2(parray[2], "world");

	return 0;
}

