
#include "calc.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch() {
	return (bufp > 0) ? buf[--bufp] : cin.get();
}
void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		cout << "ungetch: これ以上追加できません" << endl;
	}
	else {
		buf[bufp++] = c;
	}
}
