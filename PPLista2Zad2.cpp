#include <stdio.h>
#include <math.h>

struct Trojmian{float a;float b;float c;};
struct MZerowe{int IloscMiejscZerowych;float x0;float x1;float x2;};
MZerowe MiejscaZerowe(Trojmian A);
void WypiszMiejscaZerowe(MZerowe Y);

int main(){
    Trojmian A;
    printf("Podaj wspolczynniki trojmianu:\n");
    printf("wpisz a: "), scanf("%f",&A.a);
    printf("wpisz b: "), scanf("%f",&A.b);
    printf("wpisz c: "), scanf("%f",&A.c);
    WypiszMiejscaZerowe(MiejscaZerowe(A));
}

MZerowe MiejscaZerowe(Trojmian A){
  MZerowe X;
  if (A.b==0){
    if(A.a==0){
        if(A.c==0){
            X.IloscMiejscZerowych=100;
        }
        else{
            X.IloscMiejscZerowych=0;   //brak rozwiazan
        }
    }
    else{
        if ((-A.c/A.a)<0){
            X.IloscMiejscZerowych=0;
        }
        else if((-A.c/A.a)==0){
            X.x0=0;
            X.IloscMiejscZerowych=1; // 1 m zer
        }
        else{
            X.x1=sqrtf(-A.c/A.a);
            X.x2=-(sqrtf(-A.c/A.a));
            X.IloscMiejscZerowych=2;  //2 m zer
        }
    }
  }
  else{
      int delta=A.b*A.b-4*A.a*A.c;
      if (delta<0){
        X.IloscMiejscZerowych=0;
      }
      else if (delta==0){
        X.x0=-A.b/(2*A.a);
        X.IloscMiejscZerowych=1;
      }
      else if (A.a==0){
        X.x0=-A.c/A.b;
        X.IloscMiejscZerowych=1;
      }
      else{
        X.x1=((-A.b-(sqrtf(delta)))/(2*A.a));
        X.x2=((-A.b+(sqrtf(delta)))/(2*A.a));
        X.IloscMiejscZerowych=2;
    }
  }
  return X;
}

void WypiszMiejscaZerowe(MZerowe Y){
    printf("Ilosc miejsc zerowych: %d\n",Y.IloscMiejscZerowych);
    if(Y.IloscMiejscZerowych==0){
        printf("Brak miejsc zerowych");
    }
    if(Y.IloscMiejscZerowych==1){
        printf("Wynosi ono %lf",Y.x0);
    }
    if(Y.IloscMiejscZerowych==2){
        printf("Wynosza one %lf i %lf",Y.x1,Y.x2);
    }
    if(Y.IloscMiejscZerowych==100){
        printf("Nieskonczenie wiele pierwiastkow");
    }
}

