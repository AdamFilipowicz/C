#include <stdio.h>
//Podstawy programowania obiektowego. Program przelicza "ziarno" na system dwójkowy w postaci kropek i iksów.
class CA{
    private:
        char *tablica;
        char *tablica2;
        int wymiar;
        int ziarno;
    public:
        CA();
        CA(int W,int Z);
        ~CA();
        int Wymiar();
        void Iteruj();
        void Wypisz();
};

int main(){
    CA T;
    T.Wymiar();
    T.Wypisz();
    T.Iteruj();
}

CA::CA(int W,int Z){
    wymiar=W;
    ziarno=Z;
    tablica=new char[wymiar];
    tablica2=new char[wymiar];
    for(int i=0;i<wymiar;i++){
        if(i==wymiar/2) tablica[i]='X';
        else tablica[i]='.';
    }
}

CA::CA(){
    int WY,ZI;
    WY=20;
    ZI=128;
    tablica=new char[WY];
    tablica2=new char[WY];
    wymiar=WY;
    ziarno=ZI;
    for(int i=0;i<wymiar;i++){
        if(i==wymiar/2) tablica[i]='X';
        else tablica[i]='.';
    }
}

CA::~CA(){
    delete []tablica;
    delete []tablica2;
}

int CA::Wymiar(){
    printf("Wymiar:%d\n",wymiar);
    return wymiar;
}

void CA::Wypisz(){
    if (ziarno>255) printf("Ziarno za du¿e");
    else{
        for(int i=0;i<wymiar;i++)
            printf("%c",tablica[i]);
        printf("\n");
    }
}

void CA::Iteruj(){
    if (ziarno>255) printf("\n");
    else{
        int *tabdw;
        tabdw=new int[8];
        for(int i=0;i<8;i++){
            tabdw[i]=0;
        }
        for(int i=0;i<8;i++){
            tabdw[7-i]=ziarno%2;
            ziarno=ziarno/2;
        }
        for(int i=1;i<wymiar;i++){
            int wynik;
            for(int j=0;j<wymiar;j++){
                wynik=0;
                if(j!=wymiar){
                    if(tablica[(j-1)%wymiar]=='X') wynik+=4;
                    if(tablica[j]=='X') wynik+=2;
                    if(tablica[j+1]=='X') wynik++;
                    if(wynik==0) tablica2[j]='.';
                    else if(tabdw[wynik-1]==1) tablica2[j]='X';
                    else tablica2[j]='.';
                }
                else if(j==wymiar){
                    if(tablica[j-1]=='X') wynik+=4;
                    if(tablica[j]=='X') wynik+=2;
                    if(tablica[(j+1)%wymiar]=='X') wynik++;
                    if(wynik==0) tablica2[j]='.';
                    else if(tabdw[wynik-1]==1) tablica2[j]='X';
                    else tablica2[j]='.';
                }
            }
            for(int k=0;k<wymiar;k++)
                printf("%c",tablica2[k]);
            printf("\n");
            for(int i=0;i<wymiar;i++)
                tablica[i]=tablica2[i];
        }
        printf("Ziarno dwojkowo:");
        for(int i=0;i<8;i++){
            printf("%d",tabdw[i]);
        }
        delete []tabdw;
    }
}
