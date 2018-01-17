import java.util.*;

public class Main
{
    static class nameSort implements Comparator<student>{
        public int compare(student a, student b){
            return a.name.compareTo(b.name);
            }
    }
    
    private static class student{
        public int r;
        public String name;
        
        public student(int roll, String n){
            this.r = roll;
            this.name = n;
        }
        
        public String toString(){
            return "Student - " + "  RollNo:" + r + "   Name :" + name;  
        }
    }
    
    public static void main(String[] args)
    {
        ArrayList<student> al = new ArrayList<>();
        
        al.add(new student(1, "c"));
        al.add(new student(2, "b"));
        al.add(new student(3, "a"));
        al.add(new student(4, "d"));
        
        Collections.sort(al,  new nameSort());
        
        Iterator itr = al.iterator();
    
        while(itr.hasNext()){
          student t = (student)itr.next();
          System.out.println(t.toString());
        }
    }
}
