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
    bool **przepustowosc;
    bool losowa;
    int qq;
    long double skojarzenie;
    for(int k=3;k<11;k++){
        bool tablica[1<<(k+1)];
        przepustowosc=new bool*[1<<(k+1)];
        for(int i=0;i<1<<(k+1);i++){
            przepustowosc[i]=new bool[1<<(k+1)];
        }
        for(int i=0;i<1<<(k+1);i++){
            for(int j=0;j<1<<(k+1);j++){
                przepustowosc[i][j]=0;
            }
        }
        for(int i=0;i<k+1;i++){
            skojarzenie=0;
            for(int q=0;q<1000;q++){
                for(int p=0;p<1<<(k+1);p++){
                    tablica[p]=1;
                }
                qq=1<<i;
                for(int w=0;w<1<<k;w++){
                    for(int e=1<<k;e<1<<(k+1);e++){
                        losowa=rand()%qq;
                        przepustowosc[w][e]=losowa;
                        if(!przepustowosc[w][e]){
                            if(tablica[e]!=0){
                                tablica[e]=0;
                                skojarzenie++;
                                break;
                            }
                        }
                    }
                }
            }
            cout<<k<<endl<<i<<endl<<skojarzenie/1000<<endl;
        }
        for(int i=0;i<(1<<(k+1))+2;i++){
            delete []przepustowosc[i];
        }
    }
    delete []*przepustowosc;
    return 0;
}
