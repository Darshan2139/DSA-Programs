#include <iostream>
#include <vector>
using namespace std;

void linear(int arr[],int n,int x)
{
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            cout<<i;
            break;
        }
    }
}
int main() {
    int n,x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;
    linear(arr,n,x);
    return 0;
}