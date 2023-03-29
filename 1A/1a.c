#include<stdio.h>
#include<math.h>
double fact(double n);

int main()
{
    printf("\tn\tn^3\t2^n\tln n\tlg n\tn lg n\te^n\t(3/2)^n\tn.2^n\tn!");
    for(double i=0;i<=100;i++)
    {
        printf("\n%.0lf",i);
        printf("\t%.2lf",i);
        printf("\t%.2lf",pow(i,3));
        printf("\t%.2lf",pow(2,i));
        printf("\t%.2lf",log(i));
        printf("\t%.2lf",log2(i));
        printf("\t%.2lf",i*log2(i));
        // printf("\t%.2lf",pow(2,pow(2,i)));
        printf("\t%.2lf",exp(i));
        printf("\t%.2lf",pow(1.5,i));
        printf("\t%.2lf",i*pow(2,i));
        // printf("\n");
        printf("\t%.2lf",fact(i));
    }
    return !4;
}

double fact(double n)
{
    if(n==0)
    return 1;
    else
    return n*fact(n-1);
}