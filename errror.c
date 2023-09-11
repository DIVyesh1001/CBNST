#include <stdio.h>
#include <math.h>
int main(){
    float ab_er,re_er,pe_er;
    float trueV, approxV;
    printf("Enter the true and approx values: ");
    scanf("%f %f",&trueV,&approxV);


    ab_er= fabs(trueV-approxV);
    re_er=ab_er/trueV;
    pe_er=re_er*100;

    printf("Absolute error: %f\n",ab_er);
    printf("Realtive error: %f\n",re_er);
    printf("Percentage error: %f\n",pe_er);

    return 0;
}