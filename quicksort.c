#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int a[], int s, int e) {
	int i,j;
  int pivot = a[e];
  i = s - 1;
  for (j = s; j <= e - 1; j++) {
    if (a[j] < pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[e]);
  return i + 1;
}

void quickSort(int a[], int s, int e) {
  if (s < e) {
    int part = partition(a, s, e);
    quickSort(a, s, part - 1);
    quickSort(a, part + 1, e);
  }
}

int main() {
  int a[20], i, j, n, k;
  printf("enter no of elements : ");
  scanf("%d", &n);
  printf("\nenter the elements into the array : \n");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  quickSort(a, 0, n - 1);
  printf("array elements are : \n");
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("enter k : \n");
  scanf("%d", &k);
  printf("The kth smallest element is : %d ", a[k - 1]);

  return 0;
}
