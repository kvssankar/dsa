#include <bits/stdc++.h>
using namespace std;

//sawp n2 times
void bubbleSort(int arr[], int n){
    bool isSwapped=false;
    for(int i=0;i<n-1;i++){
        isSwapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                isSwapped=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!isSwapped) break;
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
    bubbleSort(arr,n);
    print(arr,n);
}

| Property                     | Value                                |
| -------------------------------- | ---------------------------------------- |
| Stability                    | Yes                                      |
| In-place                     | Yes                                      |
| Best Case Time Complexity    | O(n) (when array is already sorted)  |
| Average Case Time Complexity | O(n²)                                    |
| Worst Case Time Complexity   | O(n²) (when array is reverse sorted) |
| Space Complexity             | O(1) (constant auxiliary space)          |

