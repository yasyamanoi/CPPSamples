
#include "calc.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch() {
	return (bufp > 0) ? buf[--bufp] : cin.get();
}
void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		cout << "ungetch: ‚±‚êˆÈã’Ç‰Á‚Å‚«‚Ü‚¹‚ñ" << endl;
	}
	else {
		buf[bufp++] = c;
	}
}
