#include <iostream>
#include <cstddef>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Heap {
    private:
        int* heap;
        int size;
    public:
        Heap(int size){heap=new int[size]; this->size=1;};

        ~Heap(){delete []heap;};

        
	
	inline int pokaz(int i){return heap[i];}

        inline bool empty(){return heap[0]==0;};

        void push(int e){
            heap[size-1]=e;
            int miejsce=size;
            int koniec=0;
            if(miejsce!=1){
                while(heap[miejsce-1]<heap[(miejsce/2)-1] && koniec==0){
                    swap(heap[miejsce-1],heap[(miejsce/2)-1]);
                    miejsce=miejsce/2;
                    if(miejsce==1){
                        koniec=1;
                    }
                }
            }
            size++;
        };

        int min(){
            size--;
            int h=heap[0];
            heap[0]=0;
            int miejsce2=1;
            while((miejsce2*2)<=size){
                if(miejsce2*2==size){
                    heap[miejsce2-1]=heap[size-1];
                    heap[size-1]=0;
                    miejsce2=2*miejsce2;
                }
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
                if((miejsce2*2)>size && (miejsce2+1)<=size){
                    heap[miejsce2-1]=heap[size-1];
                    heap[size-1]=0;
                    int koniec=0;
                    int pomocnicza=miejsce2;
                    if(miejsce2!=1){
                        while(heap[miejsce2-1]<heap[(miejsce2/2)-1] && koniec==0){
                            swap(heap[miejsce2-1],heap[(miejsce2/2)-1]);
                            miejsce2=miejsce2/2;
                            if(miejsce2==1){
                                koniec=1;
                            }
                        }
                    }
                    miejsce2=pomocnicza;
                }
            }
            return h;
        };
};

int main(){
    int p=30;
    Heap K(p);
    int tab[p];
    srand(time(NULL));
    for(int i = 0; i < p; i++){
        tab[i]=0;
    }
    for(int i = 0; i < p; i++) {
        tab[i]=rand()%p+1;
        for(int j=0;j<i;j++){
            if(tab[i]==tab[j]){
                tab[i]=0;
                i--;
            }
        }
    }
    for(int i = 0; i < p; i++){
        K.push(tab[i]);
    }
    for(int i = 0; i < p; i++){
        cout<<K.pokaz(i);
    }
    cout<<endl;
    while(!K.empty()){
        cout<<K.min()<<endl;
    }
    return 0;
}
