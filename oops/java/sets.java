public class sets{
    public static void main(String args[]){
        //initializing the set
        Set<Integer> set=new HashSet<Integer>();
        Set<Integer> set1=new HashSet<Integer>(List.of(1,2,3));
        Set<Integer> set2=new HashSet<Integer>(Arrays.asList(1,2,3));
        Set<Integer> set3=new HashSet<Integer>(Arrays.stream(new int[]{1,2,3}).boxed().collect(Collectors.toList()));
        Set<Integer> set4=new HashSet<Integer>(Arrays.stream(new int[]{1,2,3}).boxed().collect(Collectors.toSet()));
        Set<Integer> set5=new HashSet<Integer>(Arrays.stream(new int[]{1,2,3}).boxed().collect(Collectors.toCollection(HashSet::new)));
        Set<Integer> set6=new HashSet<Integer>(Arrays.stream(new int[]{1,2,3}).boxed().collect(Collectors.toCollection(LinkedHashSet::new)));
        Set<Integer> set7=new HashSet<Integer>(Arrays.stream(new int[]{1,2,3}).boxed().collect(Collectors.toCollection(TreeSet::new)));
        Set<Integer> set8=new HashSet<Integer>(Arrays.stream(new int[]{1,2,3}).boxed().collect(Collectors.toCollection(ConcurrentSkipListSet::new)));

        //adding elements
        set.add(1);
        set.add(2);

        //removing elements
        set.remove(1);

        //contains
        set.contains(1);

        //size
        set.size();

        //clear
        set.clear();

        //union
        set1.addAll(set2);

        //intersection
        set1.retainAll(set2);

        //difference
        set1.removeAll(set2);

        //subset
        set1.containsAll(set2);

        //disjoint
        set1.stream().anyMatch(set2::contains);

        //sorting
        List<Integer> list=new ArrayList<Integer>(set1);
        Collections.sort(list);
        set1=new HashSet<Integer>(list);

        //sorting
        List<Integer> list1=new ArrayList<Integer>(set1);
        Collections.sort(list1,Collections.reverseOrder());
        set1=new HashSet<Integer>(list1);

        
    }
}