#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad de aristas
    int numEdges() const {
        int edgeCounter = 0;

        for (int i = 0; i < adjMatrix.size(); i++) {
            for (int j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    edgeCounter++;
                }
            }
        }
    
        return edgeCounter;
    }

    // Completa esta función
    // Devuelve el in-degree de un vertice
    int inDegree(int u) const {
        if (u < 0 || u >= numVertices)
            throw out_of_range("Vertice fuera de rango");
        else {
            int inCounter = 0;

            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[u][i] == 1) {
                    inCounter++;
                }
            }

            return inCounter;
        }
    }

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    bool isInfluencer(int u) const  {
        
        int influencer = 0;
        for (int i = 1; i < adjMatrix.size(); i++) {
            if (inDegree(u) > inDegree(influencer)) {
                influencer = u;
            }
        }
        
        if (influencer == u) { return true; }
        else { return false; }
    }
};

