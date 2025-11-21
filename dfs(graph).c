#include <stdio.h>
#define MAX 100
int visited[MAX];
void dfs(int graph[][MAX], int n, int v)
 {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, n, i);
  }
  }
}

int main() {
    int n = 6;
    int graph[MAX][MAX] = {0};
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[2][5] = graph[5][2] = 1;
    printf("DFS starting from vertex 0:\n");
    dfs(graph, n, 0);
    return 0;
}
