#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of dimensions:";
    cin>>n;
    int a[n];
    cout<<"Enter dimensions:";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int m[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || j==0 || i==j)
            m[i][j]=0;
        }
    }
    for(int r=1;r<n;r++)
    {
        int t,j=1+r;
        for(int i=1;j<n;i++,j=i+r)
        {
            for(int k=i;k<j;k++)
            {
                t=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
                if(k==i)
                m[i][j]=t;
                else
                m[i][j]=min(t,m[i][j]);
            }
            // cout<<"m["<<i<<"]["<<j<<"]="<<m[i][j]<<endl;
        }
    }
    cout<<"Optimal cost for parenthesization is:"<<m[1][n-1]<<endl;
}