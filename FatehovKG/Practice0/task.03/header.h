#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

int* array_create(int n);
void array_out(int* arr, int n);
int unique(int* arr, int n);
int* new_arr(int* arr, int n, int uniq);