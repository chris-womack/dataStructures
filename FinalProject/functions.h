#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "functions.cpp"
#include <iostream>
#include <string>

using namespace std;

void seed();
unsigned int concatenate(unsigned int x, unsigned int y);
int deathCheck(Node* node, int* opCounter);
void quickSort(arrayStruct arr[], int head, int tail);

#endif // FUNCTIONS_H_INCLUDED
