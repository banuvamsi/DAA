#include <stdio.h>
#include <stdlib.h>
void readArray(float a[],int n){
    for(int i=0;i<n;i++)
        scanf("%f",&a[i]);
}
void printArray(float a[],int n){
    for(int i=0;i<n;i++)
        printf("%f ",a[i]);
    printf("\n");
}
void interchange(int a[], int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void knapsack(float p[],float w[],int m, int n,float x[]) {
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }
    if (m == 0) {
        return;
    }
    int index[n];
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
          for (int j = i + 1; j < n; j++) {
            if (p[index[i]] / w[index[i]] < p[index[j]] / w[index[j]]) {
                interchange(index, i, j);
            }
        }
    }
    float u = m;int i;
    for (i = 0; i < n; i++) {
        if (w[index[i]] > u) {
            break;
        }
        x[index[i]] = 1.0;
        u -= w[index[i]];
    }
    if (i < n) {
        x[index[i]] = u / w[index[i]];
    }
}

int main() {
    int n,m;
    printf("Enter the no.of elements:");
    scanf("%d",&n);
    float p[n],w[n],x[n];
    printf("\nEnter the Profit values:\n");
    readArray(p,n);
    printf("\nEnter the Weight values:\n");
    readArray(w,n);
    printf("\nEnter the Maximum Limit of Knapsack:");
    scanf("%d",&m);
    knapsack(p, w, m, n, x);
    float opt_prof=0;
    printf("\nSolution set is:\n");
    for(int i=0;i<n;i++){
        printf("%f ",x[i]);
        opt_prof+=p[i]*x[i];
    }
    printf("\nThe Optimal Profit Of the Knapsack is:%f",opt_prof);
    
    return 0;

