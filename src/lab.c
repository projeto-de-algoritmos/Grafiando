#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

/* Definindo o tipo do vertice, que é a unidade básica de um grafo */

#define vertex int

/* Definindo a estrutura no da lista de adjacencia */

typedef struct node *link;

struct node
{
  vertex w;
  link next;
};

/* Definindo a estrutura grafo utilizando lista de adjacencia*/

struct graph
{
  int V;     // Número de vértices
  int E;     // Número de aréstas
  link *adj; // Lista de adjacencia
};

/* Definição do Graph que é um ponteiro para um grafo */

typedef struct graph *Graph;

/* Definição da estrutura Edge "aresta" */

typedef struct
{
  vertex v, w;
} Edge;

/* Funções básicas para construção e manipulação de grafos */

Graph GRAPHinit(int V);
static link NEWnode(vertex w, link next);
Edge EDGE(vertex v, vertex w);
void GRAPHinsert(Graph G, Edge E);
void GRAPHremove(Graph G, Edge E);
int GRAPHEdges(Edge[], Graph G);
void GRAPHshow(Graph G);
Graph GRAPHcopy(Graph G);
void GRAPHdestroy(Graph G);

/* Funções básicas para construção e manipulação de grafos */

/* Inicialização de um grafo */

Graph GRAPHinit(int V)
{
  Graph G = malloc(sizeof *G);
  G->V = V;
  G->E = 0;
  G->adj = malloc(V * sizeof(link));
  vertex v;
  for (v = 0; v < V; ++v)
    G->adj[v] = NULL;
  return G;
}

/* Inicialização da lista de adjacencia */

static link NEWnode(vertex w, link next)
{

  link l = malloc(sizeof(struct node));
  l->w = w;
  l->next = next;
  return l;
}

/* Função para montagem de um Edge */

Edge EDGE(vertex v, vertex w)
{
  Edge E = {.v = v, .w = w};
  return E;
}

/* Inserção de uma aresta ao grafo */

void GRAPHinsert(Graph G, Edge E)
{
  vertex v = E.v, w = E.w;
  link a;
  for (a = G->adj[v]; a != NULL; a = a->next)
    if (a->w == w)
      return;
  G->adj[v] = NEWnode(w, G->adj[v]);
  G->adj[w] = NEWnode(v, G->adj[w]);
  G->E++;
}

/* Remoção de uma aresta do grafo */

void GRAPHremove(Graph G, Edge E)
{

  vertex v = E.v, w = E.w;
  link a;

  for (a = G->adj[v]; a != NULL; a = a->next)
  {
    if (a->w == w)
    {
      free(a);
      break;
    }
  }

  link b;

  for (b = G->adj[w]; b != NULL; b = b->next)
  {
    if (b->w == v)
    {
      free(b);
      break;
    }
  }
  G->E--;
}
/*int GRAPHEdges(Edge[], Graph G);*/

/* Impressão do grafo */

void GRAPHshow(Graph G)
{
  vertex v;
  for (v = 0; v < G->V; v++)
  {
    printf("%2d:", v);
    link a;
    for (a = G->adj[v]; a != NULL; a = a->next)
      printf("%2d", a->w);
    printf("\n");
  }
}
/*Graph GRAPHcopy(Graph G);*/

/* Destroi o grafo */

void GRAPHdestroy(Graph G)
{

  vertex r = G->V;
  vertex i;
  for (i = 0; i < r; i++)
  {
    link a = G->adj[i];
    while (a != NULL)
    {
      link temp = a;
      a = a->next;
      free(temp);
    }
  }

  free(G->adj);

  free(G);
}
int GRAPHEdges(Edge a[], Graph G)
{
  int v, e = 0;
  link t;

  for (v = 0; v < G->V; v++)
  {
    for (t = G->adj[v]; t != NULL; t = t->next)
      if (v < t->w)
        a[e++] = EDGE(v, t->w);
  }

  return e;
}

typedef struct queue *Queue;

struct queue
{
  vertex *q;
  int f, l;
};

Queue QUEUEinit(int N);
int QUEUEempty(Queue q);
vertex QUEUEget(Queue q);
void QUEUEput(Queue q, vertex x);
void QUEUEfree(Queue q);

Queue QUEUEinit(int N)
{
  Queue q = malloc(sizeof *q);
  q->q = malloc(sizeof(vertex) * N);
  q->f = q->l = 0;
  return q;
}
int QUEUEempty(Queue q)
{
  return (q->f >= q->l);
}
vertex QUEUEget(Queue q)
{
  return q->q[q->f++];
}
void QUEUEput(Queue q, vertex x)
{
  q->q[q->l++] = x;
}
void QUEUEfree(Queue q)
{
  free(q->q);
  free(q);
}

static int num[MAX];
int passos = 0;
void GRAPHbfs(Graph G, vertex s);

void GRAPHbfs(Graph G, vertex s)
{
  int cnt = 0;
  vertex v;
  for (v = 0; v < G->V; v++)
    num[v] = -1;
  Queue q = QUEUEinit(G->V);
  num[s] = cnt++;
  QUEUEput(q, s);

  while (!QUEUEempty(q))
  {
    vertex v = QUEUEget(q);
    link a;
    for (a = G->adj[v]; a != NULL; a = a->next)
    {
      passos++;
      if (num[a->w] == -1)
      {
        num[a->w] = cnt++;
        QUEUEput(q, a->w);
      }
    }
  }

  QUEUEfree(q);
}
int main(void)
{
  int v, a, inicial, T;
  vertex s, t;

    passos = 0;
    scanf("%d", &inicial);
    scanf("%d %d", &v, &a);
    Graph g = GRAPHinit(v);

    while (a--)
    {
      scanf("%d %d", &s, &t);
      Edge e = EDGE(s, t);
      GRAPHinsert(g, e);
    }

    GRAPHbfs(g, inicial);

    printf("##############################################################\n");
    printf("### O Minimo de passos para gerar esse mapa, são %d passos ###\n",passos);
    printf("##############################################################\n");
   
   
  
    GRAPHdestroy(g);
  
}