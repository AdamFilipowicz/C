#include <iostream>
#include <cstddef>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
//Zadanie jak w Zad1 dla Kopca
using namespace std;

class Heap {
    private:
        int m=0;
        int* heap;
        int size;
    public:
        Heap(int size){heap=new int[size]; this->size=1;};

        ~Heap(){delete []heap;};

        void zeruj(){m=0;}

        void sajz(){size=1;}

        inline bool empty(){return heap[0]==0;};

        inline int getCounter(){return m;}

        void push(int e){
            heap[size-1]=e;
            int miejsce=size;
            if (miejsce==1){}
            else{
                while(heap[miejsce-1]<heap[(miejsce/2)-1] && miejsce!=1){
                    swap(heap[miejsce-1],heap[(miejsce/2)-1]);
                    miejsce=miejsce/2;
                    m++;
                }
                m++;
            }
            size++;
        };

        int min(){
            size--;
            int h=heap[0];
            heap[0]=0;
            int miejsce2=1;
            while((miejsce2*2)<size){
                m++;
                if(heap[(2*miejsce2)-1]<heap[2*miejsce2]){
                    heap[miejsce2-1]=heap[(2*miejsce2)-1];
                    heap[(2*miejsce2)-1]=0;
                    miejsce2=2*miejsce2;
                }
                else{
                    heap[miejsce2-1]=heap[2*miejsce2];
                    heap[2*miejsce2]=0;
                    miejsce2=(2*miejsce2)+1;
                }
                m++;
            }
            m++;
            heap[miejsce2-1]=heap[size-1];
            heap[size-1]=0;
            while(heap[miejsce2-1]<heap[(miejsce2/2)-1] && miejsce2!=1){
                if(heap[miejsce2-1]!=0){
                    swap(heap[miejsce2-1],heap[(miejsce2/2)-1]);
                    m++;
                }
                miejsce2=miejsce2/2;
                m++;
            }
            m++;
            return h;
        };
};

int main(){
    int p=8;
    Heap K(p);
    int tab[p];
    int maksymalny2=0,minimalny2=100,sredni2=0;
    int ilosc=0;
    for(int i = 0; i < p; i++){
        tab[i]=i+1;
    }
    int licznik=0;
    int poi=0;
    do{
        poi++;
        K.sajz();
        K.zeruj();
        ilosc++;
        for(int i = 0; i < p; i++){
            K.push(tab[i]);
        }
        while(!K.empty()){
            K.min();
        }
        if(K.getCounter()>maksymalny2){
            maksymalny2=K.getCounter();
        }
        if(K.getCounter()<minimalny2){
            minimalny2=K.getCounter();
        }
        sredni2=sredni2+K.getCounter();
    }while(next_permutation(tab,tab+p));
    cout<<maksymalny2<<endl<<minimalny2<<endl<<sredni2/ilosc;
    return 0;
}
