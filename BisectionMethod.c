#include<stdio.h>
#include<math.h>
#include<conio.h>

float func1(float x)
{
    float f_x = cos(x)-x*exp(x);
    return f_x;
}

int main()
{
    float xa, xb;
    float xm,e;
    printf("Enter the initial guesses:\n");
    scanf("%f%f",&xa,&xb);
    printf("Enter the tolerable error:");
    scanf("%f",&e);

    float f_xa = func1(xa);
    float f_xb = func1(xb);
    float f_xm;
    int itertation=0;

    if((xa*xb)>0.0){
        printf("Incorrect initial guess.\n");
        exit(0);
    }
    do{
            xm = (xa+xb)/2;
            f_xm = func1(xm);
            ++itertation;
            printf("iteration number:%d\n",itertation);
            printf("xa=%f\txb=%f\txm=%f\tf_xm=%f\n",xa,xb,xm,f_xm);


            if((f_xa*f_xm)<0)
            {
                xb=xm;
                f_xb=f_xm;
            }

            else
            {
                xa=xm;
                f_xb=f_xm;
            }
    }
    while(fabs(f_xm)>e);
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\t\t");
    printf("The required number of the iterations are= %d\n",itertation);
    printf("\t\t");
    printf("The root is:%f",xm);
    return 0;
}
//(xb-xa)>=pow(10,-5)
