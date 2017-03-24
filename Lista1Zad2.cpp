#include<stdio.h>

void WypiszJutrzejszaDate(int dzien,int miesiac,int rok);

int main(){
    int dzien,miesiac,rok;
    WypiszJutrzejszaDate(dzien,miesiac,rok);
    return 0;
}

void WypiszJutrzejszaDate(int dzien,int miesiac,int rok){
    printf("Podaj rok\n");
    scanf("%d",&rok);
    if (rok>0){
        printf("Podaj miesiac\n");
        scanf("%d",&miesiac);
        if (miesiac>0 && miesiac<13){
            printf("Podaj dzien\n");
            scanf("%d",&dzien);
            if (miesiac==1 || miesiac==3 || miesiac==5 || miesiac==7 || miesiac==8 || miesiac==10){
                if (dzien>0 && dzien<31){
                    printf("Jutrzejsza data to: %d.%d.%d",dzien+1,miesiac,rok);
                }
                else{
                    if (dzien==31){
                        printf("Jutrzejsza data to: 1.%d.%d",miesiac+1,rok);
                    }
                    else{
                        printf("Data nieprawidlowa");
                    }
                }
            }
            else{
                if (miesiac==4 || miesiac==6 || miesiac==9 || miesiac==11){
                    if (dzien>0 && dzien<30){
                        printf("Jutrzejsza data to: %d.%d.%d",dzien+1,miesiac,rok);
                    }
                    else{
                        if (dzien==30){
                        printf("Jutrzejsza data to: 1.%d.%d",miesiac+1,rok);
                        }
                        else{
                        printf("Data nieprawidlowa");
                        }
                    }
                }
                else{
                    if (miesiac==12){
                        if (dzien>0 && dzien<31){
                            printf("Jutrzejsza data to: %d.%d.%d",dzien+1,miesiac,rok);
                        }
                        else{
                            if (dzien==31){
                                printf("Jutrzejsza data to: 1.1.%d",rok+1);
                            }
                            else{
                                printf("Data nieprawidlowa");
                            }
                        }
                    }
                    else{
                        if (rok%4==00 && (rok%100!=0 || rok%400==0)){
                            if (dzien>0 && dzien<29){
                                printf("Jutrzejsza data to: %d.2.%d",dzien+1,rok);
                            }
                            else{
                                if (dzien==29){
                                    printf("Jutrzejsza data to: 1.3.%d",rok);
                                }
                                else{
                                    printf("Data nieprawidlowa");
                                }
                            }
                        }
                        else{
                            if (dzien>0 && dzien<28){
                                printf("Jutrzejsza data to: %d.2.%d",dzien+1,rok);
                            }
                            else{
                                if (dzien==28){
                                    printf("Jutrzejsza data to: 1.3.%d",rok);
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
            printf("Data nieprawid³owa");
        }
    }
    else{
        printf("Data nieprawid³owa");
    }
}

