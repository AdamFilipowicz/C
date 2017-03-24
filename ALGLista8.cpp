#include <iostream>
#include <cstddef>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(){
    srand(time(NULL));
    int a;
    long int qq;
    long double sumawag;
    for(int k=1;k<17;k++){
        sumawag=0;
        long tab[1<<k];
        for(int q=0;q<1000;q++){
            for(long j=0;j<(1<<k)-1;j++){
                tab[j]=INT_MAX;
            }
            tab[(1<<k)-1]=0;
            for(long i=(1<<k)-2;i>=0;i--){
                for(long j=i+1;j<(1<<k);j++){
                    qq=i^j;
                    for(int p=0;p<k;p++){
                        if(qq==(1<<p)){
                            a=(rand()%(2*k+1))-k;
                            if(tab[i]>tab[j]+a){
                                tab[i]=tab[j]+a;
                            }
                        }
                    }
                }
            }
            sumawag=sumawag+tab[0];
        }
        cout<<k<<endl<<sumawag/1000<<endl;
    }
    return 0;
}
