#include <iostream>
#include <cstddef>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
//Program bada spójność grafu nieskierowanego o rozmiarze n.
using namespace std;

class UnionFind{
    private:
        int *set;
        int licznik=0;
        int licznik2=0;
    public:
        UnionFind(int n){
            set=new int[n];
            for(int i=0;i<n;i++){
                set[i]=i;
            }
        };

        ~UnionFind(){delete []set;};

        inline int GetCounter(){
            licznik2=licznik;
            licznik=0;
            return licznik2;}

        int FindSet(int e){
            int h=e;
            while(e!=set[e]){
                e=set[e];
            }
            while(h!=set[h]){
                int l=set[h];
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
        bool Connected(int n, bool **G){
            for(int i=0;i<n;i++){
                set[i]=i;
            }
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(G[i][j]){
                        Union(i,j);
                    }
                }
            }
            for(int i=1;i<n;i++){
                if(set[i]==i){
                    return false;
                }
            }
            licznik++;
            return true;
        };
};

int main(){
    srand(time(NULL));
    int n=pow(2,8);
    int p,w;
    UnionFind K(n);
    bool **G;
    G=new bool*[n];
    for(int i=0;i<n;i++){
        G[i]=new bool[n];
    }
    for(int t=0;t<10;t++){
        int pp=pow(2,t);
        w=RAND_MAX/pp;
        for(int s=0;s<1000;s++){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    G[i][j]=w>rand();
                }
            }
            K.Connected(n,G);
        }
        cout<<K.GetCounter()<<endl;
    }
    for(int i=0;i<n;i++){
        delete []G[i];
    }
    delete []*G;
}
