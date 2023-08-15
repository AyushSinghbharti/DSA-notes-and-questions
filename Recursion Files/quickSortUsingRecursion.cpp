#include<iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int pivot = arr[s];
    int cnt = 0;

    for(int i = s+1; i<e; i++)
        if(arr[i] < pivot)
            cnt++;

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
    if(i<pivotIndex && j>pivotIndex)
        swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e){
    if(s>=e)
        return;
    
    int p = partition(arr, s, e);
    quickSort(arr, s, p);
    quickSort(arr, p+1, e);
    return;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 5, 9, 2, 6, 4, 7, 8, 8,9,5,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size);

    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
