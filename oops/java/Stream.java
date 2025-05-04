import java.util.*;
import java.lang.*;
import java.util.stream.*;

public class Stream {
    public void printArray(int arr[]){
        for(int i=0;i<arr.length;i++){
                System.out.print(arr[i]);
            }
            System.out.println();
        }
    public void printList(List<Integer>al){
        for(int i=0;i<al.size();i++){
            System.out.print(al.get(i));
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int arr[]={1,2,4,5};
        List<Integer>al=Arrays.stream(arr).sorted().boxed().collect(Collectors.toList());
        Stream sol=new Stream();
        sol.printArray(arr);
        al = al.stream().filter(x->x!=4).collect(Collectors.toList());
        sol.printList(al);
        al = al.stream().map(x->x*4).collect(Collectors.toList());
        sol.printList(al);
    }
}
