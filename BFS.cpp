#include<iostream>
#include<queue>
using namespace std;
void BFS(int G[][50],int n,int k){
  int visited[50]={0};
  queue<int> st;
  st.push(k);
  while(!st.empty()){

    int s= st.front();
    st.pop();
    
    if(visited[s]==0)
    {
      visited[s]=1;
      cout<<s<<" ";
    }
    
    for(int j=0;j<=n;j++)
    {
    
      if(G[s][j]==1 && visited[j]==0){
        st.push(j);
      }
    
    } 
  
  }

}

int main()
{
  int n;
  cin>>n;
  int G[50][50];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>G[i][j];
    }
  }
  BFS(G,n,0);
  cout<<"\nprepared by 23CE051 Darshan"<<endl;
  return 0;
}