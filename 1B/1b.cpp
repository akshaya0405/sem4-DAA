#include<bits/stdc++.h>
#include<chrono>
#include<fstream>
using namespace std;

int main()
{
    int n=100000;
    int arr[n];

    ofstream outdata;
    outdata.open("output.csv");

    for(int i=0;i<n;i++)
     {
        arr[i]=rand()%n;
        // cout<<arr[i]<<"\n";
     }

     int copyarr[n];
     copy(arr,arr+n,copyarr);
    
    for(int i=100;i<=n;i+=100)
    {
      //Insertion Sort
      auto start=chrono::high_resolution_clock::now();
      for(int j=1;j<i;j++)
      {
        int k=j;
        while(arr[k-1]>arr[k] && k>0)
         {
            int temp;
            temp=arr[k-1];
            arr[k-1]=arr[k];
            arr[k]=temp;
            k--;
         }
      }
      auto end=chrono::high_resolution_clock::now();
      outdata<<"\n"<<i/100<<","<<chrono::duration_cast<chrono::nanoseconds>(end-start).count()<<",";
    // for(int a=0;a<i;a++)
    // {
    //     cout<<arr[a]<<" ";
    // }

    //Selection Sort
    start=chrono::high_resolution_clock::now();
    for (int j=0;j<i;j++)
    {
        int min=j;
        for(int k=j+1;k<i;k++)
        {
            if(copyarr[min]>copyarr[k])
            {
                min=k;
            }
        }
        int temp=copyarr[min];
        copyarr[min]=copyarr[j];
        copyarr[j]=temp;
    }
    end=chrono::high_resolution_clock::now();
    outdata<<chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    // for(int a=0;a<i;a++)
    // {
    //     cout<<copyarr[a]<<" ";
    // }
    }

     return 0;
}