// The simplest and shortest recursively reversing a linked list. @author Ashutosh-Sharma

public class ReverseALinkedList {
    static class Node{
        int data;
        Node next;
        Node(int d){
            this.data = d;
            this.next = null;
        }
    }
    
    Node reverseL(Node prev, Node cur, Node next){
        
        if(cur == null)
            return prev;
        
        next = cur.next;
        cur.next = prev;
        
        Node revHead = reverseL(cur, next, null);
  
        return revHead;
    }
    
    public static void main(String[] args) {
        // My linked list 1 -> 2 -> 3 -> null
        // Reverse list shoould be 3 -> 2 -> 1 -> null
        
        
        // Making the linked list
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        
        ReverseALinkedList r = new ReverseALinkedList();
        // Calling reverseL on the head of our linked list
        head = r.reverseL(null, head, null);
        
        // Printing the reversed list
        while(head != null){
            System.out.println(head.data + " ");
            head = head.next;
        }
    }
}
