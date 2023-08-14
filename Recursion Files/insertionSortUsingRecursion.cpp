#include<iostream>
using namespace std;

void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortUsingRecursion(int arr[], int n, int i=1){
    if(n == 0)
        return;
    int key = arr[i], j = i-1;
    while(j >= 0 && arr[j]>key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
    return insertionSortUsingRecursion(arr, n-1, i+1);
}

int main(){
    int arr[] = {1,2,5,3,9,4,5,7,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSortUsingRecursion(arr, size);
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;

    insertionSort(arr, size);
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}