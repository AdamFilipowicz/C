#include <iostream>
#include <stdio.h>
#define MAX 3

using namespace std;

struct Data{int dzien;int miesiac;int rok;};
Data tab[MAX];

int main(){
    Data tab[MAX];
    for(int i=0;i<MAX;i++){
        tab[i-1].dzien=0;
        tab[i-1].miesiac=0;
        tab[i-1].rok=0;
    }
    for(int i=0;i<MAX;i++){
        printf("Podaj dzien\n");
        scanf("%d",&tab[i-1].dzien);
        printf("Podaj miesiac\n");
        scanf("%d",&tab[i-1].miesiac);
        printf("Podaj rok\n");
        scanf("%d",&tab[i-1].rok);
    }
    printf("Podane daty:\n");
    for(int i=0;i<MAX;i++){
        printf("%d.%d.%d  ",tab[i-1].dzien,tab[i-1].miesiac,tab[i-1].rok);
    }
    for(int i=0;i<MAX;i++){
        if (tab[i-1].rok>0){
            if (tab[i-1].miesiac>0 && tab[i-1].miesiac<13){
                if (tab[i-1].miesiac==1 || tab[i-1].miesiac==3 || tab[i-1].miesiac==5 || tab[i-1].miesiac==7 || tab[i-1].miesiac==8 || tab[i-1].miesiac==10 || tab[i-1].miesiac==12){
                    if (tab[i-1].dzien>0 && tab[i-1].dzien<32){
                        printf("Najwczeœniejsza poprawna data to: %d.%d.%d",tab[i-1].dzien,tab[i-1].miesiac,tab[i-1].rok);
                        return 1;
                    }
                }

                else{
                    if (tab[i-1].miesiac==4 || tab[i-1].miesiac==6 || tab[i-1].miesiac==9 || tab[i-1].miesiac==11){
                        if (tab[i-1].dzien>0 && tab[i-1].dzien<31){
                            printf("Najwczeœniejsza poprawna data to: %d.%d.%d",tab[i-1].dzien,tab[i-1].miesiac,tab[i-1].rok);
                            return 1;
                        }
                    }
                    else{
                        if (tab[i-1].rok%4==00 && (tab[i-1].rok%100!=0 || tab[i-1].rok%400==0)){
                                if (tab[i-1].dzien>0 && tab[i-1].dzien<30){
                                    printf("Najwczeœniejsza poprawna data to: %d.2.%d",tab[i-1].dzien,tab[i-1].rok);
                                    return 1;
                                }
                        }
                        else{
                            if (tab[i-1].dzien>0 && tab[i-1].dzien<29){
                                printf("Najwczeœniejsza poprawna data to: %d.2.%d",tab[i-1].dzien,tab[i-1].rok);
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
