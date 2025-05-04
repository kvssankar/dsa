// "static void main" must be defined in a public class.
import java.util.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        String s="sankar";
        String s1=s,s2=s;
        for(int i=0;i<s.length();i++){
            System.out.println(s.charAt(i));
        }

        //char to string
        char c='a';
        String s3=Character.toString(c);
        
        //format
        String ans=String.format("my name is %s",s);
        
        //decimal points
        double d=1.2343;
        String sf=String.format("float value %.3f",d);
        
        //substring
        System.out.println(sf.substring(2,4));
        if(ans.contains("sankar")){
            System.out.println("true");
        }
        
        //join
        String j=String.join(":",ans,sf);
        String s4=s1.concat(s2).concat(s3);
        
        //split
        String[] words=sf.split(" ");
        
        //replace
        String newS=sf.replace("ab","cd");
        
        //compare
        s1.equals(s2);
        s1.equalsIgnoreCase(s2);
        s1.compareTo(s2); //if(s1>s2) postive, if equals then 0
        s1.contains(s2);
        s1.indexOf("ka",2);//start index
        

        //trim
        String s3="  sankar  ";
        s3=s3.trim();

        //reverse
        StringBuilder sb=new StringBuilder(s3);
        sb.reverse();
        String s5=sb.toString();

        //length
        s3.length();

        //to upper
        s3=s3.toUpperCase();

        //to lower
        s3=s3.toLowerCase();

        //to char array
        char[] ch=s3.toCharArray();

        //to string
        String s5=String.valueOf(ch);

        //to int
        int i=Integer.parseInt(s3);

        //sort string
        char[] ch1=s3.toCharArray();
        Arrays.sort(ch1);
        String s6=String.valueOf(ch1);

        //stringbuilder opereations
        StringBuilder sb=new StringBuilder();
        sb.append('a');
        sb.append("sankar");
        sb.insert(2,"sankar");
        sb.delete(2,4);
        sb.reverse();
        sb.toString();


    }
}