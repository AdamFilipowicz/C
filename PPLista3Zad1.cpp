#include <stdio.h>

void wyzeruj(char *tab,int n);
void wypelnij(char *tab,int n);
void wypisz(char *tab,int n);

int main(){
    int n;
    printf("Podaj dlugosc tablicy:\n");
    scanf("%d",&n);
    if (n>=0){
        char *tab;
        tab=new char[n];
        wyzeruj(tab,n);
        wypelnij(tab,n);
        wypisz(tab,n);
        delete []tab;
    }
    else{
        printf("Podales bledny rozmiar tablicy");
    }
    return 0;
}

void wyzeruj(char *tab,int n){
    for(int i=0;i<=n;i++)
        tab[i]=0;
}

void wypelnij(char *tab,int n){
    for(int i=0;i<=n;i++){
        if (i%26==1)    tab[i-1]='A';
        else if(i%26==2)    tab[i-1]='B';
        else if(i%26==3)    tab[i-1]='C';
        else if(i%26==4)    tab[i-1]='D';
        else if(i%26==5)    tab[i-1]='E';
        else if(i%26==6)    tab[i-1]='F';
        else if(i%26==7)    tab[i-1]='G';
        else if(i%26==8)    tab[i-1]='H';
        else if(i%26==9)    tab[i-1]='I';
        else if(i%26==10)    tab[i-1]='J';
        else if(i%26==11)    tab[i-1]='K';
        else if(i%26==12)    tab[i-1]='L';
        else if(i%26==13)    tab[i-1]='M';
        else if(i%26==14)    tab[i-1]='N';
        else if(i%26==15)    tab[i-1]='O';
        else if(i%26==16)    tab[i-1]='P';
        else if(i%26==17)    tab[i-1]='Q';
        else if(i%26==18)    tab[i-1]='R';
        else if(i%26==19)    tab[i-1]='S';
        else if(i%26==20)    tab[i-1]='T';
        else if(i%26==21)    tab[i-1]='U';
        else if(i%26==22)    tab[i-1]='V';
        else if(i%26==23)    tab[i-1]='W';
        else if(i%26==24)    tab[i-1]='X';
        else if(i%26==25)    tab[i-1]='Y';
        else if(i%26==0)    tab[i-1]='Z';
    }
}

void wypisz(char *tab,int n){
    for(int i=0;i<=n;i++)
        printf("%c",tab[i]);
}
