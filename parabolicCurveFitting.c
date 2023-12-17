#include<stdio.h>
void convertToUpperTri(float a[3][4],int n)
{
    float ratio;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j>i)
            {
                ratio=a[j][i]/a[i][i];
                for(int k=0;k<n+1;k++)
                {
                    a[j][k]-=ratio*a[i][k];
                }
            }
        }
    }
}

void applyBackSubs(float a[3][4],float value[3],int n)
{
    value[n-1]=a[n-1][n]/a[n-1][n-1];
    int i,j,sum;
    for(i=n-2;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<n;j++)
        {
            sum=sum+a[i][j]*value[j];
        }
        value[i]=(a[i][n]-sum)/a[i][i];
    }
}
int main()
{

}