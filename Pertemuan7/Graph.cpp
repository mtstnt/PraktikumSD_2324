#include "AdjMatrix.h"

using namespace std;

// Buka file AdjMatrix.h untuk detailnya.
int main() {
    GraphAdjMatrix graph(3);
    graph.add_edge(0, 1, 0);
    graph.add_edge(0, 2, 1);
    graph.add_edge(2, 1, 1);

    cout << "Printing DFS starting at Vertex 0\n";
    graph.print_dfs(0);

    cout << "Printing BFS starting at Vertex 0\n";
    graph.print_bfs(0);
    return 0;
}
