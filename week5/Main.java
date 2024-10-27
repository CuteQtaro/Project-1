package week5;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main{
    static class Edge {
        int head, tail, weight; // src and dest are the vertices and weight is the weight of the edge, src abbreviates source and dest abbreviates destination
        public Edge(int head, int tail, int weight){
            this.head = head;
            this.tail = tail;
            this.weight = weight;
        }
    }
    static class Subset { // subset is a disjoint set data structure
        int parent, rank; // parent is the parent of the subset and rank is the rank of the subset
        public Subset(int parent, int rank){
            this.parent = parent;
            this.rank = rank;
        }
    }

    static int findRoot(Subset[] subsets, int i){ 
        if(subsets[i].parent != i){
            subsets[i].parent = findRoot(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    static void union(Subset[] subsets, int x, int y){
        int xRoot = findRoot(subsets, x);
        int yRoot = findRoot(subsets, y);
        if(subsets[xRoot].rank < subsets[yRoot].rank){
            subsets[xRoot].parent = yRoot;
        } else if(subsets[xRoot].rank > subsets[yRoot].rank){
            subsets[yRoot].parent = xRoot;
        } else {
            subsets[yRoot].parent = xRoot;
            subsets[xRoot].rank++;
        }
    }

    static void kruskals(int V, List<Edge> edges){
        int j=0;
        int numOfEdges = 0; // noOfEdges is the number of edges in the minimum spanning tree
        Subset[] subsets = new Subset[V]; // subsets is an array of disjoint sets
        Edge[] result = new Edge[V]; // result is an array of edges in the minimum spanning tree
        for(int i=0; i<V; i++){
            subsets[i] = new Subset(i, 0); // initially, each vertex is a disjoint set
        }
        while(numOfEdges < V-1){
            Edge nextEdge = edges.get(j++); // get the next edge, why not get j-th edge directly?
            int x = findRoot(subsets, nextEdge.head); // find the parent of the source vertex
            int y = findRoot(subsets, nextEdge.tail); // find the parent of the destination vertex
            if(x != y){ // if the source and destination vertices are not in the same disjoint set
                result[numOfEdges++] = nextEdge; // add the edge to the minimum spanning tree
                union(subsets, x, y); // merge the source and destination vertices into the same disjoint set
            }
        }
        int minCost = 0; // minCost is the total weight of the minimum spanning tree
        for(int i=0; i<numOfEdges; i++){
            System.out.println(result[i].head + " -- " + result[i].tail + " == " + result[i].weight);
            minCost += result[i].weight;
        }
        System.out.println(minCost);
    }
    public static void main(String[] args){
        int n,m;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        List<Edge> edges = new ArrayList<>();
        for(int i=0; i<m; i++){
            int head, tail, weight;
            head = scanner.nextInt();
            tail = scanner.nextInt();
            weight = scanner.nextInt();
            edges.add(new Edge(head, tail, weight));
        }
        kruskals(n, edges);
        scanner.close();
    }
}