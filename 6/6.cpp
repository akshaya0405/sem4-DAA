#include<bits/stdc++.h>
using namespace std;

int V;



int minDistance(int distance[],bool sptSet[]){

    int minDist=INT_MAX;
    int minVertex=0;
    for(int i=0;i<V;i++){
        if(sptSet[i]==false && distance[i]<=minDist){
            minDist=distance[i];
            minVertex=i;
        }
    }
    return minVertex;
}

void printSolution(int dist[])
{
    cout << "\nVertex \t\t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}


void dijkstra(int **graph, int src)
{
    int dist[V];

    bool sptSet[V];

    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;  // All s=distance initialised to INF
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, sptSet); //u is vertex with min distance

        sptSet[u]=true; // u included

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from u to v,
            // and total weight of path from src to  v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

int main(){

    cout<<"Enter the number of vertices :";
    cin>>V;

    int **graph=new int*[V];
    for(int i=0;i<V;i++)
    {
        graph[i]=new int[V];
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            graph[i][j]=0;
        }
    }

    cout<<"Enter the number of edges :";
    int e; cin >> e;

    for(int i=0;i<e;i++){
        cout<<"\nEnter the Vertices of the edge "<<i<<" :";
        int a,b,w;
        cin>>a>>b;
        cout<<"Enter the Weight of the edge "<<i<<" :";
        cin>>w;

        graph[a][b]=w;
        graph[b][a]=w;
    }





    dijkstra(graph,0);

    return 0;
}