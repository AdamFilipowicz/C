#include <stdio.h>
#include <stdlib.h>
//Podstawy dynamicznej deklaracji dwuwymiarowej tablicy. Program według pewnego algorytmu rysuje "drzewo" kropek i iksów.
void Wypisz(char**tab, int m, int n);
int main ()
{
    int m,n;
    printf("Podaj liczbe kolumn: ");
    scanf("%d", &n);
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &m);
    int i,j,wynik;
    char **tab2d;
    tab2d=new char*[m];
    for (i = 0; i < m; i++)
    {
        tab2d[i]=new char[n];
    }
    for(i=0; i<n; i++)
    {
        if(i==n/2) tab2d[0][i]='X';
        else tab2d[0][i]='.';
    }
    for(i=1; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            wynik=0;
            if(j!=0 && j!=m-1)
            {
                if(tab2d[i-1][j-1]=='X') wynik+=4;
                if(tab2d[i-1][j]=='X') wynik+=2;
                if(tab2d[i-1][j+1]=='X') wynik++;
                if(wynik==0 || wynik>4) tab2d[i][j]='.';
                else tab2d[i][j]='X';
            }
            else if(j==0)
            {
                if(tab2d[i-1][(j-1)%n]=='X') wynik+=4;
                if(tab2d[i-1][j]=='X') wynik+=2;
                if(tab2d[i-1][j+1]=='X') wynik++;
                if(wynik==0 || wynik>4) tab2d[i][j]='.';
                else tab2d[i][j]='X';
            }
            else if(j==m-1)
            {
                if(tab2d[i-1][j-1]=='X') wynik+=4;
                if(tab2d[i-1][j]=='X') wynik+=2;
                if(tab2d[i-1][(j+1)%n]=='X') wynik++;
                if(wynik==0 || wynik>4) tab2d[i][j]='.';
                else tab2d[i][j]='X';
            }
        }
    }
    Wypisz(tab2d, m, n);
    for (i = 0; i < 11; i++)
    {
        delete tab2d[i];
    }
    delete tab2d;
    return 0;
}
void Wypisz(char**tab, int m, int n)
{
    int i,j;
    for(i=0;i<m; i++)
    {
        printf("\n");
        for(j=0; j<n; j++)
            printf("%c", tab[i][j]);
    }
}
