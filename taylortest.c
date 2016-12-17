#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int fact (int num){
    int f = 0;
    if (num == 1)
        return 1;
    else
        f =num * fact(num-1);
    return f;
}
double Taylorsine(double x, int m){
    int i;
    double taylor;
    for(i=0; i<=m; i++){
        taylor += pow(-1, (i+1))*pow(x, 2i+1)/fact(2i+1);
    }
    return taylor; 
}

int main(){
    int n;
    double dx;
    double tol;
    double interval;
    
    printf("aralik sayısını belirleyiniz:\n");
    scanf("%d",&n);
    interval = (PI/2)/n;
    printf ("aralık uzunlugu:%lf\n",interval);
    printf("hata toleransını giriniz: \n");
    scanf("%lf",&tol);
    double taylor;
    
    for(dx= -PI/4; dx<= PI/4; dx = dx + interval){
        printf("dx: %lf \n", dx);
        double val=PI/180;
        double deger=sin(dx*val);
        printf("sin(dx) degeri: %lf \n",deger);
        
        printf("sinus fonksiyonunun taylor degeri:%lf\n",Taylorsine(dx, n));
        taylor =Taylorsine(dx, n)-sin(dx);
      
        while (taylor < tol)
            printf("error degeri:%lf\n",taylor++);   
    }  
    return 0;
}
