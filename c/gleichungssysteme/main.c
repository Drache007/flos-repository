#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SPALTEN 10

//feld[zeilen][spalten]

double getDouble (char text[]) {
  char s[100];
  double z;
  do {
    printf("%s: ", text);
    fgets(s, sizeof s, stdin);
  } while (sscanf(s, "%lf", &z) != 1);
  return z;
}

void eingabeUI (int zeilen, int spalten, int pos, double matrix[][MAX_SPALTEN]) {
  printf("Matrix:\n");
  printf("-------\n\n");
  for (int ze = 0; ze < zeilen; ze++) {
    for (int sp = 0; sp < spalten; sp++) {
      if (ze * spalten + sp < pos) {
        printf("%6.2lf", matrix[ze][sp]);
      } else if (ze * spalten + sp == pos) {
        printf("     x");
      } else {
        printf("     -");
      }
    }
    printf("\n\n");
  }
}

void getMatrix (char name[], int zeilen, int spalten, double matrix[][MAX_SPALTEN]) {
  printf("%s:\n", name);
  for (int i = 0; i < strlen(name); i++) {
    printf("-");
  }
  printf("\n");
  for (int ze = 0; ze < zeilen; ze++) {
    for (int sp = 0; sp < spalten; sp++) {
      eingabeUI(zeilen, spalten, ze * spalten + sp, matrix);
      matrix[ze][sp] = getDouble("Zahl an x");
      system("clear");
    }
  }
  printf("\n");
}

void gibMatrixAus (char name[], int zeilen, int spalten, double matrix[][MAX_SPALTEN]) {
  printf("%s:\n", name);
  for (int i = 0; i < strlen(name); i++) {
    printf("-");
  }
  printf("\n");
  for (int ze = 0; ze < zeilen; ze++) {
    for (int sp = 0; sp < spalten; sp++) {
      printf("%6.2lf", matrix[ze][sp]);
    }
    printf("\n");
  }
  printf("\n");
}

int multipliziereMatrizen (double matrixA[][MAX_SPALTEN], double matrixB[][MAX_SPALTEN], double matrixC[][MAX_SPALTEN], int zeilenA, int spaltenA, int zeilenB, int spaltenB, int *zeilenC, int *spaltenC) {
  if (spaltenA != zeilenB) {
    return 1; //Keine Multiplikation möglich
  }
  *zeilenC = zeilenA;
  *spaltenC = spaltenB;
  for (int zeC = 0; zeC < *zeilenC; zeC++) {
    for (int spC = 0; spC < *spaltenC; spC++) {
      matrixC[zeC][spC] = 0;
      for (int i = 0; i < spaltenA; i++) {
        matrixC[zeC][spC] += matrixA[zeC][i] * matrixB[i][spC];
      }
    }
  }
  return 0; //ok
}

double berechneDeterminante (double matrix[][MAX_SPALTEN], int groesse) {
  if (groesse == 1) {
    return matrix[0][0];
  }
  if (groesse == 2) {
    return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
  }
  //Entwicklungssatz nach Laplace
  //  es wird immer nach der ersten Spalte entwickelt
  double determinante = 0;
  int vorzeichen = 1;
  for (int i = 0; i < groesse; i++) {
    vorzeichen *= -1;
    //Submatrix erstellen
    double submatrix[MAX_SPALTEN][MAX_SPALTEN];
    int check = 0;
    for (int sze = 0; sze < groesse; sze++) {
      for (int ssp = 0; ssp < (groesse - 1); ssp++) {
        if (check == (groesse - 1)) {
          submatrix[sze - 1][ssp] = matrix[sze][ssp + 1];
        } else if (sze != i) {
          submatrix[sze][ssp] = matrix[sze][ssp + 1];
        } else if (sze == i) {
          check++;
        }
      }
    }
    //Test
    //gibMatrixAus(groesse - 1, submatrix);
    determinante += vorzeichen * matrix[i][0] * berechneDeterminante(submatrix, groesse - 1);
  }
  return determinante;
}

void erstelleKofaktormatrix(double matrix[][MAX_SPALTEN], double kofaktorMatrix[][MAX_SPALTEN], int groesse) {
  for (int kze = 0; kze < groesse; kze++) {
    for (int ksp = 0; ksp < groesse; ksp++) {
      //Submatrix erstellen
      double submatrix[MAX_SPALTEN][MAX_SPALTEN];
      int checkZeile = 0;
      int checkSpalte = 0;
      for (int sze = 0; sze < groesse; sze++) {
        for (int ssp = 0; ssp < groesse; ssp++) {
          if (checkZeile == groesse && checkSpalte < groesse) {
            submatrix[sze - 1][ssp] = matrix[sze][ssp];
          } else if (checkZeile < groesse && checkSpalte == groesse) {
            submatrix[sze][ssp - 1] = matrix[sze][ssp];
          } else if (checkZeile == groesse && checkSpalte == groesse) {
            submatrix[sze - 1][ssp - 1] = matrix[sze][ssp];
          } else if (sze != kze && ssp != ksp) {
            submatrix[sze][ssp] = matrix[sze][ssp];
          } else {
            if (sze == kze) {
              checkZeile++;
            }
            if (ssp == ksp) {
              checkSpalte++;
            }
          }
        }
      }
      kofaktorMatrix[kze][ksp] = pow(-1, kze + ksp) * berechneDeterminante(submatrix, groesse - 1);
    }
  }
}

int invertiereMatrix (double matrix[][MAX_SPALTEN], double inverseMatrix[][MAX_SPALTEN], int zeilen, int spalten, int *groesse) {
  if (zeilen != spalten) {
    return 1; //Matrix ist nicht quadratisch
  }
  double determinante = berechneDeterminante(matrix, zeilen);
  if (determinante == 0) {
    return 2; //Matrix ist nicht invertierbar
  }
  //Kofaktormatrix erstellen
  
  
  return 0;
}

int main () {
    int zeilenC;
    int spaltenC;

    double matrixA[4][4];
    double matrixB[4][4];
    double matrixC[1][MAX_SPALTEN];

    getMatrix("Matrix A", 4, 4, matrixA);
    
    invertiereMatrix(matrixA, matrixB, 4, 4, &zeilenC);

    gibMatrixAus("Matrix B", 4, 4, matrixB);

    return 0;
}
