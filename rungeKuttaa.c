#include<stdio.h>
float f(float x,float y)
{
    return x+y*y;
}
int main()
{
    float x0,y0,xn,h,yn,k1,k2,k3,k4,k;
    int i,n;
    printf("Enter the intial value : ");
    printf("x0= ");
    scanf("%f",&x0);
    printf("y0= ");
    scanf("%f",&y0);
    printf("Enter the calculation value: ");
    scanf("%f",&xn);
    printf("enter the number of interval :");
    scanf("%d",&n);

    h=(xn-x0)/n;
    printf("x0\ty0\tyn");
    for(i=0;i<n;i++)
    {
        k1=h*(f(x0,y0));
        k2=h*f((x0+h/2),(y0+k1/2));
        k3=h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0+h,y0+k3);
        k=(k1+2*k2+2*k3+k4)/6;

        yn=y0+k;
        printf("\n%0.2f\t%0.2f\t%0.2f",x0,y0,yn);
        x0=x0+h;
        y0=yn;
    }
    printf("\nvalye of yn= %f",yn);

    return 0;
}