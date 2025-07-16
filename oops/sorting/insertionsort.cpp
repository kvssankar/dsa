#include <bits/stdc++.h>
using namespace std;
//find place of i in left sorted
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=arr[i];
        for(;j>=0;j--){
            if(arr[j]>arr[j+1]){
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=key;
    }
}

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,3,2,5,4};
    int n = 5;
    insertionSort(arr,n);
    print(arr,n);
}

| Property                     | Value                  |
| -------------------------------- | -------------------------- |
| Stability                    | ✅ Yes                      |
| In-place                     | ✅ Yes (O(1) extra space)   |
| Best Case Time Complexity    | O(n) (already sorted)  |
| Average Case Time Complexity | O(n²)                      |
| Worst Case Time Complexity   | O(n²) (reverse sorted) |
| Space Complexity             | O(1)                   |
