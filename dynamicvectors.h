#ifndef INCLUDE_DYNAMICVECTORS__
#define INCLUDE_DYNAMICVECTORS__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

// Deklarationen der neuen Funktionen
double* mallocVector(int n);
double* freeVector(double* vector);
double* reallocVector(double* vector, int n, int nnew);
double* scanVector(int n);
void printVector(double* vector, int n);

double* matrixVectorProduct(double* matrix, int mMat, int nMat, double* vector, int nVec);
double matrixNorm(double* matrix, int m, int n);

#endif
