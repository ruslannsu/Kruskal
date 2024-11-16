#include "Graph.h"
#include <stdlib.h>
#include <assert.h>

Graph *CreateGraph(int node_count, int edges_count)
{
    Graph *graph = malloc(sizeof(Graph));
    assert(graph != NULL);
    graph->node_count = node_count;
    graph->edges_count = edges_count;
    graph->edge_last = 0;
    graph->edges = calloc(graph->edges_count,sizeof(Edge));
    assert(graph->edges != NULL);
    return graph;
}

void AddEdge(Graph *graph, int start, int end, int length)
{
    graph->edges[graph->edge_last].start = start;
    graph->edges[graph->edge_last].end = end;
    graph->edges[graph->edge_last].length = length;
    graph->edge_last++;
}

void DestroyGraph(Graph *graph)
{
    free(graph->edges);
    free(graph);
}
