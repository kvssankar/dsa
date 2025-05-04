#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int nl,nr;
    nl=m-l+1;
    nr=r-m;
    int arr1[nl],arr2[nr];
    for(int i=0;i<nl;i++) arr1[i]=arr[l+i];
    for(int j=0;j<nr;j++) arr2[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<nl && j<nr){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;
        }else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<nl){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<nr){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
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
    mergeSort(arr,0,n-1);
    print(arr,n);
}