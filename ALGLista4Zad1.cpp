#include <cstddef>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

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
            if(first==NULL) first = last = new Element( e );
            else{
                Element* item = first;
                Element* insert = new Element( e );
                if(insert ->getValue() < item ->getValue() ){
                        item ->setPrev(insert);
                        first = item ->getPrev();
                        first ->setNext(item);
                }
                else{
                    item=item->getNext();
                    while(item != NULL) {
                        if(insert ->getValue() > item ->getValue ()){
                            item = item ->getNext ();
                        }
                        else{
                            m++;
                            break;
                        }
                        m++;
                    }
                    if(item != NULL){
                        insert ->setNext(item);
                        insert ->setPrev(item ->getPrev());
                        item ->getPrev() ->setNext(insert);
                        item ->setPrev(insert);
                    }
                    else{
                        item=last;
                        last ->setNext(insert);
                        last = last ->getNext();
                        last ->setPrev(item);
                    }
                }
                m++;
            }
        }

        int min () {
            m=0;
            Element* min = first;
            int value = min ->getValue ();
            first = first ->getNext();
            delete  min;
            return  value ;
        }
   };

int main( int argc , char* argv  []) {
    int ilosc=0;
    int o=8;
    int tab[o];
    int minimalny=100,maksymalny=0,sredni=0;
    Queue k;
    for(int i=0;i<o;i++){
        tab[i]=i+1;
    }
    int licznik=0;
    int poi=0;
    do{
        poi++;
        ilosc++;
        for(int i=0;i<o;i++){
            k.insert(tab[i]);
        }
        if(k.getCounter()>maksymalny){
            maksymalny=k.getCounter();
        }
        if(k.getCounter()<minimalny){
            minimalny=k.getCounter();
        }
        sredni=sredni+k.getCounter();
        while ( !k.empty() ) k.min();
    }while(next_permutation(tab,tab+o));
    cout<<sredni/ilosc<<endl<<maksymalny<<endl<<minimalny<<endl;
    return 0;
}
