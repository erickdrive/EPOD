#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

// Estrutura para representar um grafo
struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int isDirected;
};

// Função para criar um grafo com 'numVertices' vértices
struct Graph* createGraph(int numVertices, int isDirected) {
	int i,j;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->isDirected = isDirected;

    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;

    if (!graph->isDirected) {
        graph->adjMatrix[dest][src] = 1;
    }
}

// Função para remover uma aresta do grafo
void removeEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 0;

    if (!graph->isDirected) {
        graph->adjMatrix[dest][src] = 0;
    }
}

// Função de busca em profundidade (DFS)
void DFS(struct Graph* graph, int startVertex, int targetVertex, bool* visited, int* path, int* pathIndex) {
	int i;
    visited[startVertex] = true;
    path[(*pathIndex)++] = startVertex;

    if (startVertex == targetVertex) {
        printf("Caminho encontrado: ");
        for (i = 0; i < *pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }

    for (i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[startVertex][i] == 1 && !visited[i]) {
            DFS(graph, i, targetVertex, visited, path, pathIndex);
        }
    }

    (*pathIndex)--;
    visited[startVertex] = false;
}

// Função para realizar a busca em profundidade
void performDFS(struct Graph* graph, int startVertex, int targetVertex) {
	int i;
    if (startVertex < 0 || startVertex >= graph->numVertices || targetVertex < 0 || targetVertex >= graph->numVertices) {
        printf("Vértices inválidos.\n");
        return;
    }

    bool visited[MAX_VERTICES];
    int path[MAX_VERTICES];
    int pathIndex = 0;

    for (i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    printf("Iniciando busca em profundidade de %d para %d:\n", startVertex, targetVertex);
    DFS(graph, startVertex, targetVertex, visited, path, &pathIndex);
    if (pathIndex == 0) {
        printf("Nenhum caminho encontrado.\n");
    }
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
	int i,j;
    printf("Matriz de Adjacência:\n");
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices, isDirected;
    printf("Escolha o tipo de grafo:\n");
    printf("1. Grafo não dirigido\n");
    printf("2. Grafo dirigido\n");
    printf("Digite a opção (1 ou 2): ");
    scanf("%d", &isDirected);

    printf("Digite o número de vértices do grafo: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices, isDirected);

    int choice, src, dest, startVertex, targetVertex;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar conexão\n");
        printf("2. Remover conexão\n");
        printf("3. Realizar busca em profundidade\n");
        printf("4. Imprimir grafo\n");
        printf("5. Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o vértice de origem: ");
                scanf("%d", &src);
                printf("Digite o vértice de destino: ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                printf("Conexão adicionada.\n");
                break;
            case 2:
                printf("Digite o vértice de origem: ");
                scanf("%d", &src);
                printf("Digite o vértice de destino: ");
                scanf("%d", &dest);
                removeEdge(graph, src, dest);
                printf("Conexão removida.\n");
                break;
            case 3:
                printf("Digite o vértice de início da busca: ");
                scanf("%d", &startVertex);
                printf("Digite o vértice de destino da busca: ");
                scanf("%d", &targetVertex);
                performDFS(graph, startVertex, targetVertex);
                break;
            case 4:
                printGraph(graph);
                break;
            case 5:
                free(graph);
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}

