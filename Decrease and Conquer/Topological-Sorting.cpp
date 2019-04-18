/**********************************************
  Kahn's algorithm (1962)
  Also True with Direct Graphs having cycles 
**********************************************/

#include<iostream> 
#include <list> 
#include <stack> 
using namespace std; 
  
class Graph 
{ 
    int V;    
    list<int> *adj; 
    bool* flag;

    void topologicalSortBreadth(int v, bool visited[], stack<int> &Stack); 
public: 
    Graph(int V);  
    void addEdge(int v, int w); 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
    flag= new bool[V];
    for(int i=0;i<V;i++) flag[i]=false;
} 
  
void Graph::addEdge(int v, int w) 
{ 
    flag[w] = true;
    adj[v].push_back(w);
} 
  
void Graph::topologicalSortBreadth(int v, bool visited[],  stack<int> &Stack) 
{ 
    visited[v] = true; 
  
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortBreadth(*i, visited, Stack); 
  
    Stack.push(v); 
} 
 
void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    for (int i = 0; i < V; i++) 
      if (flag[i] == false) 
        topologicalSortBreadth(i, visited, Stack); 
  
    
    while (Stack.empty() == false) 
    { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
    
    cout<<"\n";
} 
  
int main() 
{ 
    Graph g(8); 
    g.addEdge(2, 7); 
    g.addEdge(7, 0); 
    g.addEdge(7, 5); 
    g.addEdge(7, 6);
    g.addEdge(3, 7);
    g.addEdge(3, 4);
    g.addEdge(1, 6);
    g.addEdge(1, 4);
    g.addEdge(4, 5);

    
  
    cout << "Topological Sort: \n"; 
    g.topologicalSort();  
  
    return 0; 
} 
