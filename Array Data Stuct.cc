#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPairable(int a[],int n,int k){
    int sign[n]={0},count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((a[i]+a[j])%k==0 && sign[j]!=1 && sign[i]!=1){
                count++;
                sign[j]=1;
                sign[i]=1;
                break;
            }
        }
    }
    if(count==n/2){
        return true;
    }
    else{
        return false;
    }
}


int main() {
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    if(n%2==1){
        cout<<"-1";
        return 0;
    }
    int sign[n]={0};
    if(isPairable(a,n,k)){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((a[i]+a[j])%k==0 && sign[i]!=1 && sign[j]!=1){
                    cout<<"("<<a[i]<<","<<a[j]<<")"<<endl;
                    sign[i]=1;
                    sign[j]=1;
                    break;
                }
            }
        }
    }
    else{
        cout<<"-1";
    }
    return 0;
}
