#include "AdjMatrix.h"

void GraphAdjMatrix::dfs(int current, set<int>& visited) {
    for (int i = 0; i < vertex_count; i++) {
        if (visited.find(i) != visited.end()) continue;
        
        int weight = matrix[current][i];
        if (weight == 0) continue;
        
        visited.insert(i);
        cout << "Vertex " << current << " to Vertex " << i 
            << " with weight: " << weight << "\n";
        dfs(i, visited);
    }
}

GraphAdjMatrix::GraphAdjMatrix(int vertex_count) : vertex_count(vertex_count) {
    matrix = new int*[vertex_count];
    for (int i = 0; i < vertex_count; i++) {
        matrix[i] = new int[vertex_count];
        for (int j = 0; j < vertex_count; j++) {
            matrix[i][j] = 0;
        }
    }
}

GraphAdjMatrix::~GraphAdjMatrix() {
    for (int i = 0; i < vertex_count; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void GraphAdjMatrix::add_edge(int vertex_a, int vertex_b, int weight) {
    assert(vertex_a >= 0 && vertex_a < vertex_count &&
            vertex_b >= 0 && vertex_b < vertex_count);
    matrix[vertex_a][vertex_b] = weight;
}

void GraphAdjMatrix::print_dfs(int start) {
    set<int> visited = { start };
    dfs(start, visited);
}

void GraphAdjMatrix::print_bfs(int start) {
    queue<int> visit_queue;
    set<int> visited = { start };
    visit_queue.push(start);

    while (! visit_queue.empty()) {
        int to_visit = visit_queue.front();
        visit_queue.pop();

        cout << "Vertex " << to_visit << "\n";
        for (int i = 0; i < vertex_count; i++) {
            if (visited.find(i) != visited.end()) continue;
            int weight = matrix[to_visit][i];
            if (weight == 0) continue;
            visit_queue.push(i);
            visited.insert(i);
        }
    }
}
