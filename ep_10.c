#include <stdio.h>
#include <stdlib.h>

#define INFINITY 999999

typedef struct {
    int src;
    int dest;
} Route;

int min(int a, int b) {
    return (a < b) ? a : b;
}

typedef struct {
    int node;
    int distance;
} Node;

int compareNodes(const void* a, const void* b) {
    int distA = ((Node*)a)->distance;
    int distB = ((Node*)b)->distance;
    return distA - distB;
}

int dijkstra(int N, int M, Route* routes, int C, int R, int E) {
    int i, j, k;
    int** dist = (int**)malloc((N + 1) * sizeof(int*));

    for (i = 1; i <= N; i++) {
        dist[i] = (int*)malloc((N + 1) * sizeof(int));
        for (j = 1; j <= N; j++) {
            dist[i][j] = INFINITY;
        }
    }

    for (i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    for (i = 0; i < M; i++) {
        dist[routes[i].src][routes[i].dest] = 1;
        dist[routes[i].dest][routes[i].src] = 1;
    }

    for (k = 1; k <= N; k++) {
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int minDistance = dist[C][R];
    for (i = 1; i <= N; i++) {
        if (dist[C][i] != INFINITY && dist[i][R] != INFINITY && i != E) {
            minDistance = min(minDistance, dist[C][i] + dist[i][R]);
        }
    }

    for (i = 1; i <= N; i++) {
        free(dist[i]);
    }
    free(dist);

    return minDistance;
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {
        Route* routes = (Route*)malloc(M * sizeof(Route));
        int i;
        for (i = 0; i < M; i++) {
            scanf("%d %d", &routes[i].src, &routes[i].dest);
        }

        int C, R, E;
        scanf("%d %d %d", &C, &R, &E);

        int minHours = dijkstra(N, M, routes, C, R, E);
        printf("%d\n", minHours);

        free(routes);
    }
    return 0;
}
