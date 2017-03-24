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
             Element* tmp = last ;
             tmp ->setNext(new  Element( e ) );
             last = tmp ->getNext ();
             last ->setPrev( tmp );
          }
        }

        int min () {
           Element* min = first;
           Element* item = first ->getNext ();
           while( item != NULL ) {
             if( min ->getValue () > item ->getValue () ) min = item;
             item = item ->getNext ();
             m++;
          }
          int value = min ->getValue ();
          if ( min == first ) {
             first = first ->getNext ();
             if( first  != NULL ) first ->setPrev( NULL );
          }
          else min ->getPrev()->setNext( min ->getNext () );
          if( min == last ) {
             last = last ->getPrev ();
             if ( last != NULL ) last ->setNext( NULL );
          }
          else min ->getNext()->setPrev( min ->getPrev () );
           delete  min;
           return  value ;
        }
   };

   int main( int argc , char* argv  []) {
       int tab[10];
        srand(time(NULL));
        Queue k;
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
        cout<<k.getCounter();
        return 0;
}
