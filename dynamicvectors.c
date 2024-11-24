#include "dynamicvectors.h"  // Inkludiere die Header-Datei, um die Funktionsprototypen zu nutzen
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double* mallocVector(int n) {
    int j = 0;
    double* vector = NULL;
    assert(n > 0);

    vector = malloc(n * sizeof(double));  // Speicher für n Elemente reservieren
    assert(vector != NULL);  // Sicherstellen, dass malloc erfolgreich war

    for (j = 0; j < n; ++j) {
        vector[j] = 0;  // Initialisiere jedes Element auf 0
    }

    return vector;
}

double* freeVector(double* vector) {
    free(vector);  // Speicher freigeben
    return NULL;   // Zeiger auf NULL setzen, um auf ungültigen Speicher zu zeigen
}

double* reallocVector(double* vector, int n, int nnew) {
    int j = 0;
    assert(vector != NULL);
    assert(n > 0);
    assert(nnew > 0);

    vector = realloc(vector, nnew * sizeof(double));  // Speicher auf neue Größe anpassen
    assert(vector != NULL);  // Sicherstellen, dass realloc erfolgreich war

    for (j = n; j < nnew; ++j) {
        vector[j] = 0;  // Neue Elemente initialisieren (optional)
    }

    return vector;
}

double* scanVector(int n) {
    int j = 0;
    double* vector = NULL;
    assert(n > 0);

    vector = mallocVector(n);  // Allokiert Speicher für den Vektor
    assert(vector != NULL);

    for (j = 0; j < n; ++j) {
        printf("vector[%d] = ", j);
        scanf("%lf", &vector[j]);  // Werte vom Benutzer einlesen
    }

    return vector;
}

void printVector(double* vector, int n) {
    int j = 0;
    assert(vector != NULL);  // Sicherstellen, dass der Vektor gültig ist
    assert(n > 0);

    for (j = 0; j < n; ++j) {
        printf("%d: %f\n", j, vector[j]);  // Index und Wert ausgeben
    }
}

double* matrixVectorProduct(double* matrix, int mMat, int nMat, double* vector, int nVec) {
    // Überprüfen, ob die Dimensionen übereinstimmen
    assert(nMat == nVec);

    // Dynamischen Speicher für das Ergebnisvektor reservieren
    double* result = malloc(mMat * sizeof(double));
    assert(result != NULL);

    for (int j = 0; j < mMat; ++j) {
        result[j] = 0;
        for (int k = 0; k < nMat; ++k) {
            result[j] += matrix[j * nMat + k] * vector[k];
        }
    }

    return result;
}

double matrixNorm(double* matrix, int m, int n) {
    double sum = 0;

    for (int j = 0; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
            sum += matrix[j * n + k] * matrix[j * n + k];
        }
    }

    return sqrt(sum);
}

