#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SPALTEN 20
#define MAX_NAME_LEN 20

//feld[zeilen][spalten]

int getInt (char text[], int min, int max) {
  char s[100];
  int z;
  do {
    printf("%s: ", text);
    fgets(s, sizeof s, stdin);
  } while (sscanf(s, "%d", &z) != 1 || z < min || z > max);
  return z;
}

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

int multipliziereMatrizen (double matrixA[][MAX_SPALTEN], double matrixB[][MAX_SPALTEN], double matrixC[][MAX_SPALTEN], int zeilenA, int spaltenA, int zeilenB, int spaltenB) {
  if (spaltenA != zeilenB) {
    return 1; //Keine Multiplikation möglich
  }
  for (int zeC = 0; zeC < zeilenA; zeC++) {
    for (int spC = 0; spC < spaltenB; spC++) {
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
    determinante += vorzeichen * matrix[i][0] * berechneDeterminante(submatrix, groesse - 1);
  }
  return determinante;
}

void getSubmatrix(double src[][MAX_SPALTEN], double dest[][MAX_SPALTEN], int groesse, int row, int col) {
  int r = 0, c = 0;
  for (int i = 0; i < groesse; i++) {
    if (i == row) continue;
      c = 0;
    for (int j = 0; j < groesse; j++) {
      if (j == col) continue;
        dest[r][c] = src[i][j];
        c++;
      }
    r++;
    }
}

void erstelleKofaktormatrix(double matrix[][MAX_SPALTEN], double kofaktorMatrix[][MAX_SPALTEN], int groesse) {
  for (int kze = 0; kze < groesse; kze++) {
    for (int ksp = 0; ksp < groesse; ksp++) {
      //Submatrix erstellen
      double submatrix[MAX_SPALTEN][MAX_SPALTEN];
      getSubmatrix(matrix, submatrix, groesse, kze, ksp);
      kofaktorMatrix[kze][ksp] = pow(-1, kze + ksp) * berechneDeterminante(submatrix, groesse - 1);
    }
  }
}

void transponiereMatrix (double matrix[][MAX_SPALTEN], double transponierteMatrix[][MAX_SPALTEN], int groesse) {
  //Matrix um Hauptdiagonale spiegeln
  for (int ze = 0; ze < groesse; ze++) {
    for (int sp = 0; sp < groesse; sp++) {
      transponierteMatrix[ze][sp] = matrix[sp][ze];
    }
  }
}

void multipliziereMatrixMitSkalar (double matrix[][MAX_SPALTEN], double ergebnis[][MAX_SPALTEN], int zeilen, int spalten, double skalar) {
  for (int ze = 0; ze < zeilen; ze++) {
    for (int sp = 0; sp < spalten; sp++) {
      ergebnis[ze][sp] = matrix[ze][sp] * skalar;
    }
  }
}

int invertiereMatrix (double matrix[][MAX_SPALTEN], double inverseMatrix[][MAX_SPALTEN], int zeilen, int spalten) {
  if (zeilen != spalten) {
    return 1; //Matrix ist nicht quadratisch
  }
  double determinante = berechneDeterminante(matrix, zeilen);
  if (determinante == 0.00) {
    return 2; //Matrix ist nicht invertierbar
  }
  //Kofaktormatrix erstellen
  double kofaktormatrix[MAX_SPALTEN][MAX_SPALTEN];
  erstelleKofaktormatrix(matrix, kofaktormatrix, zeilen);
  //Matrix transponieren
  double adjungierteMatrix[MAX_SPALTEN][MAX_SPALTEN];
  transponiereMatrix(kofaktormatrix, adjungierteMatrix, zeilen);

  multipliziereMatrixMitSkalar(adjungierteMatrix, inverseMatrix, zeilen, zeilen, -1 / determinante);
  
  return 0;
}

void getString (char text[], char eingabe[]) {
  printf("%s: ", text);
  fgets(eingabe, MAX_NAME_LEN, stdin);
}

void printEingabeGleichungssystem(int groesse, double matrix[][MAX_SPALTEN], double ergebnisse[][MAX_SPALTEN], int pos, char variablen[][MAX_NAME_LEN]) {
    printf("Gleichungssystem in Matrixschreibweise eingeben:\n");
    printf("================================================\n\n");
    // Kopfzeile mit Variablennamen
    for (int sp = 0; sp < groesse; sp++) {
        printf("%8s", variablen[sp]);
    }
    printf(" |%8s\n", "Ergebnis");
    for (int ze = 0; ze < groesse; ze++) {
        for (int sp = 0; sp < groesse; sp++) {
            int index = ze * groesse + sp;
            if (index < pos) {
                printf("%8.2lf", matrix[ze][sp]);
            } else if (index == pos) {
                printf("%8c", 'x');
            } else {
                printf("%8s", "*");
            }
        }
        printf(" |");
        int ergIndex = groesse * groesse + ze;
        if (ergIndex < pos) {
            printf("%8.2lf", ergebnisse[ze][0]);
        } else if (ergIndex == pos) {
            printf("%8c", 'x');
        } else {
            printf("%8s", "*");
        }
        printf("\n");
    }
    printf("\n");
}

void getGleichungssystem (int groesse, double matrix[][MAX_SPALTEN], double ergebnisse[][MAX_SPALTEN], char variablen[][MAX_NAME_LEN]) {
  for (int i = 0; i < groesse; i++) {
    getString("Name der Variablen", variablen[i]);
    variablen[i][strcspn(variablen[i], "\n")] = '\0';
  }
  for (int ze = 0; ze < groesse; ze++) {
    for (int sp = 0; sp < groesse; sp++) {
      printEingabeGleichungssystem(groesse, matrix, ergebnisse, ze * groesse + sp, variablen);
      printf("\n");
      matrix[ze][sp] = getDouble("Zahl bei x");
      system("clear"); //nur Linux, "cls" für Windows
    }
  }
  for (int i = 0; i < groesse; i++) {
    printEingabeGleichungssystem(groesse, matrix, ergebnisse, groesse * groesse + i, variablen);
    printf("\n");
    ergebnisse[i][0] = getDouble("Ergebnis der Gleichung");
    system("clear"); //nur Linux, "cls" für Windows
  }
  printEingabeGleichungssystem(groesse, matrix, ergebnisse, groesse * (groesse + 1), variablen);
  printf("\n\n");
}

int loeseGleichungssystem (int groesse, double matrix[][MAX_SPALTEN], double ergebnisse[][MAX_SPALTEN], char variblenNamen[][MAX_NAME_LEN], double variablen[][MAX_SPALTEN]) {
  double inverseMatrix[MAX_SPALTEN][MAX_SPALTEN];
  int fehler = invertiereMatrix(matrix, inverseMatrix, groesse, groesse);
  if (fehler != 0) {
    return fehler;
  }
  fehler = multipliziereMatrizen(inverseMatrix, ergebnisse, variablen, groesse, groesse, groesse, 1);
  if (fehler != 0) {
    return 3;
  }
  return 0;
}

void printLoesung (int groesse, char variablenNamen[][MAX_NAME_LEN], double variablen[][MAX_SPALTEN]) {
  printf("Lösunge:\n");
  printf("========\n\n");
  for (int i = 0; i < groesse; i++) {
    printf("  %s = %.3lf\n", variablenNamen[i], variablen[i][0]);
  }
}

int main () {
  double matrix[MAX_SPALTEN][MAX_SPALTEN];
  double ergebnisse[MAX_SPALTEN][MAX_SPALTEN];
  char variablenNamen[MAX_SPALTEN][MAX_NAME_LEN];
  double variablen[MAX_SPALTEN][MAX_SPALTEN];

  printf("Lineares Gleichungssystem lösen:\n");
  printf("================================\n\n");
  char text[100];
  sprintf(text, "  Anzahl der Gleichungen und Unbekannten (maximal: %d)", MAX_SPALTEN);
  int groesse = getInt(text, 1, MAX_SPALTEN);
  //system("clear"); //nur Linux, "cls" für Windows
  getGleichungssystem(groesse, matrix, ergebnisse, variablenNamen);
  int fehler = loeseGleichungssystem(groesse, matrix, ergebnisse, variablenNamen, variablen);
  if (fehler != 0) {
    switch (fehler) {
      case 1: {
        printf("Fehler: Matrix ist nicht quadratisch!");
        return 1;
      }
      case 2: {
        printf("Fehler: Matrix ist nicht invertierbar!");
        return 2;
      }
      case 3: {
        printf("Fehler beim multiplizieren!");
        return 3;
      }
    }
  }
  printLoesung(groesse, variablenNamen, variablen);

  return 0;
}
