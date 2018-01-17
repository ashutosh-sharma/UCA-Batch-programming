import java.util.Iterator;

public class CustomLinkedList implements Iterable<Integer>
{    
    class Node{
        Integer data;
        Node next;

        Node(Integer data){
            this.data = data;
            this.next = null;
        }
    }
    
    //'private' coz no need to show it outside ; Naive user will not use it, he/she will use functions only
    private Node first = null;

    
    //two interface method for naive user add() and remove()
    public void add(Integer data)
    {
        Node node = new Node(data); 
        node.next = first;
        first = node;
    }
    
    //return type is Integer hence we can return null when first == null in line 31
    public Integer remove()
    {
        if(first == null) return null;
        int data = first.data;
        first = first.next;
        
        return data;
    }
    

    //Iterator interface has function hasNext(), next(), remove()
    //this will be helping us to create a for-each loop to iterate through the linkedList
    class LinkedListIterator implements Iterator<Integer>{
            
        private Node current = first;
        
        public boolean hasNext(){
            return current != null;
        }

        public Integer next(){
            int data = current.data;
            current = current.next;
            return data;
        }

        // no statements coz it is not a optional method, it has to implement it also
        public void remove(){
        }
    }

    //***************************************// 
    public Iterator<Integer> iterator(){
        return new LinkedListIterator();
    }
    
    public static void main(String[] args){
        CustomLinkedList ll = new CustomLinkedList();
        ll.add(3);
        ll.add(2);
        ll.add(1);

        // for-each loop will be implemented by iterator function and iterator of 
        // LinkedList that we created above
        
        for(Integer i : ll)
            System.out.println(i);
    }
}

