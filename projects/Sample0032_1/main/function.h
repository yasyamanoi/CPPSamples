#pragma once

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
using namespace std;

#define MAXLINES 5000
int readlines(char* lineptr[],int maxlines);
void writelines(char* lineptr[], int nlines);
void qsort(char* v[], int left, int right);

