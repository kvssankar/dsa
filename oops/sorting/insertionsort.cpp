#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=arr[i];
        for(;j>=0;j--){
            if(arr[j]>arr[i]){
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