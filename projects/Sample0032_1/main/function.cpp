
#include "function.h"



#define ALLOCSIZE 10000
static char allocbuff[ALLOCSIZE];
static char* allocp = allocbuff;

char* alloc(int n) {
	if (allocbuff + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else {
		return nullptr;
	}
}


/*
文字列をtからsにコピーする（ポインタ版３）
*/
void strcpy2(char* s, const char* t) {
	while (*s++ = *t++)
		;
}

//sに行を入れ、長さを返す
int getline(char *s, int lim) {
	char c;
	int i = 0;
	while (--lim > 0 && (c = cin.get()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

#define MAXLEN 1000

int readlines(char* lineptr[], int maxlines) {
	int len, nlines;
	char* p, line[MAXLEN];
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL) {
			return -1;
		}
		else {
			line[len - 1] = '\0';
			strcpy2(p, line);
			lineptr[nlines++] = p;

		}
	}
	return nlines;
}
void writelines(char* lineptr[], int nlines) {
	int i;
	for (i = 0; i < nlines; i++) {
		printf("%s\n", lineptr[i]);
	}
}

int strcmp2(char* s, char* t) {
	for (; *s == *t; s++, t++) {
		if (*s == '\0') {
			return 0;
		}
	}
	return *s - *t;
}

/*
v[i]とv[j]を交換する
*/
void swap(char *v[], int i, int j) {
	char* temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
/*
v[left]...v[right]を昇順にソートする
*/
void qsort(char* v[], int left, int right) {
	if (left >= right) {
		return;
	}
	swap(v, left, (left + right) / 2);
	int last = left;
	for (int i = left + 1; i <= right; i++) {
		if (strcmp2(v[i], v[left]) < 0) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, left + 1, right);
}
