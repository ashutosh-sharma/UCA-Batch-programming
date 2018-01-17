# /*
# * DETECT CYCLE IN A GRAPH USING UNION-RANK ALGO AND 
# * PATH COMPRESSION TECHNIQUE.
# */

package detectcycle;

public class DetectCycle  {

    // Edge consists of src - destination
    static public class Edge{
        public int src;
        public int dest;
    }
    
    // graph contains : V - > number of vertices(Int)
    //                  E -> number of edges(Int)
    //                  edges -> array of Edge objects storing all edges(Edge)
    
    static class graph{
    
        public int V;
        public int E;
        public Edge edges[];
    
        public graph(int v, int e){
        V = v;
        E = e;
        edges = new Edge[E];

        for (int i = 0; i < e; ++i)
            edges[i] = new Edge();
        }
        
        void addEdge(int i, int s, int d){
            edges[i].src = s;
            edges[i].dest = d;
        }

    }
    
    // 'set' class for each node contains its parent and rank
    static class set{
        public int parent;
        public int rank;
    }

    //find(set, int) to get the ultimate parent of the passed node 'n'
    static int find(set s[], int n){
        if(s[n].parent != n)
            find(s, s[n].parent);

        return s[n].parent;
    }

    //union(set, int, int) to union two nodes x and y
    static void union(set s[], int x, int y){
        int p_x = find(s, x);
        int p_y = find(s, y);                                                   
        
        if(s[p_x].rank < s[p_y].rank){
            s[p_x].parent = p_y;
        }
        else if(s[p_x].rank > s[p_y].rank){
            s[p_y].parent = p_x;
        }
        
        else{
            s[p_y].parent = p_x;
            s[p_x].rank++;
        }
    }
    
    // isCycle(graph) to detech cycle in the passed graph 'g'
    // 1. Making a 'set' array for all nodes to store their parents and rank of each node
    // 2. Intilize parent of each node as themsleves and rank as 0
    // 3. Traverse each node
    //    a. Find the parents for each corresponding pair of nodes.
    //    b. If their parents are not same union those nodes.
    //    c. If their parents are same then 'the Cycle is detected'.
    // 4. Return the result as 1 or 0 to main driving fucntion
    
    static int isCycle(graph g){
        
        int retCycle = 0;
        
        // 1.Making a 'set' array for all nodes to store their parents and rank of each node
        set s[] = new set[g.V];
        
        // 2.Intilize parent of each node as themsleves and rank as 0
        for(int i = 0; i < g.V; i++){
            s[i]=new set();
            s[i].parent = i;
            s[i].rank = 0;
        }
        
    //    3. Traverse each node :
    //        a. Find the parents for each corresponding pair of nodes.
    //        b. If their parents are not same union those nodes.
    //        c. If their parents are same then 'the Cycle is detected'.
        for(int j = 0; j < g.E; j++){   
            int p_x = find(s, g.edges[j].src);
            int p_y = find(s, g.edges[j].dest);
            
            if(p_x != p_y){
                union (s, p_x, p_y);
            }
            else{
                retCycle = 1;
                break;
            }
        }
        return retCycle;
    }
    
    public static void main(String[] args) {
        
        // Creating a graph of 3 vetices and 3 edges among them
        graph g = new graph(3, 3);
        
        // adding all three edges 0 --- 1
        //                        1 --- 2
        //                        0 --- 2
        
        g.addEdge(0, 0, 1);
        g.addEdge(1, 1, 2);
        g.addEdge(0, 0, 2);
        
        // caling function isCycle() to check wheather the graph g has cycle or not
        
        int res = isCycle(g);
        
        if(res == 0){
            System.out.println("No cycle is present.");
        }
        else{
            System.out.println("Cycle is present.");
        }
    }
}
