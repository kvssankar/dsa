import java.util.*;


public class maps{
    public static void main(String[]args){
        Map<Integer,Integer>map=new HashMap<>();

        m.getOrDefault(1,0);//0
        
        map.put(1,2);
        map.put(3,4);
        
        map.containsKey(1);//true
        map.containsValue(3);//false

        map.get(1); //2
        map.get(2); //null

        //traversing a hashmap
        for(Map.Entry<Integer,Integer> entry:map.entrySet()){
            System.out.println(entry.getKey()+" "+entry.getValue());
        }
        
        ///sort hashmap
        Map<Integer,Integer>map2=new HashMap<>();
        map2.put(1,2);

        List<Map.Entry<Integer,Integer>> list=new ArrayList<>(map2.entrySet());
        Collections.sort(list,(a,b)->a.getKey()-b.getKey());
        for(Map.Entry<Integer,Integer> entry:list){
            System.out.println(entry.getKey()+" "+entry.getValue());
        }

        map2.entrySet().stream()
            .sorted(Map.Entry.comparingByKey())
            .forEach(entry -> System.out.println(entry.getKey() + " " + entry.getValue()));


        //sort hashmap by values
        List<Map.Entry<Integer,Integer>> list=new ArrayList<>(map.entrySet());
        Collections.sort(list,(a,b)->a.getValue()-b.getValue());
        for(Map.Entry<Integer,Integer> entry:list){
            System.out.println(entry.getKey()+" "+entry.getValue());
        }

        map2.entrySet().stream()
            .sorted(Map.Entry.comparingByValue())
            .forEach(entry -> System.out.println(entry.getKey() + " " + entry.getValue()));


        //arrow funtcion traversing map
        map.forEach((k,v)->System.out.println(k+" "+v));

        //arrow function traversing list
        list.forEach((k)->System.out.println(k));

        // TreeMap with natural ordering
        Map<Integer, Integer> treeMap = new TreeMap<>();
        treeMap.put(3, 300);
        treeMap.put(1, 100);
        treeMap.put(2, 200);
        treeMap.forEach((key, value) -> System.out.println(key + " => " + value));

        // TreeMap with a custom comparator (e.g., descending order)
        Map<Integer, Integer> treeMapCustomOrder = new TreeMap<>(Comparator.reverseOrder());
        treeMapCustomOrder.put(3, 300);
        treeMapCustomOrder.put(1, 100);
        treeMapCustomOrder.put(2, 200);
        treeMapCustomOrder.forEach((key, value) -> System.out.println(key + " => " + value));


    }
}
