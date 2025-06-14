// Berechnung der Determinante einer beliebig großen Matrix mithilfe des Entwicklungssatzes von Laplace

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPALTEN 10

int getInt (char text[], int max, int min) {
  char s[100];
  int z;
  do {
    printf("%s: ", text);
    fgets(s, sizeof s, stdin);
  } while (sscanf(s, "%d", &z) != 1 || z < min || z > max);
  return z;
}

int getRandomInt (int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generiereQuadratischeMatrix (int matrix[][MAX_SPALTEN], int groesse) {
    for (int ze = 0; ze < groesse; ze++) {
        for (int sp = 0; sp < groesse; sp++) {
            matrix[ze][sp] = getRandomInt(-10, 10);
        }
    }
}

void gibMatrixAus (int groesse, int matrix[][MAX_SPALTEN]) {
  for (int ze = 0; ze < groesse; ze++) {
    for (int sp = 0; sp < groesse; sp++) {
      printf("%6d", matrix[ze][sp]);
    }
    printf("\n");
  }
  printf("\n");
}

int berechneDeterminante (int matrix[][MAX_SPALTEN], int groesse) {
  if (groesse == 1) {
    return matrix[0][0];
  }
  if (groesse == 2) {
    return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
  }
  //Entwicklungssatz nach Laplace
  //  es wird immer nach der ersten Spalte entwickelt
  int determinante = 0;
  int vorzeichen = 1;
  for (int i = 0; i < groesse; i++) {
    vorzeichen *= -1;
    //Submatrix erstellen
    int submatrix[MAX_SPALTEN][MAX_SPALTEN];
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

int main () {
    srand(time(NULL));
    int matrix[MAX_SPALTEN][MAX_SPALTEN];
    int groesse = getInt("Geben Sie die Groesse der Matrix ein", MAX_SPALTEN, 1);
    generiereQuadratischeMatrix(matrix, groesse);
    gibMatrixAus(groesse, matrix);
    int det = berechneDeterminante(matrix, groesse);
    printf("Die Determinante der Matrix ist: %d\n", det);

    return 0;
}