// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "function.h"

/*
文字列をtからsにコピーする（ポインタ版３）
*/
void strcpy2(char* s, const char* t) {
	while (*s++ = *t++)
		;
}

void printarr(char** parr) {
	while (*parr != nullptr) {
		cout << *parr << endl;
		parr++;
	}
	cout << endl;
}

int main()
{
	char* parray[6]{};

	char buff[10];

	for (int i = 0; i < 5; i++) {
		parray[i] = alloc(10);
		sprintf_s(buff, "hello%d", i);
		strcpy2(parray[i], buff);
		printarr(parray);
	}
	cout << "-------------"<< endl;

	for (int i = 4; i >= 0; i--) {
		afree(parray[i]);
		parray[i] = nullptr;
		printarr(parray);
	}

	return 0;
}

