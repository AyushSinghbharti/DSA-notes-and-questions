#include<iostream>
using namespace std;

void selectionSort(int *arr, int begin, int size){
    if(begin >= size)
        return;
    
    int minIndex = begin;

    for(int i=begin; i<size; i++)
        if(arr[minIndex] > arr[i])
            minIndex = i;
        
    swap(arr[minIndex], arr[begin]);
    return selectionSort(arr, begin+1, size);
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,9,6,8,7,2};
    selectionSort(arr, 0, sizeof(arr)/sizeof(arr[0]));
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
