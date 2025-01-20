// https://www.codingninjas.com/codestudio/problems/quick-sort_983625?leftPanelTab=1

#include <iostream>
using namespace std;

int partition(int *arr, int start, int end){
    // get pivot element  
    int pivot = arr[start];
    
    // get count of how much less than pivot elements are present in rightside of pivot
    int cnt = 0;
    for(int i = start+1; i <= end; i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }

    int pivotIndex = start + cnt;
    swap(arr[pivotIndex], arr[start]);

    // make pivot left elements are less or right elements are big

    int i = start;
    int j = end;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int start, int end){
    if(start >= end){
        return;
    }

    int p = partition(arr, start, end);

    // Partition of left portion
    quickSort(arr, start, p-1);

    // Partition of right portion
    quickSort(arr, p+1, end);
}

int main(){
    int arr[8] = {3,2,4,1,8,6,7,5};
    int n = 8;
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}