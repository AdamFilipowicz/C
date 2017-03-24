#include <cstddef>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace  std;

class Element {
      private:
int value;
        Element* next;
        Element* prev;
      public:
        Element (int v ) { value = v; next = prev = NULL; }
        inline int getValue () { return value; }
        inline Element* getNext () { return next; }
        inline  Element* getPrev () { return  prev; }
        inline void  setNext( Element* n ) { next = n; }
        inline void  setPrev( Element* n ) { prev = n; }
   };

   class Queue {
      private:
        int m=0;
        Element* first;
        Element* last;
      public:
        Queue () { first = last = NULL; }

        ~Queue () {
           while( first  != NULL ) {
             last = first ->getNext ();
             delete  first;
             first = last;
          };
        }
        inline bool empty () { return first  == NULL; }

        inline int getCounter(){return m;}

        void  insert(int e ) {
            if( first  == NULL ) first = last = new Element( e );
            else{
                Element* item = first ->getNext();
                Element* insert = new Element( e );
                while( item != NULL && insert ->getValue() > item ->getValue () ) {
                    item = item ->getNext ();
                    m++;
                }
                m++;
                if(item != NULL && insert->getValue() > first ->getValue()){
                    insert ->setNext(item);
                    insert ->setPrev(item ->getPrev());
                    item ->getPrev() ->setNext(insert);
                    item ->setPrev(insert);
                }
                else if(first==last){
                    item = first;
                    if(insert ->getValue() > item ->getValue() ){
                        item ->setNext(insert);
                        last = item ->getNext();
                        last ->setPrev(item);
                    }
                    else{
                        item ->setPrev(insert);
                        first = item ->getPrev();
                        first ->setNext(item);
                    }
                    m++;
                }
                else{
                    if(insert ->getValue() < first ->getValue()){
                        item=first;
                        first ->setPrev(insert);
                        first = first ->getPrev();
                        first ->setNext(item);
                    }
                    else{
                        item=last;
                        last ->setNext(insert);
                        last = last ->getNext();
                        last ->setPrev(item);
                    }
                    m++;
                }
            }
        }

        int min () {
            Element* min = first;
            int value = min ->getValue ();
            first = first ->getNext();
            delete  min;
            return  value ;
        }
   };

int main( int argc , char* argv  []) {
    int tab[10];
    srand(time(NULL));
    Queue k;
    for(int i=0;i<100;i++){
        for(int i = 0; i < 10; i++){
            tab[i]=0;
        }
        for(int i = 0; i < 10; i++) {
            tab[i]=rand()%10+1;
            for(int j=0;j<i;j++){
                if(tab[i]==tab[j]){
                    tab[i]=0;
                    i--;
                }
            }
        }
        for(int i = 0; i < 10; i++){
            k.insert(tab[i]);
        }
        while ( !k.empty() ) cout  << k.min() << endl ;
    }
    cout<<k.getCounter()/100;
    return 0;
}
