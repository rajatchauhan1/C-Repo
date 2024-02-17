#include <bits/stdc++.h> // This includes all standard libraries
using namespace std;

class Graph
{
    int V; // No. of vertices
    vector<list<int>> adj; // Adjacency list representation

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Function to add an edge to the graph
    void BFS(int s); // Function for Breadth First Search
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V); // Resizing adjacency list to the number of vertices
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    vector<bool> visited; // Array to keep track of visited vertices
    visited.resize(V, false); // Initially all vertices are not visited
    list<int> queue; // Queue for BFS traversal

    visited[s] = true; // Mark the current node as visited and enqueue it
    queue.push_back(s);

    while (!queue.empty()) // While there are vertices in queue
    {
        s = queue.front(); // Dequeue a vertex from queue and print it
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s. If an adjacent
        // has not been visited, then mark it visited and enqueue it.
        for (auto adjacent : adj[s])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    Graph g(4); // Create a graph with 4 vertices
    g.addEdge(0, 1); // Add edges to the graph
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2); // Perform BFS traversal starting from vertex 2
    return 0;
}




//DFS Start here 



#include <bits/stdc++.h>
using namespace std;
#define N 100000

// To keep correct and reverse direction
vector<int> gr1[N], gr2[N]; // Adjacency lists for both directions
bool vis1[N], vis2[N]; // Arrays to mark visited nodes

// Function to add edges to both directions
void Add_edge(int u, int v)
{
    gr1[u].push_back(v); // Add edge from u to v
    gr2[v].push_back(u); // Add edge from v to u
}

// DFS function for the first direction
void dfs1(int x)
{
    vis1[x] = true; // Mark node x as visited
    for (auto i : gr1[x]) // Visit all adjacent nodes
        if (!vis1[i]) // If the adjacent node is not visited, recursively call dfs1
            dfs1(i);
}

// DFS function for the reverse direction
void dfs2(int x)
{
    vis2[x] = true; // Mark node x as visited
    for (auto i : gr2[x]) // Visit all adjacent nodes
        if (!vis2[i]) // If the adjacent node is not visited, recursively call dfs2
            dfs2(i);
}

// Function to check if the graph is strongly connected
bool Is_Connected(int n)
{
    // Call DFS for both directions
    memset(vis1, false, sizeof vis1); // Reset visited array for the first direction
    dfs1(1); // Start DFS from node 1 for the first direction
    memset(vis2, false, sizeof vis2); // Reset visited array for the second direction
    dfs2(1); // Start DFS from node 1 for the second direction
    
    // Check if there are any nodes not reachable from node 1 in both directions
    for (int i = 1; i <= n; i++) {
        if (!vis1[i] && !vis2[i]) // If there is a node not reachable from both directions
            return false; // Return false, indicating the graph is not strongly connected
    }
    return true; // If all nodes are reachable from node 1 in both directions, return true
}

int main()
{
    int n = 4; // Number of nodes in the graph
    Add_edge(1, 2); // Add edges to the graph
    Add_edge(1, 3);
    Add_edge(2, 3);
    Add_edge(3, 4);
    if (Is_Connected(n)) // Check if the graph is strongly connected
        cout << "Yes"; // If the graph is strongly connected, print "Yes"
    else
        cout << "No"; // If the graph is not strongly connected, print "No"
    return 0;
}
