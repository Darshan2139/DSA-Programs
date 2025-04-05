#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cout<<"Enter the element of Array:-"; 
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        }
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1-i;j++)
            {
                if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
                }
                }
                cout<<"Shorted Array is:-";
                for(i=0;i<n;i++)
                {
                cout<<a[i]<<" ";
                }
                cout<<endl<<"Prepared by 23CE051 Darshan";
                

    return 0;
}