#include<stdio.h>
#include<stdlib.h>
int n;
int place(int k,int i,int x[]){
  for(int j=0;j<k-1;j++){
    if((x[j]==i) || (abs(j+1-k)==abs(x[j]-i)))
      return 0;
  }
  return 1;
}
void Nqueen(int k,int x[]){
  for(int i=1;i<=n;i++){
    if(place(k,i,x)){
      x[k-1]=i;
      if(k==n){
        for(int j=0;j<n;j++){
          printf("%d ",x[j]);}
        printf("\n");
      }
      else{
        Nqueen(k+1,x);
      }
  }
}
}
int main(){
  printf("Enter the no. of Queens:");
  scanf("%d",&n);
  int x[n];
  printf("The Solution Sets are:\n");
  Nqueen(1,x);
}
