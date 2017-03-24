#include <stdio.h>

struct Data{int dzien; int miesiac; int rok;};
void Wypisz(Data B);
void WypiszJutrzejszaDate(Data B);

int main(){
    Data A;
    printf("Podaj dzien\n");
    scanf("%d",&A.dzien);
    printf("Podaj miesiac\n");
    scanf("%d",&A.miesiac);
    printf("Podaj rok\n");
    scanf("%d",&A.rok);
    Wypisz(A);
    WypiszJutrzejszaDate(A);
    return 0;
}

void Wypisz(Data B){
    printf("Podana data: %d.%d.%d\n",B.dzien,B.miesiac,B.rok);
}

void WypiszJutrzejszaDate(Data B){
    if (B.rok>0){
        if (B.miesiac>0 && B.miesiac<13){
            if (B.miesiac==1 || B.miesiac==3 || B.miesiac==5 || B.miesiac==7 || B.miesiac==8 || B.miesiac==10){
                if (B.dzien>0 && B.dzien<31){
                    printf("Jutrzejsza data to: %d.%d.%d",B.dzien+1,B.miesiac,B.rok);
                }
                else{
                    if (B.dzien==31){
                        printf("Jutrzejsza data to: 1.%d.%d",B.miesiac+1,B.rok);
                    }
                    else{
                        printf("Data nieprawidlowa");
                    }
                }
            }
            else{
                if (B.miesiac==4 || B.miesiac==6 || B.miesiac==9 || B.miesiac==11){
                    if (B.dzien>0 && B.dzien<30){
                        printf("Jutrzejsza data to: %d.%d.%d",B.dzien+1,B.miesiac,B.rok);
                    }
                    else{
                        if (B.dzien==30){
                        printf("Jutrzejsza data to: 1.%d.%d",B.miesiac+1,B.rok);
                        }
                        else{
                        printf("Data nieprawidlowa");
                        }
                    }
                }
                else{
                    if (B.miesiac==12){
                        if (B.dzien>0 && B.dzien<31){
                            printf("Jutrzejsza data to: %d.%d.%d",B.dzien+1,B.miesiac,B.rok);
                        }
                        else{
                            if (B.dzien==31){
                                printf("Jutrzejsza data to: 1.1.%d",B.rok+1);
                            }
                            else{
                                printf("Data nieprawidlowa");
                            }
                        }
                    }
                    else{
                        if (B.rok%4==00 && (B.rok%100!=0 || B.rok%400==0)){
                            if (B.dzien>0 && B.dzien<29){
                                printf("Jutrzejsza data to: %d.2.%d",B.dzien+1,B.rok);
                            }
                            else{
                                if (B.dzien==29){
                                    printf("Jutrzejsza data to: 1.3.%d",B.rok);
                                }
                                else{
                                    printf("Data nieprawidlowa");
                                }
                            }
                        }
                        else{
                            if (B.dzien>0 && B.dzien<28){
                                printf("Jutrzejsza data to: %d.2.%d",B.dzien+1,B.rok);
                            }
                            else{
                                if (B.dzien==28){
                                    printf("Jutrzejsza data to: 1.3.%d",B.rok);
                                }
                                else{
                                    printf("Data nieprawidlowa");
                                }
                            }
                        }
                    }
                }
            }
        }
        else{
            printf("Data nieprawidlowa");
        }
    }
    else{
        printf("Data nieprawidlowa");
    }
}
