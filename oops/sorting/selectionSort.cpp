#include <bits/stdc++.h>
using namespace std;

//find min n times
void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        swap(arr[min_idx],arr[i]);
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
    selectionSort(arr,n);
    print(arr,n);
}

| **Property**                     | **Value**                                   |
| -------------------------------- | ------------------------------------------- |
| **Stability**                    | ❌ No (can be made stable with extra effort) |
| **In-place**                     | ✅ Yes (O(1) extra space)                    |
| **Best Case Time Complexity**    | **O(n²)**                                   |
| **Average Case Time Complexity** | O(n²)                                       |
| **Worst Case Time Complexity**   | **O(n²)**                                   |
| **Space Complexity**             | **O(1)**                                    |
