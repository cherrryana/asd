#include <iostream>

// поразрядная сортировка

int max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void calc(int arr[], int n, int e)
{
    int *output = new int[n]; 
    int ind[10] = { 0 };


    for (int i = 0; i < n; i++)
        ind[(arr[i] / e) % 10]++;

    for (int i = 1; i < 10; i++)
        ind[i] += ind[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[ind[(arr[i] / e) % 10] - 1] = arr[i];
        ind[(arr[i] / e) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int maximum = max(arr, n);
    for (int e = 1; maximum / e > 0; e *= 10)
        calc(arr, n, e);
}

int main()
{
    int arr[] = { 66, 32, 11, 2, 0, 85, 75, 44 };
    int n = sizeof(arr) / sizeof(int);
    radixSort(arr, n);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    return 0;
}