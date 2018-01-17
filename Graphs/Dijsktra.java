package dijkstra;

public class Dijkstra {
    
    static int V;
    
    void init(int dist[], boolean marked[], int src){
        
        for(int i = 0; i< V; i++){
            dist[i] = Integer.MAX_VALUE;
            marked[i] = false;
        }
        
        // Distance of source from source is zero.
        dist[src] = 0;
    }
    
    int minDistance(int dist[], boolean marked[]){
        int min = Integer.MAX_VALUE, min_index=-1;
 
        for (int v = 0; v < V; v++)
            if (marked[v] == false && dist[v] < min)
            {
                min = dist[v];
                min_index = v;
            }
 
        return min_index;
    }
    
    void setVertices(int v){
        V = v;
    }
    
    void shortestPath(int dist[]){
        System.out.println("Shortest distance of all vertices from source");
        for (int i = 0; i < V; i++)
            System.out.println(i+" \t "+dist[i]);
    }

    
    void dijsktra(int g[][], int src){
        // To keep distance of every vertex from the source vertex
        int dist[] = new int[V];
        
        boolean marked[] = new boolean[V];
        
        // Make distance for every vertex from the source vertex as infinite
        // and mark every vertex as not visited!
        init(dist, marked, src);
        
        
        // Poop from 0 to V-1 coz other then src vertex will be processed.
        for (int i = 0; i < V-1; i++)
        {
            // Pick the minimum distance vertex from current vertex
            int u = minDistance(dist, marked);
 
            // Mark the vertex u as included in shortest path
            marked[u] = true;
 
            // Traverse through all adjacent vertices of 'u' and update the distance
            // only update distance if dist[v] > dist[u] + g[u][v]
            for (int v = 0; v < V; v++)
                if (!marked[v] && g[u][v]!=0 && dist[u] != Integer.MAX_VALUE && dist[u]+g[u][v] < dist[v])
                    dist[v] = dist[u] + g[u][v];
        }
        
        // Print the shortest path from every vertex
        shortestPath(dist);
    }
        
    public static void main(String[] args) {
        
        // Create a graph with adjacency matrix implementation
        // weight(0 -- 1) -> 4
        // weight(0 -- 7) -> 8
        // weight(3 -- 2) -> 7
        // and so on!
        int graph[][] = new int[][]{{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                  {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                  {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                  {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                  {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                  {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                  {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                  {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                  {0, 0, 2, 0, 0, 0, 6, 7, 0}};
        Dijkstra d = new Dijkstra();
        
        // Setting vetices of graph as 9
        d.setVertices(9);
        d.dijsktra(graph, 0);
    }
}
