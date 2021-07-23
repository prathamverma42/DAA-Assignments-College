#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
    int src, dest;
};
class Graph
{
public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int N)
    {
        adjList.resize(N);
        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
void DFS(Graph const &graph, int v, vector<bool> &visited)
{
    visited[v] = true;
    for (int u : graph.adjList[v])
    {
        if (!visited[u])
        {
            DFS(graph, u, visited);
        }
    }
}
bool isConnected(Graph const &graph, int N)
{
    vector<bool> visited(N);
    for (int i = 0; i < N; i++)
    {
        if (graph.adjList[i].size())
        {
            DFS(graph, i, visited);
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && graph.adjList[i].size() > 0)
        {
            return false;
        }
    }

    return true;
}
int countOddVertices(Graph const &graph)
{
    int count = 0;
    for (vector<int> list : graph.adjList)
    {
        if (list.size() & 1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<Edge> edges = {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};

    int N = 5;
    Graph graph(edges, N);
    bool is_connected = isConnected(graph, N);
    int odd = countOddVertices(graph);

    if (is_connected && (odd == 0 || odd == 2))
    {
        cout << "The graph has an Eulerian path" << endl;
        if (odd == 0)
        {
            cout << "The graph has an Eulerian circuit" << endl;
        }
        else
        {
            cout << "The Graph is Semi–Eulerian" << endl;
        }
    }
    else
    {
        cout << "The Graph is not Eulerian" << endl;
    }

    return 0;
}