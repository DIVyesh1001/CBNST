#include<stdio.h>
float f(float x,float y)
{
    // return (y-x)/(y+x);
    return -1*x*y*y;
}
int main()
{
    int n,i=1;
    float xi,yi,x,y,h;
    printf("Enter the value of n : ");
    scanf("%d",&n);

    printf("Enter the value of x and y : ");
    scanf("%f%f",&xi,&yi);
    printf("Enter the value of x for which y to be determined");
    scanf("%f",&x);
    h=(x-xi)/n;
    while(xi<x && i<=n)
    {
        y=yi+h*f(xi,yi);
        yi=y;
        xi=xi+h;
        printf("\nx=%f\ty=%f",xi,yi);
        i++;
    }
    printf("\nvalue y=%f",y);
}