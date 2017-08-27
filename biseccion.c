#include <stdio.h>
#include <math.h>

int main () {
    int i=0;
    float a, b, xm, fa, fb, fxm, fxma, sg, er=0;
    printf("F(x)=x²-cos(x)-1\n");
    printf("Ingrese el valor minimo del rango: ");
    scanf("%f",&a);
    printf("Ingrese el valor maximo del rango: ");
    scanf("%f",&b);
    if(b<a) {
        b = b + a;
        a = b - a;
        b = b - a;
    }
    printf("minimo: %.1f\tmaximo: %.1f\n",a,b);
    printf("|i|  a   |   b  |  xmi |  f(a) | f(b)  | f(xmi) |f(a)·f(xmi)    |Er\n");
    do {
    xm = (b + a) / 2;
    fa = (powf(a,2.0)) - (cosf(a)) - 1;
    fb = (powf(b,2.0)) - (cosf(b)) - 1;
    fxm = (powf(xm,2.0)) - (cosf(xm)) - 1;
    sg = fa*fxm;
    printf("|%d|%.4f|%.4f|%.4f|%.4f|%.4f|%.4f\t|%f\t|%.5f\n",i,a,b,xm,fa,fb,fxm,sg,er);
    i++;
    if (sg>0){
        a = xm;
        xm = (b + a) / 2;
        fxma = (powf(xm,2.0)) - (cosf(xm)) - 1;  
    }else{
        b = xm;
        xm = (b + a) / 2;
        fxma = (powf(xm,2.0)) - (cosf(xm)) - 1;     
    }
    er = (fabs(fabs(fxma) - fabs(fxm)) / fabs(fxma));
    }while((fxm<-0.000001)||(fxm>0.000001));
    printf("El valor del punto medio es %.4f y el numero de iteraciones fue %d\n",xm,i+1);
    return 0;
}