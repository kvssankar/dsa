import java.util.*;


public class lists{
    public static void main(String[]args){
        //initializing the list
        //only works for strings
        String arr[]={"2","3","4"};
        List<String> list=Arrays.asList(arr);

        ArrayList<Integer> list2=new ArrayList<Integer>(List.of(2,3,4));
        
        int[] arr1={1,2,3,4,5};
        List<Integer> list1=new ArrayList<Integer>();
        for(int i:arr1){
            list1.add(i);
        }

        //filter 3 from arr1 using stream
        List<Integer> list4=list1.stream()
        .filter(i->i!=3)
        .collect(Collectors.toList());

        List<Integer>list5=list1.stream()
        .sorted()
        .boxed().collect(Collectors.toList());

        List<List<Integer>> ll=new ArrayList<>(Collections.nCopies(5, Collections.nCopies(5, 0)));
        List<List<Character>> ll1=new ArrayList<>(Collections.nCopies(5, Collections.nCopies(5, 'a')));
        //set (0,5) as 'b'
        ll1.get(0).set(5,'b');
        
        //sorting
        int arr2[]={1,2,3,4,5};
        Arrays.sort(arr2);
        Arrays.sort(arr2,0,arr2.length);

        List<Integer> list3=new ArrayList<Integer>(List.of(2,3,4));
        Collections.sort(list3);
        Collections.sort(list3.subList(0,list3.size()));
        Collections.sort(list3.subList(0,list3.size()),Collections.reverseOrder());

        //swap
        Collections.swap(list3,1,2);//swap indices 2 and 3

        //reverse
        Collections.reverse(list3);

        Collections.max(list3);

        Collections.min(list3);

        Collections.frequency(list3,1);

        Collections.replaceAll(list3,1,2);

        Collections.rotate(list3,1);

        Collections.shuffle(list3);

        Collections.fill(list3,1);

        Collections.copy(list3,list3);

        Collections.disjoint(list3,list3);

        Collections.nCopies(5, 0);

        //binary search
        int index=Collections.binarySearch(list3,3);

        //traversing
        for(int i:list3){
            System.out.println(i);
        }

        //traversing using iterator
        Iterator<Integer> it=list3.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }
        
        //list operations
        list3.add(1);

        list3.remove(1);

        list3.set(1,2);

        list3.get(1);

        list3.size();

        list3.contains(1);

        list3.indexOf(1);

        list3.lastIndexOf(1);

        list3.clear();

        list3.isEmpty();

        list3.addAll(list3);

        list3.removeAll(list3);

        //remove last element
        list3.remove(list3.size()-1);

        //2 power 31
        int max=Integer.MAX_VALUE;
    }
}