#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomArray(int *v, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100000;
    }
}

void swap(int *i, int *j) {
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void bubbleSort(int *v, int n) {
    for (int i = n; i > 1; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (v[j] > v[j + 1]) swap(&v[j], &v[j + 1]);
        }
    }
}

void insertionSort(int *v, int n) {
    int key, j;
    for (int i = 1; i <= n; i++) {
        key = v[i];
        j = i - 1;
        while (j > -1 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void merge(int *v, int p, int q, int r) {
    int w[r - p + 1];
    int i = p;
    int j = q + 1;
    for (int k = 0; k < (r - p + 1); k++) {
        int t;
        if (i > q) {
            t = 1;
        } else {
            if (j > r) {
                t = 0;
            } else {
                if (v[i] < v[j]) t = 0;
                else t = 1;
            }
        }
        if (t == 0) {
            w[k] = v[i];
            i++;
        } else {
            w[k] = v[j];
            j++;
        }
    }
    for (int k = 0; k < (r - p + 1); k++) {
        v[k + p] = w[k];
    }
}

void mergeSort(int *v, int l, int h) {
    int m;
    if (l < h) {
        m = (l + h) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, h);
        merge(v, l, m, h);
    } else {
        return;
    }
}

void printArray(int *v, int n) {
    printf("Array: {");
    for (int i = 0; i < n - 1; i++) printf("%d, ", v[i]);
    printf("%d", v[n - 1]);
    printf("}\n");
}

int main() {
    clock_t start, end;
    int n = 5;
    int v[n];

    randomArray(v, n);
    start = clock();
    bubbleSort(v, n);
    end = clock();
    printf("Bubble Sort - time: %.3f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    randomArray(v, n);
    printArray(v, n);
    start = clock();
    insertionSort(v, n);
    end = clock();
    printArray(v, n);
    printf("Insertion Sort - time: %.3f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    randomArray(v, n);
    start = clock();
    mergeSort(v, 0, n);
    end = clock();
    printf("Merge Sort - time: %.3f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    return 0;
}
