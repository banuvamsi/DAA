#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = 0;
    int b[r - l + 1];

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    
    while (i <= m) {
        b[k] = a[i];
        i++;
        k++;
    }
    
    while (j <= r) {
        b[k] = a[j];
        j++;
        k++;
    }

    for (k = 0; k < r - l + 1; k++) {
        a[l + k] = b[k];
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void print1(int a[], int n) {
	int i;
    for(i = 0; i < n; i++) {
        printf("\t%d", a[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    
    printf("Original array:");
    print1(a, n);
    
    mergesort(a, 0, n - 1);
    
    printf("Sorted array:");
    print1(a, n);

    return 0;
}
