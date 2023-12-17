#include<stdio.h>
#include<math.h>

float f(float x)
{
    return 1/(1+pow(x,2)) ;
}
int main()
{
    int n;
    float sum=0;
    float i,a,b,h;
    printf("Enter teh value of a and b  : \n");
    scanf("%f%f",&a,&b);
    printf("Enter the value of n:\n");
    scanf("%d",&n);

    h=(b-a)/n;
    sum=f(a)+f(b);
    for(i=a+h;i<b;i=i+h)
    {
        sum=sum+2*f(i);
    }
    sum=(h*sum)/2;

    printf("integral %f",sum);
    return 0;
}