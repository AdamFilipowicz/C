#include <stdio.h>
#include "Trojmiany.h"

int main()
{
    Trojmian A;
    Trojmian2 D;
    printf("Pierwszy wielomian:\n");
    printf("Podaj a\n");
    scanf("%f",&A.a);
    printf("Podaj b\n");
    scanf("%f",&A.b);
    printf("Podaj c\n");
    scanf("%f",&A.c);
    printf("Drugi wielomian:\n");
    printf("Podaj a\n");
    scanf("%f",&D.a2);
    printf("Podaj b\n");
    scanf("%f",&D.b2);
    printf("Podaj c\n");
    scanf("%f",&D.c2);
    Wypisz(A);
    WypiszPostacKanoniczna(A);
    WypiszMiejscaZerowe(A);
    TrojmianSuma(A,D);
    TrojmianRoznica(A,D);
    return 0;
}
