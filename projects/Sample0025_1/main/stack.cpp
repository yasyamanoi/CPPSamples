
#include "calc.h"

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double d) {
	if (sp < MAXVAL) {
		val[sp++] = d;
	}
	else {
		cout << "push: スタックがいっぱいです" << endl;
	}
}
double pop() {
	if (sp > 0) {
		return val[--sp];
	}
	else {
		cout << "pop: スタックが空です" << endl;
		return 0.0;
	}
}
