#include <stdio.h>
#include <iostream>
//Program kostka rubika ukazujący 2wymiarowo kostkę którą można obracać komendami. Program zwraca komunikat gdy kostka jest ułożona.
using namespace std;

class Kostka{
    private:
        char *Tab1;
        char *Tab2;
        char *Tab3;
        char *Tab4;
        char *Tab5;
        char *Tab6;
        char *Tab0;
        char *Tab12;
        char *Tab22;
        char *Tab32;
        char *Tab42;
        char *Tab52;
        char *Tab62;
    public:
        Kostka();
        ~Kostka();
        void U();
        void u();
        void L();
        void l();
        void F();
        void f();
        void R();
        void r();
        void B();
        void b();
        void D();
        void d();
        void Wypisz();
        void CzyUlozona();
        void Ruch(char c);
};

int main(){
    int koniec;
    char wybor;
    Kostka T;
    koniec=0;
    while(koniec!=1){
        T.Wypisz();
        T.CzyUlozona();
        cout<<"KOSTKA RUBIKA\n"<<"Wybierz metode: U u L l F f R r B b D d\n"<<"K - Zakoncz gre\n";
        cin>>wybor;
        switch(wybor){
            case('U'):{
                T.U();
                break;
            }
            case('u'):{
                T.u();
                break;
            }
            case('L'):{
                T.L();
                break;
            }
            case('l'):{
                T.l();
                break;
            }
            case('F'):{
                T.F();
                break;
            }
            case('f'):{
                T.f();
                break;
            }
            case('R'):{
                T.R();
                break;
            }
            case('r'):{
                T.r();
                break;
            }
            case('B'):{
                T.B();
                break;
            }
            case('b'):{
                T.b();
                break;
            }
            case('D'):{
                T.D();
                break;
            }
            case('d'):{
                T.d();
                break;
            }
            case('K'):{
                cout<<"Koniec gry";
                koniec=1;
                break;
            }
            default:{
                cout<<"Podany nieprawidlowy znak";
                koniec=1;
                break;
            }
        }
    }
}

Kostka::Kostka(){
    Tab1=new char[9];
    Tab2=new char[9];
    Tab3=new char[9];
    Tab4=new char[9];
    Tab5=new char[9];
    Tab6=new char[9];
    Tab0=new char[9];
    Tab12=new char[9];
    Tab22=new char[9];
    Tab32=new char[9];
    Tab42=new char[9];
    Tab52=new char[9];
    Tab62=new char[9];
    for(int i=0;i<9;i++){
        Tab1[i]='W';
        Tab2[i]='R';
        Tab3[i]='B';
        Tab4[i]='O';
        Tab5[i]='G';
        Tab6[i]='Y';
    }
        for(int i=0;i<9;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
        Tab0[i]='A';
    }
}

Kostka::~Kostka(){
    delete []Tab1;
    delete []Tab2;
    delete []Tab3;
    delete []Tab4;
    delete []Tab5;
    delete []Tab6;
    delete []Tab0;
    delete []Tab12;
    delete []Tab22;
    delete []Tab32;
    delete []Tab42;
    delete []Tab52;
    delete []Tab62;
}

void Kostka::U(){
    int i;
    Tab1[0]=Tab12[6];
    Tab1[1]=Tab12[7];
    for(i=2;i<8;i++)
        Tab1[i]=Tab12[i-2];
    for(i=0;i<3;i++){
        Tab0[i]=Tab2[i];
        Tab2[i]=Tab3[i];
        Tab3[i]=Tab4[i];
        Tab4[i]=Tab5[i];
        Tab5[i]=Tab0[i];
    }
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::u(){
    int i;
    Tab1[6]=Tab12[0];
    Tab1[7]=Tab12[1];
    for(int i=0;i<6;i++)
        Tab1[i]=Tab12[i+2];
    for(i=0;i<3;i++){
        Tab0[i]=Tab5[i];
        Tab5[i]=Tab4[i];
        Tab4[i]=Tab3[i];
        Tab3[i]=Tab2[i];
        Tab2[i]=Tab0[i];
    }
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::L(){
    int i;
    Tab2[0]=Tab22[6];
    Tab2[1]=Tab22[7];
    for(i=2;i<8;i++)
        Tab2[i]=Tab22[i-2];
    for(i=2;i<4;i++){
        Tab0[i]=Tab5[i];
        Tab5[i]=Tab6[i+4];
        Tab6[i+4]=Tab3[i+4];
        Tab3[i+4]=Tab1[i+4];
        Tab1[i+4]=Tab0[i];
    }
    Tab0[4]=Tab5[4];
    Tab5[4]=Tab6[0];
    Tab6[0]=Tab3[0];
    Tab3[0]=Tab1[0];
    Tab1[0]=Tab0[4];
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::l(){
    int i;
    Tab2[6]=Tab22[0];
    Tab2[7]=Tab22[1];
    for(int i=0;i<6;i++)
        Tab2[i]=Tab22[i+2];
    for(i=2;i<4;i++){
        Tab0[i]=Tab1[i+4];
        Tab1[i+4]=Tab3[i+4];
        Tab3[i+4]=Tab6[i+4];
        Tab6[i+4]=Tab5[i];
        Tab5[i]=Tab0[i];
    }
    Tab0[4]=Tab1[0];
    Tab1[0]=Tab3[0];
    Tab3[0]=Tab6[0];
    Tab6[0]=Tab5[4];
    Tab5[4]=Tab0[4];
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::F(){
    int i;
    Tab3[0]=Tab32[6];
    Tab3[1]=Tab32[7];
    for(i=2;i<8;i++)
        Tab3[i]=Tab32[i-2];
    for(i=2;i<4;i++){
        Tab0[i]=Tab2[i];
        Tab2[i]=Tab6[i-2];
        Tab6[i-2]=Tab4[i+4];
        Tab4[i+4]=Tab1[i+2];
        Tab1[i+2]=Tab0[i];
    }
    Tab0[4]=Tab2[4];
    Tab2[4]=Tab6[2];
    Tab6[2]=Tab4[0];
    Tab4[0]=Tab1[6];
    Tab1[6]=Tab0[4];
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::f(){
    int i;
    Tab3[6]=Tab32[0];
    Tab3[7]=Tab32[1];
    for(int i=0;i<6;i++)
        Tab3[i]=Tab32[i+2];
    for(i=2;i<4;i++){
        Tab0[i]=Tab1[i+2];
        Tab1[i+2]=Tab4[i+4];
        Tab4[i+4]=Tab6[i-2];
        Tab6[i-2]=Tab2[i];
        Tab2[i]=Tab0[i];
    }
    Tab0[4]=Tab1[6];
    Tab1[6]=Tab4[0];
    Tab4[0]=Tab6[2];
    Tab6[2]=Tab2[4];
    Tab2[4]=Tab0[4];
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::R(){
    int i;
    Tab4[0]=Tab42[6];
    Tab4[1]=Tab42[7];
    for(i=2;i<8;i++)
        Tab4[i]=Tab42[i-2];
    for(i=2;i<4;i++){
        Tab0[i]=Tab1[i];
        Tab1[i]=Tab3[i];
        Tab3[i]=Tab6[i];
        Tab6[i]=Tab5[i+4];
        Tab5[i+4]=Tab0[i];
    }
    Tab0[4]=Tab1[4];
    Tab1[4]=Tab3[4];
    Tab3[4]=Tab6[4];
    Tab6[4]=Tab5[0];
    Tab5[0]=Tab0[4];
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::r(){
    int i;
    Tab4[6]=Tab42[0];
    Tab4[7]=Tab42[1];
    for(int i=0;i<6;i++)
        Tab4[i]=Tab42[i+2];
    for(i=2;i<4;i++){
        Tab0[i]=Tab5[i+4];
        Tab5[i+4]=Tab6[i];
        Tab6[i]=Tab3[i];
        Tab3[i]=Tab1[i];
        Tab1[i]=Tab0[i];
    }
    Tab0[4]=Tab5[0];
    Tab5[0]=Tab6[4];
    Tab6[4]=Tab3[4];
    Tab3[4]=Tab1[4];
    Tab1[4]=Tab0[4];
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::B(){
    int i;
    Tab5[0]=Tab52[6];
    Tab5[1]=Tab52[7];
    for(i=2;i<8;i++)
        Tab5[i]=Tab52[i-2];
    for(i=2;i<4;i++){
        Tab0[i-2]=Tab1[i-2];
        Tab1[i-2]=Tab4[i];
        Tab4[i]=Tab6[i+2];
        Tab6[i+2]=Tab2[i+4];
        Tab2[i+4]=Tab0[i-2];
    }
    Tab0[2]=Tab1[2];
    Tab1[2]=Tab4[4];
    Tab4[4]=Tab6[6];
    Tab6[6]=Tab2[0];
    Tab2[0]=Tab0[2];
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::b(){
    int i;
    Tab5[6]=Tab52[0];
    Tab5[7]=Tab52[1];
    for(int i=0;i<6;i++)
        Tab5[i]=Tab52[i+2];
    for(i=2;i<4;i++){
        Tab0[i-2]=Tab2[i+4];
        Tab2[i+4]=Tab6[i+2];
        Tab6[i+2]=Tab4[i];
        Tab4[i]=Tab1[i-2];
        Tab1[i-2]=Tab0[i-2];
    }
    Tab0[2]=Tab2[0];
    Tab2[0]=Tab6[6];
    Tab6[6]=Tab4[4];
    Tab4[4]=Tab1[2];
    Tab1[2]=Tab0[2];
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::D(){
    int i;
    Tab6[0]=Tab62[6];
    Tab6[1]=Tab62[7];
    for(i=2;i<8;i++)
        Tab6[i]=Tab62[i-2];
    for(i=4;i<7;i++){
        Tab0[i]=Tab5[i];
        Tab5[i]=Tab4[i];
        Tab4[i]=Tab3[i];
        Tab3[i]=Tab2[i];
        Tab2[i]=Tab0[i];
    }
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::d(){
    int i;
    Tab6[6]=Tab62[0];
    Tab6[7]=Tab62[1];
    for(int i=0;i<6;i++)
        Tab6[i]=Tab62[i+2];
    for(i=4;i<7;i++){
        Tab0[i]=Tab2[i];
        Tab2[i]=Tab3[i];
        Tab3[i]=Tab4[i];
        Tab4[i]=Tab5[i];
        Tab5[i]=Tab0[i];
    }
    for(i=0;i<8;i++){
        Tab12[i]=Tab1[i];
        Tab22[i]=Tab2[i];
        Tab32[i]=Tab3[i];
        Tab42[i]=Tab4[i];
        Tab52[i]=Tab5[i];
        Tab62[i]=Tab6[i];
    }
}

void Kostka::Wypisz(){
    printf("       %c %c %c\n       %c %c %c\n       %c %c %c\n\n",Tab1[0],Tab1[1],Tab1[2],Tab1[7],Tab1[8],Tab1[3],Tab1[6],Tab1[5],Tab1[4]);
    printf("%c %c %c  %c %c %c  %c %c %c  %c %c %c\n",Tab2[0],Tab2[1],Tab2[2],Tab3[0],Tab3[1],Tab3[2],Tab4[0],Tab4[1],Tab4[2],Tab5[0],Tab5[1],Tab5[2]);
    printf("%c %c %c  %c %c %c  %c %c %c  %c %c %c\n",Tab2[7],Tab2[8],Tab2[3],Tab3[7],Tab3[8],Tab3[3],Tab4[7],Tab4[8],Tab4[3],Tab5[7],Tab5[8],Tab5[3]);
    printf("%c %c %c  %c %c %c  %c %c %c  %c %c %c\n\n",Tab2[6],Tab2[5],Tab2[4],Tab3[6],Tab3[5],Tab3[4],Tab4[6],Tab4[5],Tab4[4],Tab5[6],Tab5[5],Tab5[4]);
    printf("       %c %c %c\n       %c %c %c\n       %c %c %c\n",Tab6[0],Tab6[1],Tab6[2],Tab6[7],Tab6[8],Tab6[3],Tab6[6],Tab6[5],Tab6[4]);
}

void Kostka::CzyUlozona(){
    if((Tab1[0]=='W') && (Tab1[1]=='W') && (Tab1[2]=='W') && (Tab1[3]=='W') && (Tab1[4]=='W') && (Tab1[5]=='W') && (Tab1[6]=='W') && (Tab1[7]=='W') && (Tab1[8]=='W') && (Tab2[0]=='R') && (Tab2[1]=='R') && (Tab2[2]=='R') && (Tab2[3]=='R') && (Tab2[4]=='R') && (Tab2[5]=='R') && (Tab2[6]=='R') && (Tab2[7]=='R') && (Tab2[8]=='R') && (Tab3[0]=='B') && (Tab3[1]=='B') && (Tab3[2]=='B') && (Tab3[3]=='B') && (Tab3[4]=='B') && (Tab3[5]=='B') && (Tab3[6]=='B') &&(Tab3[7]=='B') && (Tab3[8]=='B') && (Tab4[0]=='O') && (Tab4[1]=='O') && (Tab4[2]=='O') && (Tab4[3]=='O') && (Tab4[4]=='O') && (Tab4[5]=='O') && (Tab4[6]=='O') && (Tab4[7]=='O') && (Tab4[8]=='O') && (Tab5[0]=='G') && (Tab5[1]=='G') && (Tab5[2]=='G') && (Tab5[3]=='G') && (Tab5[4]=='G') && (Tab5[5]=='G') && (Tab5[6]=='G') && (Tab5[7]=='G') && (Tab5[8]=='G'))
        printf("Kostka ulozona.\n");
    else
        printf("Kostka nie jest ulozona.\n");
}

void Kostka::Ruch(char c){
    if(c=='U')
        U();
    else if(c=='u')
        u();
    else if(c=='L')
        L();
    else if(c=='l')
        l();
    else if(c=='F')
        F();
    else if(c=='f')
        f();
    else if(c=='R')
        R();
    else if(c=='r')
        r();
    else if(c=='B')
        B();
    else if(c=='b')
        b();
    else if(c=='D')
        D();
    else if(c=='d')
        d();
}
