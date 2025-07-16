// "static void main" must be defined in a public class.
public class Main {
    static void bubbleSort(Integer[] arr){
        int n=arr.length;
        for(int i=0;i<n;i++){
            boolean isSwapped=false;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    isSwapped=true;
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
            if(!isSwapped) break;
        }
        
    }
    
    static void insertionSort(Integer arr[]){
        int n=arr.length;
        for(int i=1;i<n;i++){
            int j=i-1;
            int key=arr[i];
            for(;j>=0;j--){
                if(arr[j]>arr[j+1]){
                    int t=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=t;
                }else{
                    break;
                }
            }
            arr[j+1]=key;
        }
        
    }
    static void selectionSort(Integer arr[]){
        int n=arr.length;
        for(int i=0;i<n;i++){
            int min_idx=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[min_idx]){
                    min_idx=j;
                }
            }
            int temp=arr[i];
            arr[i]=arr[min_idx];
            arr[min_idx]=temp;
        }
        
    }
    
    static void merge(Integer []arr, int l, int m, int r){
        int nl=m-l+1;
        int nr=r-m;
        Integer arr1[]=new Integer[nl];
        Integer arr2[]=new Integer[nr];
        for(int i=0;i<nl;i++) arr1[i]=arr[l+i];
        for(int i=0;i<nr;i++) arr2[i]=arr[m+i+1];
        int i=0,j=0,k=l;
        while(i<nl && j<nr){
            if(arr1[i]<=arr2[j]){
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
    
    static void mergeSort(Integer arr[], int l, int r){
        if(l<r){//remember
            int m=l+(r-l)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
    
    public static void main(String[] args) {
        Integer [] arr={2,1,5,4,3,3,2};
        // bubbleSort(arr);
        // insertionSort(arr);
        // selectionSort(arr);
        mergeSort(arr,0,arr.length-1);//remember
        for(Integer i:arr){
            System.out.println(i);
        }
    }
}

| **Property**                     | **Value**                        |
| -------------------------------- | -------------------------------- |
| **Stability**                    | ✅ Yes                            |
| **In-place**                     | ❌ No (uses O(n) auxiliary space) |
| **Best Case Time Complexity**    | **O(n log n)**                   |
| **Average Case Time Complexity** | **O(n log n)**                   |
| **Worst Case Time Complexity**   | **O(n log n)**                   |
| **Space Complexity**             | **O(n)**                         |
