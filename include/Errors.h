#pragma once
#include "Graph.h"
#include <stdbool.h>

bool EdgesNumberError(int n, int m);

bool NoSpanningError(const Graph *minimal_spanning_tree);

bool VerticesError(int n);

bool EdgeError(int n, int m);

bool VertexError(int node_1, int node_2, int n);


