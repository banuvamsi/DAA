#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
int mincostVertex(int dist[],int s[]){
  int min_cost=999;
  int index=n-1;
  for(int i=0;i<n;i++){
    if(min_cost>dist[i] && s[i]!=1){
      min_cost=dist[i];
      index=i;
    }
  }
  return index;
}
void ShortestPath(int v ,int cost[][n],int dist[]){
  int s[n];
  for(int i=0;i<n;i++){
    s[i]=0;
    dist[i]=cost[v][i];
  }
  s[v]=1;
  for(int i=1;i<n-1;i++){
    int u=mincostVertex(dist,s);
    s[u]=1;
    for(int j=0;j<n;j++){
      if(s[j]!=1 && cost[u][j]!=999){
        if(dist[j]>dist[u]+cost[u][j]){
          dist[j]=dist[u]+cost[u][j];
        }
      }
    }
  }
}
int main(){
  // n=7;
  // int cost[7][7]={{0,1,2,999,999,999,3},
  // {999,0,999,4,999,999,999},
  // {999,999,0,999,3,1,999},
  // {999,999,999,0,999,1,999},
  // {999,999,999,999,0,2,999},
  // {999,999,999,999,999,0,999},
  // {999,999,999,999,999,8,0}};
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
  printf("\nEnter the source vertex:");
  int v,dist[n];
  scanf("%d",&v);
  ShortestPath(v,cost,dist);
  printf("\nThe distance of all vertices from %d is :\n",v);
  for(int i=0;i<n;i++){
    printf("%d ",dist[i]);
  }
}

