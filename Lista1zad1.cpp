#include<stdio.h>

void CzyPoprawnaData(int dzien,int miesiac,int rok);

int main(){
    int dzien,miesiac,rok;
    CzyPoprawnaData(dzien,miesiac,rok);
    return 0;
}

void CzyPoprawnaData(int dzien,int miesiac,int rok){
    printf("Podaj rok\n");
    scanf("%d",&rok);
    if (rok>0){
        printf("Podaj miesiac\n");
        scanf("%d",&miesiac);
        if (miesiac>0 && miesiac<13){
            printf("Podaj dzien\n");
            scanf("%d",&dzien);
            if (miesiac==1 || miesiac==3 || miesiac==5 || miesiac==7 || miesiac==8 || miesiac==10 || miesiac==12){
                if (dzien>0 && dzien<32){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
            else{
                if (miesiac==4 || miesiac==6 || miesiac==9 || miesiac==11){
                    if (dzien>0 && dzien<31){
                        printf("1");
                    }
                    else{
                        printf("0");
                    }
                }
                else{
                    if (rok%4==00 && (rok%100!=0 || rok%400==0)){
                        if (dzien>0 && dzien<30){
                            printf("1");
                        }
                        else{
                            printf("0");
                        }
                    }
                    else{
                        if (dzien>0 && dzien<29){
                            printf("1");
                        }
                        else{
                            printf("0");
                        }
                    }
                }
            }
        }
        else{
            printf("0");
        }
    }
    else{
        printf("0");
    }
}
