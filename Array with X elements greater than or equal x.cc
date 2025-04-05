#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    for( x=0;x<=n;x++)
    {
        int coutn=0;
        for(int i=0;i<n;i++)
        {
            if(array[i]>=x)
            coutn++;
        }

        if(coutn==x)
        {
            cout<<x;
            break;
        }
        if(coutn!=x && x==n)
        {
            cout<<"-1";
        }


    }
}