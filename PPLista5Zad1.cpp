#include <stdio.h>
#include <iostream>

using namespace std;

class CA{
    private:
        char *tablica;
        int wymiar;
        int ziarno;
    public:
        CA();
        CA(int W,int Z);
        ~CA();
        CA(const CA &q);
        CA& operator=(const CA &q);
        int Wymiar();
        void Iteruj();
        void Wypisz();
};

int main(){
    cout<<"MENU\n"<<"0 - koniec\n"<<"1 - Zadaj nowe dane wejsciowe oraz nowa liczbe iteracji\n"<<"2 - Przetestuj metode Wymiar()\n";
    char wybor;
    cin>>wybor;
    switch(wybor){
        case('1'):{
            CA T;
            CA operator=kopia(T);
            T.Wymiar();
            T.Wypisz();
            T.Iteruj();
            break;
        }

        case('2'):{
            CA T(10,10);
            T.Wymiar();
            break;
        }

        case('0'):{return 0;break;}
    }
}

CA::CA(int W,int Z){
    tablica=new char[W];
    wymiar=W;
    ziarno=Z;
    for(int i=0;i<wymiar;i++){
        if(i==wymiar/2) tablica[i]='X';
        else tablica[i]='.';
    }
}

CA::CA(){
    int WY,ZI;
    cout<<"Podaj wymiar";
    cin>>WY;
    cout<<"Podaj ziarno";
    cin>>ZI;
    tablica=new char[WY];
    wymiar=WY;
    ziarno=ZI;
    for(int i=0;i<wymiar;i++){
        if(i==wymiar/2) tablica[i]='X';
        else tablica[i]='.';
    }
}

CA::~CA(){
    delete []tablica;
}

CA::CA(const CA &q){
    wymiar=q.wymiar;
    tablica=new char[wymiar];
    for(int d=0;d<wymiar;d++){
        tablica[d]=q.tablica[d];
    }
}
CA& CA::operator=(const CA &q){
    if(&q==this) return *this;
    if(tablica!=NULL) delete []tablica;
    wymiar=q.wymiar;
    tablica=new char[wymiar];
    for(int d=0;d<wymiar;d++){
        tablica[d]=q.tablica[d];
    }
    return * this;
}

int CA::Wymiar(){
    printf("Wymiar:%d\n",wymiar);
    return wymiar;
}

void CA::Wypisz(){
    if (ziarno>255) printf("Ziarno za duze");
    else{
        for(int i=0;i<wymiar;i++)
            printf("%c",tablica[i]);
        printf("\n");
    }
}

void CA::Iteruj(){
    CA kopia(*this);
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
                    if(wynik==0) kopia.tablica[j]='.';
                    else if(tabdw[wynik-1]==1) kopia.tablica[j]='X';
                    else kopia.tablica[j]='.';
                }
                else if(j==wymiar){
                    if(tablica[j-1]=='X') wynik+=4;
                    if(tablica[j]=='X') wynik+=2;
                    if(tablica[(j+1)%wymiar]=='X') wynik++;
                    if(wynik==0) kopia.tablica[j]='.';
                    else if(tabdw[wynik-1]==1) kopia.tablica[j]='X';
                    else kopia.tablica[j]='.';
                }
            }
            for(int k=0;k<wymiar;k++)
                printf("%c",kopia.tablica[k]);
            printf("\n");
            for(int i=0;i<wymiar;i++)
                tablica[i]=kopia.tablica[i];
        }
        printf("Ziarno dwojkowo:");
        for(int i=0;i<8;i++){
            printf("%d",tabdw[i]);
        }
        delete []tabdw;
    }
}
