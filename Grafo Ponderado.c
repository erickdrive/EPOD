#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Estrutura para representar um grafo ponderado
struct Graph {
    int numVertices;
    int graphMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Fun��o para criar um novo grafo
struct Graph createGraph(int numVertices) {
    struct Graph graph;
    graph.numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph.graphMatrix[i][j] = 0; // Inicializa com 0 para indicar aus�ncia de aresta
        }
    }
    return graph;
}

// Fun��o para adicionar uma aresta ponderada
void addEdge(struct Graph* graph, int src, int dest, int weight, bool isDirected) {
    graph->graphMatrix[src][dest] = weight;
    
    if (!isDirected) {
        graph->graphMatrix[dest][src] = weight; // Para um grafo n�o direcionado, a aresta � bidirecional
    }
}

// Fun��o para imprimir o grafo
void printGraph(struct Graph* graph) {
    printf("Matriz de Adjac�ncia do Grafo:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d\t", graph->graphMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices, isDirected;
    printf("Digite o n�mero de v�rtices: ");
    scanf("%d", &numVertices);
    printf("O grafo � direcionado? (1 para sim, 0 para n�o): ");
    scanf("%d", &isDirected);

    struct Graph graph = createGraph(numVertices);

    int numEdges, src, dest, weight;
    printf("Digite o n�mero de arestas: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        printf("Digite a origem, destino e peso da aresta %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight, isDirected);
    }

    printGraph(&graph);

    return 0;
}

