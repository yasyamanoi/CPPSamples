
#include "calc.h"

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double d) {
	if (sp < MAXVAL) {
		val[sp++] = d;
	}
	else {
		cout << "push: �X�^�b�N�������ς��ł�" << endl;
	}
}
double pop() {
	if (sp > 0) {
		return val[--sp];
	}
	else {
		cout << "pop: �X�^�b�N����ł�" << endl;
		return 0.0;
	}
}
