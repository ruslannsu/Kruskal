#pragma once

typedef struct Edge
{
    int start;
    int end;
    int length;
} Edge;

typedef struct Graph
{
    int node_count;
    int edges_count;
    int edge_last;
    Edge *edges;
} Graph;

Graph *CreateGraph(int node_count, int edges_count);

void AddEdge(Graph *graph, int start, int end, int length);

void DestroyGraph(Graph *graph);
