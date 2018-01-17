package dfstraversal;

import java.util.Iterator;
import java.util.LinkedList;

public class DFSTraversal {
    
    static class graph{
        final private int V;
        final private LinkedList<Integer> adj[];
        
        graph(int v){
            this.V = v;
            adj = new LinkedList[V];
            
            for(int i = 0; i < v; ++i){
                adj[i] = new LinkedList(); 
            }
        }
        
        void addEdge(int v, int x){
            adj[v].add(x);
        }
        
        void DFSu(int v, boolean visited[]){
            
            visited[v] = true;
            System.out.println(v + " ");
            
            Iterator<Integer> i = adj[v].listIterator();
            
            while(i.hasNext()){
                int n  = i.next();
                if(!visited[n])
                    DFSu(n, visited);
            } 
        }
        
        void DFS(int v){
            boolean visited[] = new boolean[v];
            DFSu(0, visited);
        }
        
    }
    
    public static void main(String args[]){
        graph g = new graph(4);
        
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        
        g.DFS(4);
    }
}
