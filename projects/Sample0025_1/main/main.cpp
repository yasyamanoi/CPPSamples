// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "calc.h"

#define MAXOP 100

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0) {
				push(pop() - op2);
			}
			else {
				cout << "0除算です" << endl;
			}
			break;
		case '\n':
			cout << '\t' << pop() << endl;
			break;
		default:
			cout << "コマンドが不明です" << endl;
			break;
		}
	}
	return 0;
}

