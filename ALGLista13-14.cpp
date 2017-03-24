#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits.h>
//Program liczący 2-aproksymację optymalnego cyklu komiwojażera z wagami krawędzi jako odległości taksówkowej.
using namespace std;

class UnionFind{
    private:
        int *set;
    public:
        UnionFind(int n){
            set=new int[n];
            for(int i=0;i<n;i++){
                set[i]=i;
            }
        };

        ~UnionFind(){delete []set;};

        int FindSet(int e){
            int l,h=e;
            while(e!=set[e]){
                e=set[e];
            }
            while(h!=set[h]){
                l=set[h];
                set[h]=e;
                h=l;
            }
            return e;
        };

        void Union(int x, int y){
            int k=FindSet(x);
            int l=FindSet(y);
            if(k!=l){
                if(k<l){
                    set[l]=k;
                }
                else{
                    set[k]=l;
                }
            }
        };

        bool Connected(int n){
            for(int i=1;i<n+1;i++){
                if(set[i]==i){
                    return false;
                }
            }
            return true;
        };
};

int main(){
    srand(time(NULL));
    long **G;
    long licznik=0,licznik2=0;
    int n,a,b,c,hh,licz,wyszlo,krawedzie=0,l,j;
    for(int k=10;k<11;k++){

        n=1<<k;
        int *tab=new int[n];
        long *tabx=new long[n];
        long *taby=new long[n];
        G=new long*[n];
        for(int i=0;i<(n);i++){
            G[i]=new long[n];
        }
        for(int q=0;q<1000;q++){
            vector<tuple<double,int,int>>tablica;
            vector<tuple<double,int,int>>las;
            krawedzie=0;
            for(int i=0;i<n;i++){
                tab[i]=-1;
            }
            UnionFind K(n);
            for(int i=0;i<n;i++){
                tabx[i]=rand();
                taby[i]=rand();
            }
            for(int i=0;i<(n-1);i++){
                for(int j=i+1;j<n;j++){
                    tablica.push_back(make_tuple(abs(tabx[i]-tabx[j])+abs(taby[i]-taby[j]),i,j));
                    G[i][j]=abs(tabx[i]-tabx[j])+abs(taby[i]-taby[j]);
                }
            }
            sort(tablica.begin(),tablica.end());
            hh=0;
            do{
                a=get<1>(tablica[hh]);
                b=get<2>(tablica[hh]);
                c=get<0>(tablica[hh]);
                if(K.FindSet(a)!=K.FindSet(b)){
                    K.Union(a,b);
                    las.push_back(make_tuple(c,a,b));
                    las.push_back(make_tuple(c,b,a));

                }
                hh++;
            }while(!K.Connected(n));
            tab[get<2>(las[0])]=get<1>(las[0]);
            licz=get<2>(las[0]);
            get<1>(las[0])=-1;
            get<1>(las[1])=-1;
            do{
                wyszlo=0;
                for(int i=0;i<las.size();i++){
                    l=get<1>(las[i]);
                    if(l==licz){
                        j=get<2>(las[i]);
                        tab[j]=licz;
                        licz=j;
                        if(l>j){
                            get<1>(las[i])=-1;
                            get<1>(las[i-1])=-1;
                        }
                        else{
                            get<1>(las[i])=-1;
                            get<1>(las[i+1])=-1;
                        }
                        wyszlo=1;
                        break;
                    }
                }
                if(wyszlo==0){
                    if(licz<tab[licz]){
                        licznik=licznik+G[licz][tab[licz]];
                    }
                    else{
                        licznik=licznik+G[tab[licz]][licz];
                    }
                    licz=tab[licz];
                    krawedzie++;
                }
            }while(krawedzie!=n-1);
            cout<<q<<' ';
            las.erase(las.begin(),las.end());
            tablica.erase(tablica.begin(),tablica.end());
            if(licznik==500){
                licznik2=licznik;
                licznik=0;
            }
        }
        long double lili=licznik/1000+licznik2/1000;
        cout<<k<<endl<<lili<<endl<<"Srednia dlugosc/RAND_MAX= "<<lili/RAND_MAX;
        for(int i=0;i<n;i++){
            delete []G[i];
        }
        delete []tabx;
        delete []taby;
        delete []tab;
    }
    delete []*G;
    return 0;
}
