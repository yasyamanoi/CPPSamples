// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "cpstring.h"

using namespace cp;

int main()
{
	String s("hello");
	s += " world";
	s += '!';
	String s2(" cppあいうえお");
	s += s2;
	cout << s << endl;
	return 0;
}

