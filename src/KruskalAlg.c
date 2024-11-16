#include "KruskalAlg.h"
#include "Graph.h"
#include "Dsu.h"
#include "Errors.h"
#include <stdlib.h>
#include <stdio.h>

static int Compare(const void *x, const void *y)
{
    const Edge *X = x;
    const Edge *Y = y;
    return X->length - Y->length;
}

void KruskalAlgorithm(Graph *graph)
{
    Graph *minimal_spanning_tree = CreateGraph(graph->node_count, graph->node_count - 1);
    Tree *dsu_tree = CreateDsu(graph->node_count);
    qsort(graph->edges, graph->edge_last, sizeof(Edge), Compare);
    for (int i = 0; i < graph->edge_last; i++)
    {
        if (Find(graph->edges[i].start, dsu_tree) != Find(graph->edges[i].end, dsu_tree))
        {
            AddEdge(minimal_spanning_tree, graph->edges[i].start, graph->edges[i].end, graph->edges[i].length);
            UniteSets(graph->edges[i].start, graph->edges[i].end, dsu_tree);
        }
    }
    DestroyGraph(graph);
    DestroyDsuTree(dsu_tree);
    if (!NoSpanningError(minimal_spanning_tree))
    {
        printf("no spanning tree");
        DestroyGraph(minimal_spanning_tree);
        return;
    }
    for (int i = 0; i < minimal_spanning_tree->edges_count; i++)
    {
        printf("%d ", minimal_spanning_tree->edges[i].start);
        printf("%d", minimal_spanning_tree->edges[i].end);
        printf("\n");
    }
    DestroyGraph(minimal_spanning_tree);
}
