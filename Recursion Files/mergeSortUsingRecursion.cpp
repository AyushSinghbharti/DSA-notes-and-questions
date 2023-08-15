#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];  // Fixed: Removed unnecessary array pointer declaration
    int *second = new int[len2]; // Fixed: Removed unnecessary array pointer declaration

    // Copy main array
    int mainIndex = s;
    for(int i = 0; i < len1; i++)
        first[i] = arr[mainIndex++];
    for(int i = 0; i < len2; i++)
        second[i] = arr[mainIndex++];
    
    // Merge 2 Sorted arrays
    int index1 = 0, index2 = 0;
    mainIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2])
            arr[mainIndex++] = first[index1++];
        else
            arr[mainIndex++] = second[index2++];
    }

    while(index1 < len1)
        arr[mainIndex++] = first[index1++];
    while(index2 < len2)
        arr[mainIndex++] = second[index2++];

    
    delete[] first;  // Fixed: Delete the dynamically allocated memory
    delete[] second; // Fixed: Delete the dynamically allocated memory
}

void mergeSort(int *arr, int s, int e){
    if(s >= e) // Fixed: Changed "s > e" to "s >= e" to handle the base case correctly
        return;
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 9, 6, 4, 7, 3, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1); // Fixed: Pass size - 1 to the mergeSort function
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
