#include <iostream>
#include <cstddef>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <vector>
#include <tuple>
#include <algorithm>
//Algorytm Kruskala wyznaczania minimalnego drzewa rozpinającego użyty na grafach losowych.
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
    int m,w,licznik,n,aa,bb;
    float srednia,srednia2;
    for(int k=1;k<8;k++){
        srednia=0;
        licznik=0;
        vector<tuple<double,int,int>>tablica;
        n=pow(2,k);
        m=n/k;
        w=(RAND_MAX/m);
        for(int s=0;s<1000;s++){
            UnionFind K(n);
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(w>rand()){
                        tablica.push_back(make_tuple((1.0*rand())/RAND_MAX,i,j));
                    }
                }
            }
            sort(tablica.begin(),tablica.end());
            srednia2=0;
            for(int i=0;i<tablica.size();i++){
                int aa= get<1>(tablica[i]);
                int bb= get<2>(tablica[i]);
                if(K.FindSet(aa)!=K.FindSet(bb)){
                    K.Union(aa,bb);
                    srednia2=srednia2+get<0>(tablica[i]);
                }
            }
            tablica.erase(tablica.begin(),tablica.end());
            if(K.Connected(n)){
                licznik++;
                srednia=srednia+srednia2;
            }
        }
        cout<<k<<endl<<"Licznik: "<<licznik<<endl<<"Srednia: "<<srednia/licznik<<endl;
    }
    return 0;
}
