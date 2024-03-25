#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int **vertices;
  int numVertices;
} Grafo;

typedef struct {
  int de;
  int para;
} Aresta;

Grafo inicializarGrafo(int numVertices);
void destruirGrafo(Grafo *grafo);
void inserirAresta(Grafo *grafo, Aresta aresta);
void imprimirGrafo(Grafo grafo);

int main() {
  int numVertices;
  printf("Informe o numero de vertices: ");
  scanf("%d", &numVertices);

  Grafo grafo = inicializarGrafo(numVertices);

  for (int i = 0; i <= numVertices; ++i) {
    Aresta aresta;
    printf("Informe a aresta %d (de para): ", i + 1);
    scanf("%d %d", &aresta.de, &aresta.para);
    inserirAresta(&grafo, aresta);
  }

  printf("\nGrafo:\n");
  imprimirGrafo(grafo);

  destruirGrafo(&grafo);

  return 0;
}

Grafo inicializarGrafo(int numVertices) {
  Grafo grafo;
  grafo.numVertices = numVertices;

  // Alocar memoria para a matriz de adjacencia
  grafo.vertices = (int **)malloc(numVertices * sizeof(int *));
  for (int i = 0; i < numVertices; ++i) {
    grafo.vertices[i] = (int *)malloc(numVertices * sizeof(int));
    for (int j = 0; j < numVertices; ++j) {
      grafo.vertices[i][j] = 0;
    }
  }

  return grafo;
}

void destruirGrafo(Grafo *grafo) {
  // Liberar memoria alocada para a matriz de adjacencia
  for (int i = 0; i < grafo->numVertices; ++i) {
    free(grafo->vertices[i]);
  }
  free(grafo->vertices);
}

void inserirAresta(Grafo *grafo, Aresta aresta) {
  if (aresta.de >= 0 && aresta.de < grafo->numVertices && aresta.para >= 0 &&
      aresta.para < grafo->numVertices) {
    grafo->vertices[aresta.de][aresta.para] = 1;
    // Se o grafo e nao direcionado, descomente a linha abaixo para adicionar a
    // aresta inversa grafo->vertices[aresta.para][aresta.de] = 1;
  } else {
    printf("Vertices invalidos na aresta.\n");
  }
}

void imprimirGrafo(Grafo grafo) {
  for (int i = 0; i < grafo.numVertices; ++i) {
    for (int j = 0; j < grafo.numVertices; ++j) {
      printf("%d ", grafo.vertices[i][j]);
    }
    printf("\n");
  }
}
