#include <stdio.h>
#include <iostream>

using namespace std;

class Scianka{
    private:
        char *Tab;
        char *Tab2;
        const char KolorSrodka;
    public:
        Scianka(char kolor);
        ~Scianka();
        void ObrotC();
        void ObrotAC();
        void Wypisz();
        void Wypisz(int i);
        void Set();
        char Get(int i);
        friend void Obrot(Scianka &A,int a1,int a2,int a3,Scianka &B,int b1,int b2,int b3,Scianka &C,int c1,int c2,int c3,Scianka &D,int d1,int d2,int d3,Scianka &E,int e1,int e2,int e3);
};

int main(){
    int koniec;
    char kolor;
    char wybor;
    cout<<"Podaj kolor srodka\n";
    cin>>kolor;
    koniec=0;
    Scianka T(kolor);
    T.Set();
    T.Wypisz();
    while(koniec!=1){
        cout<<"MENU\n"<<"0 - Koniec\n"<<"1 - Obroc scianke zgodnie z ruchem wskazowek zegara\n"<<"2 - Obroc scianke przeciwnie do ruchu wskazowek zegara\n"<<"3 - Przetestuj metode Wypisz(i)\n";
        cin>>wybor;
        switch(wybor){
            case('1'):{
                T.ObrotC();
                T.Wypisz();
                break;
            }

            case('2'):{
                T.ObrotAC();
                T.Wypisz();
                break;
            }

            case('3'):{
                int i;
                cout<<"Podaj i-ty wiersz: ";
                cin>>i;
                T.Wypisz(i);
                break;
            }
            case('0'):{
                koniec=1;
                break;
            }
            default:{
                koniec=1;
                break;
            }
        }
    }
}

Scianka::Scianka(char kolor):KolorSrodka(kolor){
    Tab=new char[8];
    Tab2=new char[8];
}

Scianka::~Scianka(){
    delete []Tab;
    delete []Tab2;
}

void Scianka::ObrotC(){
    Tab[0]=Tab2[6];
    Tab[1]=Tab2[7];
    for(int i=2;i<8;i++)
        Tab[i]=Tab2[i-2];
    for(int i=0;i<8;i++)
        Tab2[i]=Tab[i];
}

void Scianka::ObrotAC(){
    Tab[6]=Tab2[0];
    Tab[7]=Tab2[1];
    for(int i=0;i<6;i++)
        Tab[i]=Tab2[i+2];
    for(int i=0;i<8;i++)
        Tab2[i]=Tab[i];
}

void Scianka::Wypisz(){
    printf("%c %c %c\n%c %c %c\n%c %c %c\n",Tab[0],Tab[1],Tab[2],Tab[7],KolorSrodka,Tab[3],Tab[6],Tab[5],Tab[4]);
}

void Scianka::Wypisz(int i){
    if(i==1)
        printf("%c %c %c\n",Tab[0],Tab[1],Tab[2]);
    else if(i==2)
        printf("%c %c %c\n",Tab[7],KolorSrodka,Tab[3]);
    else if(i==3)
        printf("%c %c %c\n",Tab[6],Tab[5],Tab[4]);
    else
        printf("Bledny wiersz\n");
}

void Scianka::Set(){
    for(int i=0;i<8;i++){
        cout<<"Podaj kolor kwadraciku\n";
        cin>>Tab[i];
    }
    for(int i=0;i<8;i++)
        Tab2[i]=Tab[i];
}

void Obrot(Scianka &A,int a1,int a2,int a3,Scianka &B,int b1,int b2,int b3,Scianka &C,int c1,int c2,int c3,Scianka &D,int d1,int d2,int d3,Scianka &E,int e1,int e2,int e3){
    for(int i=0;i<8;i++){
        E.Tab[i]=A.Tab[i];
        A.Tab[i]=B.Tab[i];
        B.Tab[i]=C.Tab[i];
        C.Tab[i]=D.Tab[i];
        D.Tab[i]=E.Tab[i];
    }
}
