#pragma once

#include <iostream>
#include <assert.h>
#include <set>
#include <queue>

using namespace std;

/**
 * Tidak seperti LL, Stack, dan Queue yang sudah ada templatenya,
 * implementasi Graph sesuai dengan kebutuhan per soal.
 *
 * Salah satu representasi Graph yang umum digunakan adalah: Adjacency Matrix.
 * Di mana array 2D digunakan untuk merepresentasikan keberadaan dan nilai weight dari edge antar Vertex.
 * Class `GraphAdjMatrix` di bawah adalah contoh implementasi yang diwrap di dlm sebuah class.
 * Implementasi praktikum & kelas lain bisa beda. Gunakan yang enak buat kalian mikir.
 *
 * Di class GraphAdjMatrix ini, untuk merepresentasikan keberadaan edge dan weight,
 * dengan A dan B sebagai index kedua vertex, dan matrix sebagai array 2D yang menyimpan nilai edge"
 * antar vertex, dapat ditulis bahwa `weightEdgeAB = matrix[A][B]`.
 * Apabila unweighted, maka keberadaan edge bisa ditandai dengan diisi nilai 1.
 * Apabila undirected, maka matrix[A][B] dan matrix[B][A] harus diisi.
 * 
 * Implementasi setiap method ada di AdjMatrix.cpp.
*/
class GraphAdjMatrix {
private:
    int** matrix;
    int vertex_count;
    void dfs(int current, set<int>& visited);
public:
    GraphAdjMatrix(int vertex_count);
    ~GraphAdjMatrix();
    void add_edge(int vertex_a, int vertex_b, int weight);
    void print_dfs(int start);
    void print_bfs(int start);
};
