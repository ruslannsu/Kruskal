#include "Graph.h"
#include "KruskalAlg.h"
#include "Errors.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }
    if (!VerticesError(n))
    {
        printf("bad number of vertices");
        return 0;
    }
    int m;
    if (scanf("%d", &m) != 1)
    {
        return 0;
    }
    if ((n == 1) && (m == 0))
    {
        return 0;
    }
    if ((n == 0) || (m == 0))
    {
        printf("no spanning tree");
        return 0;
    }
    if (!EdgeError(n, m))
    {
        printf("bad number of edges");
        return 0;
    }

    Graph *graph = CreateGraph(n, m);
    int start, end, length = 0;
    int edge_counter = 0;
    unsigned long long t_length;
    for (int i = 0; i < m; i++)
    {

        if (scanf("%d %d %llu", &start, &end, &t_length) == 3)
        {

            edge_counter++;
            if (t_length > INT_MAX)
            {
                printf("bad length");
                DestroyGraph(graph);
                return 0;
            }
            else
            {
                length = t_length;
            }
            if (!VertexError(start, end, n))
            {
                printf("bad vertex");
                DestroyGraph(graph);
                return 0;
            }
        }

        AddEdge(graph, start, end, length);
    }
    
    if (edge_counter != m)
    {
        printf("bad number of lines");
        DestroyGraph(graph);
        return 0;
    }
    KruskalAlgorithm(graph);
    return 0;
}
