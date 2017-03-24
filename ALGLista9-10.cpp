#include <iostream>
#include <cstddef>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    srand(time(NULL));
    long qq,qqq,licz,licznik,licznik2;
    int koniec;
    long blad;
    long double minimum;
    long double przeplyw;
    long double liczbasciezek;
    long liczbasciezek2;
    int zapamietaj;
    for(int k=1;k<17;k++){
        long tablica[(1<<k)];
        queue <long> kolejka;
        przeplyw=0;
        liczbasciezek=0;
        licznik=(1<<k);
        licznik2=(1<<k);
        long double **G;
        G=new long double*[1<<k];
        for(long i=0;i<(1<<k);i++){
            G[i]=new long double[k];
        }
        for(int q=0;q<1000;q++){
            for(long w=0;w<kolejka.size();w++){
                kolejka.pop();
            }
            for(long w=0;w<(1<<k);w++){
                tablica[w]=-1;
            }
            blad=0;
            koniec=0;
            minimum=2.0;
            liczbasciezek2=0;
            for(long i=0;i<(1<<k);i++){
                for(int j=0;j<k;j++){
                    qq=i^(1<<j);
                    if(qq>i){
                        G[i][j]=1.0*rand()/RAND_MAX;
                    }
                    else{
                        G[i][j]=0;
                    }
                }
            }
            do{
                for(long w=0;w<kolejka.size();w++){  //while( !kolejka.empty() ) kolejka.pop();
                    kolejka.pop();
                }
                for(long w=0;w<(1<<k);w++){
                    tablica[w]=-1;
                }
                kolejka.push(0);
                minimum=2.0;
                koniec=0;
                blad=0;
                licznik=(1<<k)-1;
                licznik2=(1<<k)-1;
                while(tablica[(1<<k)-1]==-1 && !kolejka.empty()){
                    licz=kolejka.front();
                    for(int j=0;j<k;j++){
                        if(G[licz][j]!=0){
                            qqq=licz^(1<<j);
                            if(tablica[qqq]==-1){
                                kolejka.push(qqq);
                                tablica[qqq]=licz;
                            }
                        }
                    }
                    kolejka.pop();
                }
                for(long w=0;w<kolejka.size();w++){
                    kolejka.pop();
                }
                if(tablica[(1<<k)-1]!=-1){
                    for(long j=0;j<(1<<k);j++){
                        if(tablica[j]==(1<<k)-1){
                            licznik=0;
                            licznik2=0;
                            koniec=1;
                            minimum=0;
                        }
                    }
                    /*for(int j=0;j<(1<<k);j++){
                            cout<< tablica[j]<<' ';
                        }
                    cout<<endl;*/
                    while(licznik!=0){
                        blad++;
                        if(blad>2*(1<<k)){
                            licznik2=0;
                            koniec=1;
                            minimum=0;
                            break;
                        }
                        for(int j=0;j<k;j++){
                            if((1<<j)==abs(licznik-tablica[licznik])){
                                zapamietaj=j;
                            }
                        }
                        if(G[tablica[licznik]][zapamietaj]<minimum){
                            minimum=G[tablica[licznik]][zapamietaj];
                        }
                        licznik=tablica[licznik];
                    }
                    blad=0;
                    while(licznik2!=0){
                        for(int j=0;j<k;j++){
                            if((1<<j)==abs(licznik2-tablica[licznik2])){
                                zapamietaj=j;
                            }
                        }
                        G[tablica[licznik2]][zapamietaj]=G[tablica[licznik2]][zapamietaj]-minimum;
                        G[licznik2][zapamietaj]=G[licznik2][zapamietaj]+minimum;
                        licznik2=tablica[licznik2];
                    }
                    przeplyw=przeplyw+minimum;
                    liczbasciezek++;
                    liczbasciezek2++;
                    for(long w=0;w<(1<<k);w++){
                        tablica[w]=-1;
                    }
                    for(long w=0;w<kolejka.size();w++){
                        kolejka.pop();
                    }
                }
                else{
                    koniec=1;
                }
                if(liczbasciezek2>=2*(1<<k)){
                    koniec=1;
                }
                if(minimum==0){
                    koniec=1;
                }
                for(long w=0;w<kolejka.size();w++){
                    kolejka.pop();
                }
                for(long w=0;w<(1<<k);w++){
                    tablica[w]=-1;
                }
            }while(koniec==0);
        }
        cout<<k<<endl<<"Srednia liczba sciezek: "<<(liczbasciezek/1000)<<endl<<"Sredni przeplyw: "<<(przeplyw/1000)<<endl;
        for(long i=0;i<(1<<k);i++){
            delete []G[i];
        }
        delete []*G;
    }
    return 0;
}
