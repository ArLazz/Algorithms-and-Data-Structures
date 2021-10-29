#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define edge pair<int,int>
class Graph {
private:
    vector<pair<int, edge>> G;
    vector<pair<int, edge>> T;
    int *parent;
    int V;
public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
    void print_weight();
};
Graph::Graph(int V) {
    parent = new int[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}
void Graph::kruskal() {
    int i, uRep, vRep;
    sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep) {
            T.push_back(G[i]);
            union_set(uRep, vRep);
        }
    }
}
void Graph::print() {
    cout << "Edge :" << " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
        cout << T[i].second.first << " - " << T[i].second.second << " : "
             << T[i].first;
        cout << endl;
    }
}
void Graph::print_weight() {
    int count = 0;
    for (int i = 0; i < T.size(); i++) {
        count += T[i].first;
    }
    printf("%d\n", count);
}
int main() {
    int n;
    scanf("%d", &n);
    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int weight;
            scanf("%d", &weight);
            if (i != j) {
                g.AddWeightedEdge(i, j, weight);
            }
        }
    }
    g.kruskal();
    g.print_weight();
}