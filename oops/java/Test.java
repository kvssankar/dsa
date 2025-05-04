import java.util.*;
import java.lang.*;


public class Test{
    public static void main(String args[]){
        List<List<Character>>al=new ArrayList<>(Collections.nCopies(5, Collections.nCopies(5, 'a')));
        al.get(0).add(1,'b');
        System.out.println(al);
    }
}
