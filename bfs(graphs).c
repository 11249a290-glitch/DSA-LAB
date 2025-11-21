#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX], front = 0, rear = 0;
int visited[MAX];
void enqueue(int v) { queue[rear++] = v; }
int dequeue() { return queue[front++]; }
void bfs(int graph[][MAX], int n, int start) 
{
  enqueue(start);
  visited[start] = 1;
  while (front < rear) {
  int v = dequeue();
  printf("%d ", v);
  for (int i = 0; i < n; i++) {
  if (graph[v][i] && !visited[i]) {
  enqueue(i);
 visited[i] = 1;
  }
  }
  }
}

int main()
{
    int n = 6;
    int graph[MAX][MAX] = {0};
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[2][5] = graph[5][2] = 1;
    printf("BFS starting from vertex 0:\n");
    bfs(graph, n, 0);
    return 0;
}
