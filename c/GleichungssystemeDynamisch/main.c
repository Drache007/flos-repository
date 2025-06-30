// Programm umbauen mit dynamischer Speicherverwaltung

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//feld[zeilen][spalten]

int getInt (char *text) {
    char *s = NULL;
    size_t size = 0;
    int z;
    do{
        printf("%s: ", text);
        getline(&s, &size, stdin);
    } while (sscanf(s, "%d", &z) != 1);
    free(s);
    return z;
}

double getDouble (char *text) {
  char *s = NULL;
  size_t size = 0;
  double z;
  do {
    printf("%s: ", text);
    getline(&s, &size, stdin);
  } while (sscanf(s, "%lf", &z) != 1);
  free(s);
  return z;
}

int multipliziereMatrizen (double **matrixA, double **matrixB, double **matrixC, int zeilenA, int spaltenA, int zeilenB, int spaltenB) {
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

double berechneDeterminante (double **matrix, int groesse) {
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
    double **submatrix = malloc((groesse - 1) * sizeof(double *));
    for (int j = 0; j < groesse - 1; j++) {
      submatrix[j] = malloc((groesse - 1) * sizeof(double));
    }
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
    for (int j = 0; j < groesse - 1; j++) {
      free(submatrix[j]);
    }
    free(submatrix);
  }
  return determinante;
}

void getSubmatrix(double **src, double **dest, int groesse, int row, int col) {
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

void erstelleKofaktormatrix(double **matrix, double **kofaktorMatrix, int groesse) {
  for (int kze = 0; kze < groesse; kze++) {
    for (int ksp = 0; ksp < groesse; ksp++) {
      //Submatrix erstellen
      double **submatrix = malloc((groesse - 1) *sizeof(double *));
      for (int i = 0; i < groesse - 1; i++) {
        submatrix[i] = malloc((groesse - 1) * sizeof(double));
      }
      getSubmatrix(matrix, submatrix, groesse, kze, ksp);
      kofaktorMatrix[kze][ksp] = pow(-1, kze + ksp) * berechneDeterminante(submatrix, groesse - 1);
      for (int i = 0; i < groesse - 1; i++) {
        free(submatrix[i]);
      }
      free(submatrix);
    }
  }
}

void transponiereMatrix (double **matrix, double **transponierteMatrix, int groesse) {
  //Matrix um Hauptdiagonale spiegeln
  for (int ze = 0; ze < groesse; ze++) {
    for (int sp = 0; sp < groesse; sp++) {
      transponierteMatrix[ze][sp] = matrix[sp][ze];
    }
  }
}

void multipliziereMatrixMitSkalar (double **matrix, double **ergebnis, int zeilen, int spalten, double skalar) {
  for (int ze = 0; ze < zeilen; ze++) {
    for (int sp = 0; sp < spalten; sp++) {
      ergebnis[ze][sp] = matrix[ze][sp] * skalar;
    }
  }
}

int invertiereMatrix (double **matrix, double **inverseMatrix, int zeilen, int spalten) {
  if (zeilen != spalten) {
    return 1; //Matrix ist nicht quadratisch
  }
  double determinante = berechneDeterminante(matrix, zeilen);
  if (determinante == 0.00) {
    return 2; //Matrix ist nicht invertierbar
  }
  //Kofaktormatrix erstellen
  double **kofaktormatrix = malloc(zeilen * sizeof(double *));
  for (int i = 0; i < zeilen; i++) {
    kofaktormatrix[i] = malloc(zeilen * sizeof(double));
  }
  erstelleKofaktormatrix(matrix, kofaktormatrix, zeilen);
  //Matrix transponieren
  double **adjungierteMatrix = malloc(zeilen * sizeof(double *));
  for (int i = 0; i < zeilen; i++) {
    adjungierteMatrix[i] = malloc(zeilen * sizeof(double));
  }
  transponiereMatrix(kofaktormatrix, adjungierteMatrix, zeilen);
  for (int i = 0; i < zeilen; i++) {
    free(kofaktormatrix[i]);
  }
  free(kofaktormatrix);
  multipliziereMatrixMitSkalar(adjungierteMatrix, inverseMatrix, zeilen, zeilen, -1 / determinante);
  for (int i = 0; i < zeilen; i++) {
    free(adjungierteMatrix[i]);
  }
  free(adjungierteMatrix);
  return 0;
}

size_t getString (char *text, char *eingabe) {
  printf("%s: ", text);
  size_t size = 0;
  getline(&eingabe, &size, stdin);
  return size;
}

void printEingabeGleichungssystem(int groesse, double **matrix, double **ergebnisse, int pos, char **variablen) {
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

void getGleichungssystem (int groesse, double **matrix, double **ergebnisse, char **variablen) {
  for (int i = 0; i < groesse; i++) {
    char *s = NULL;
    size_t len = 0;
    printf("Name der Variablen: ");
    size_t read = getline(&s, &len, stdin);
    if (read > 0 && s[read-1] == '\n') s[read-1] = '\0';
    variablen[i] = malloc(strlen(s) + 1);
    strcpy(variablen[i], s);
    free(s);
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

int loeseGleichungssystem (int groesse, double **matrix, double **ergebnisse, char **variblenNamen, double **variablen) {
  double **inverseMatrix = malloc(groesse * sizeof(double *));
  for (int i = 0; i < groesse; i++) {
    inverseMatrix[i] = malloc(groesse * sizeof(double));
  }
  int fehler = invertiereMatrix(matrix, inverseMatrix, groesse, groesse);
  if (fehler != 0) {
    return fehler;
  }
  fehler = multipliziereMatrizen(inverseMatrix, ergebnisse, variablen, groesse, groesse, groesse, 1);
  for (int i = 0; i < groesse; i++) {
    free(inverseMatrix[i]);
  }
  free(inverseMatrix);
  if (fehler != 0) {
    return 3;
  }
  return 0;
}

void printLoesung (int groesse, char **variablenNamen, double **variablen) {
  printf("Lösunge:\n");
  printf("========\n\n");
  for (int i = 0; i < groesse; i++) {
    printf("  %s = %.3lf\n", variablenNamen[i], variablen[i][0]);
  }
}

int main () {
  printf("Lineares Gleichungssystem lösen:\n");
  printf("================================\n\n");
  int groesse = getInt("Anzahl der Gleichungen und Unbekannten");
  system("clear"); //nur Linux, "cls" für Windows
  double **matrix = malloc(groesse * sizeof(double*));
  for (int i = 0; i < groesse; i++) {
    matrix[i] = malloc(groesse * sizeof(double));
  }
  double **ergebnisse = malloc(groesse * sizeof(double*));
  for (int i = 0; i < groesse; i++) {
    ergebnisse[i] = malloc(sizeof(double));
  }
  double **variablen = malloc(groesse * sizeof(double*));
  for (int i = 0; i < groesse; i++) {
    variablen[i] = malloc(sizeof(double));
  }
  char **variablenNamen = malloc(groesse * sizeof(char*));
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
  for (int i = 0; i < groesse; i++) {
    free(matrix[i]);
    free(ergebnisse[i]);
    free(variablen[i]);
  }
  free(matrix);
  free(ergebnisse);
  free(variablen);
  return 0;
}
