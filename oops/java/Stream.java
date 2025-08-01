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
// java.lang.Comparable<T>
class Order implements Comparable<Order> {
    int mid, sid, price;

    public Order(int mid, int sid, int price) {
        this.mid = mid;
        this.sid = sid;
        this.price = price;
    }

    @Override
    public int compareTo(Order o) {
        // Example: sort by price, then mid, then sid
        if (this.price != o.price)
            return Integer.compare(this.price, o.price);
        if (this.mid != o.mid)
            return Integer.compare(this.mid, o.mid);
        return Integer.compare(this.sid, o.sid);
    }
}


//comparator
class Order {
    int mid, sid, price;

    public Order(int mid, int sid, int price) {
        this.mid = mid;
        this.sid = sid;
        this.price = price;
    }

    @Override
    public String toString() {
        return "(" + mid + ", " + sid + ", " + price + ")";
    }
}

public class Main {
    public static void main(String[] args) {
        Comparator<Order> cmp = (a, b) -> {
            if (a.price != b.price) return Integer.compare(a.price, b.price);
            if (a.mid != b.mid) return Integer.compare(a.mid, b.mid);
            return Integer.compare(a.sid, b.sid);
        };

        TreeSet<Order> set = new TreeSet<>(cmp);

        set.add(new Order(1, 2, 100));
        set.add(new Order(1, 2, 100)); // duplicate
        set.add(new Order(2, 1, 90));
        set.add(new Order(1, 3, 100));

        for (Order o : set) {
            System.out.println(o);
        }
    }
}
