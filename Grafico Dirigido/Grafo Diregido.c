#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura para representar o grafo com matriz de adjacências
struct Graph {
    int numVertices;
    bool** adjMatrix;
};

// Função para criar um grafo com 'numVertices' vértices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjMatrix = (bool**)malloc(numVertices * sizeof(bool*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (bool*)malloc(numVertices * sizeof(bool));
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = false;
        }
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    // Adiciona uma aresta do src ao dest
    graph->adjMatrix[src][dest] = true;
}

// Função para realizar a busca em largura
void BFS(struct Graph* graph, int startVertex) {
    // Cria uma fila para a busca em largura
    int queue[graph->numVertices];
    int front = 0, rear = 0;
    queue[rear++] = startVertex;

    // Marca o vértice de início como visitado
    bool visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }
    visited[startVertex] = true;

    printf("Resultado da Busca em Largura (BFS):\n");

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }

    printf("\n");
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
    printf("Matriz de Adjacências:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices;

    printf("Digite o número de vértices do grafo: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    int choice, src, dest;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar aresta\n");
        printf("2. Realizar Busca em Largura (BFS)\n");
        printf("3. Imprimir grafo\n");
        printf("4. Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o vértice de origem: ");
                scanf("%d", &src);
                printf("Digite o vértice de destino: ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Digite o vértice de início da Busca em Largura (BFS): ");
                scanf("%d", &src);
                printf("Resultado da Busca em Largura (BFS) a partir do vértice %d:\n", src);
                BFS(graph, src);
                break;
            case 3:
                printGraph(graph);
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}

