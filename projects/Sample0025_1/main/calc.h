#pragma once

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
using namespace std;

#define NUMBER '0'
void push(double d);
double pop();
int getop(char s[]);
int getch();
void ungetch(int c);

