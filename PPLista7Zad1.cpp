#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Klasa.h"
using namespace std;

int main(){
    char nazwa;
    char *NazwaPliku=new char;
    cout<<"Wpisz 'd', jesli chcesz uzyc domyslnej kostki, lub cokolwiek innego, by zadac wlasny plik)\n";
    cin>>nazwa;
    if(nazwa=='d'){
        int koniec;
        char wybor;
        Kostka T;
        koniec=0;
        while(koniec!=1){
            T.Wypisz();
            T.CzyUlozona();
            cout<<"KOSTKA RUBIKA\n"<<"Wybierz metode: U u L l F f R r B b D d\n"<<"K - Zakoncz gre\n"<<"W - Wyprobuj metode 'Wymieszaj'\n"<<"Z - Wyprobuj metode 'Uloz'\n";
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
                case('W'):{
                    T.Wymieszaj();
                    break;
                }
                case('Z'):{
                    int n2;
                    cout<<"Podaj ilosc maksymalnych ruchow ulozenia kostki\n";
                    cin>>n2;
                    T.Uloz(n2);
                    printf("\n");
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
    else{
        NazwaPliku="C:\\Adam\\Informatyka\\C++\\KostkidoListy7Zad1\\Kostka3_1.txt";
        Kostka U(NazwaPliku);
        int koniec;
        char wybor;
        koniec=0;
        while(koniec!=1){
            U.Wypisz();
            U.CzyUlozona();
            cout<<"KOSTKA RUBIKA\n"<<"Wybierz metode: U u L l F f R r B b D d\n"<<"K - Zakoncz gre\n"<<"W - Wyprobuj metode 'Wymieszaj'\n"<<"Z - Wyprobuj metode 'Uloz'\n";
            cin>>wybor;
            switch(wybor){
                case('U'):{
                    U.U();
                    break;
                }
                case('u'):{
                    U.u();
                    break;
                }
                case('L'):{
                    U.L();
                    break;
                }
                case('l'):{
                    U.l();
                    break;
                }
                case('F'):{
                    U.F();
                    break;
                }
                case('f'):{
                    U.f();
                    break;
                }
                case('R'):{
                    U.R();
                    break;
                }
                case('r'):{
                    U.r();
                    break;
                }
                case('B'):{
                    U.B();
                    break;
                }
                case('b'):{
                    U.b();
                    break;
                }
                case('D'):{
                    U.D();
                    break;
                }
                case('d'):{
                    U.d();
                    break;
                }
                case('K'):{
                    cout<<"Koniec gry";
                    koniec=1;
                    break;
                }
                case('W'):{
                    U.Wymieszaj();
                    break;
                }
                case('Z'):{
                    int n2;
                    cout<<"Podaj ilosc maksymalnych ruchow ulozenia kostki\n";
                    cin>>n2;
                    U.Uloz(n2);
                    printf("\n");
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
    delete NazwaPliku;
    return 0;
}
