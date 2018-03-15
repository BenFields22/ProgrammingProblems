//
//  dfs.cpp
//  C++Practice
//
//  Created by Benjamin G Fields on 3/14/18.
//  Copyright © 2018 Benjamin G Fields. All rights reserved.
//

// A simple representation of graph using STL,
// for the purpose of competitive programming
//adjacency list implementation
#include <vector>
#include <iostream>
#include <list>
#include "xlsxwriter.h"

using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(int u, vector<int> adj[],
             vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}

// This function does DFSUtil() for all
// unvisited vertices.
void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}

class Graph
{
    int V;    // No. of vertices
    
    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
public:
    Graph(int V);  // Constructor
    
    // function to add an edge to graph
    void addEdge(int v, int w);
    
    // prints BFS traversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    // Create a queue for BFS
    list<int> queue;
    
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// Driver code
int main()
{
    //testing out writing to excel files
    /* Create a workbook and add a worksheet. */
    lxw_workbook  *workbook  = workbook_new("tutorial01.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    /* Start from the first cell. Rows and columns are zero indexed. */
    int row = 0;
    int col = 0;
    worksheet_write_string(worksheet, row, col,     "This is a new string", NULL);
    worksheet_write_number(worksheet, row, col + 1, 1.234, NULL);
    workbook_close(workbook);
    //********************************************************
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    DFS(adj, V);
    cout<<endl;
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "Following is Breadth First Traversal "
    << "(starting from vertex 2) \n";
    g.BFS(2);
    cout<<endl;
    return 0;
}
