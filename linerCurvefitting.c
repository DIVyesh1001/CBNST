#include<stdio.h>
int main()
{
    int n;
    float sum1=0,sum2=0,sum3=0,sum4=0,a,b;
    printf("enter the no of obsevation: ");
    scanf("%d",&n);
    float x[n],y[n],agumented_matrix[2][3];
    printf("Enter the value of x and y\n");
    for(int i=0;i<n;i++)
    {
        scanf("%f\t%f",&x[i],&y[i]);
    }
    for(int i=0;i<n;i++)
    {
        sum1=sum1+x[i];
        sum2=sum2+y[i];
        sum3=sum3+x[i]*y[i];
        sum4=sum4+x[i]*x[i];
    }

    agumented_matrix[0][0]=n;
    agumented_matrix[0][1]=sum1;
    agumented_matrix[0][2]=sum2;
    agumented_matrix[1][0]=sum1;
    agumented_matrix[1][1]=sum4;
    agumented_matrix[1][2]=sum3;



    //Gauss elemination
    float ratio=agumented_matrix[1][0]/agumented_matrix[0][0];
    for(int i=0;i<3;i++)
    {
        agumented_matrix[1][i]=agumented_matrix[1][i]-ratio*agumented_matrix[0][i];
    }

    //print the upper triangular matrix
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%0.2f ",agumented_matrix[i][j]);
        }
        printf("\n");
    }

    //backward substitution
    b=agumented_matrix[1][2]/agumented_matrix[1][1];
    a=(agumented_matrix[0][2]-b*agumented_matrix[0][1])/agumented_matrix[0][0];

    printf("Equation of the line is : y=%0.2f+%0.2fx",a,b);
}