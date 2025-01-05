#include <stdio.h>
#include <stdlib.h>

int* generateFibonacciSeries(int n) {
    if (n <= 0) {
        return NULL; // Return NULL for invalid input
    }

    // Allocate memory for the array to store Fibonacci series
    int* fibonacciSeries = (int*)malloc(n * sizeof(int));
    if (!fibonacciSeries) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Handle base cases
    if (n >= 1) fibonacciSeries[0] = 0;
    if (n >= 2) fibonacciSeries[1] = 1;

    // Generate the Fibonacci series
    for (int i = 2; i < n; i++) {
        fibonacciSeries[i] = fibonacciSeries[i - 1] + fibonacciSeries[i - 2];
    }

    return fibonacciSeries;
}

int main() {
    int n;

    printf("Enter the number of Fibonacci series elements to generate: ");
    scanf("%d", &n);

    int* fibonacciSeries = generateFibonacciSeries(n);

    if (fibonacciSeries) {
        printf("Fibonacci Series: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", fibonacciSeries[i]);
        }
        printf("\n");

        // Free the allocated memory
        free(fibonacciSeries);
    } else {
        printf("Invalid input or memory allocation failed.\n");
    }

    return 0;
}
