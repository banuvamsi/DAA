#include <stdio.h>
#include<stdlib.h>
int n;
int check(int c[][n],int u){
  int Incoming_edge=0;
  for(int i=0;i<n;i++){
    if(i!=u && c[i][u]!=999){
      Incoming_edge=1;
      break;
    }
  }
  return Incoming_edge;
}
void Bellman_Ford(int c[][n],int v,int d[]){
  for(int i=0;i<n;i++){
    d[i]=c[v][i];
  }
  for(int k=1;k<n-1;k++){
    for(int u=0;u<n;u++){
        if(u!=v && check(c,u)==1){
          for(int i=0;i<n;i++){
            if(i!=u && d[u]>d[i]+c[i][u]){
              d[u]=d[i]+c[i][u];
            }
          }
        }
    }
  }
}
int main(){
//   n=7;
//   int cost[7][7] = {
//   {0,6,5,5,999,999,999},
//   {999,0,999,999,-1,999,999},
//   {999,-2,0,999,1,999,999},
//   {999,999,-2,0,999,-1,999},
//   {999,999,999,999,0,999,3},
//   {999,999,999,999,999,0,3},
//   {999,999,999,999,999,999,0},
// };
  printf("Enter no of vertices of graph:\n");
  scanf("%d", &n);
  int cost[n][n];
  printf("Enter the Graph(Cost Adjacency Matrix):\n");
  for(int i=0;i<n;i++){
    printf("Enter distance between %d and others:\n",i);
    for(int j=0;j<n;j++){
      scanf("%d",&cost[i][j]);
    } 
  }
  
  int d[n],v;
  printf("Enter the Source Vertex:");
  scanf("%d",&v);
  Bellman_Ford(cost,v,d);
  printf("The minimum lengths of paths from source vertex - %d to all others:\n",v);
  for(int i=0;i<n;i++){
    printf("%d\t",d[i]);
  }
}
