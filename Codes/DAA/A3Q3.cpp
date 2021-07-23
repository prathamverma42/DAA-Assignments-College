#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void topologicalSortUtil(int start, bool visited[], stack<int> &st)
    {
        visited[start] = true;
        list<int>::iterator i;
        for (i = adj[start].begin(); i != adj[start].end(); ++i)
            if (!visited[*i])
                topologicalSortUtil(*i, visited, st);

        st.push(start);
    }
    void topologicalSort()
    {
        bool visited[V] = {false};
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                topologicalSortUtil(i, visited, st);
        }
        cout << "Topological Sort : " << endl;
        int n = st.size();
        for (int i = 0; i < n; i++)
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
};
int main()
{
    int V = 8;
    Graph g(V);
    g.addEdge(7, 6);
    g.addEdge(7, 5);
    g.addEdge(6, 4);
    g.addEdge(6, 3);
    g.addEdge(5, 4);
    g.addEdge(5, 2);
    g.addEdge(3, 1);
    g.addEdge(2, 1);
    g.addEdge(1, 0);
    g.topologicalSort();
}