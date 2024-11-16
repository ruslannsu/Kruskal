#include "Errors.h"
#include "Graph.h"
#include <stdio.h>



bool NoSpanningError(const Graph *minimal_spanning_tree)
{
    if (minimal_spanning_tree->edge_last != minimal_spanning_tree->node_count - 1)
    {
        return false;
    }
    return true;
}



bool VerticesError(int n)
{
    if ((n > 5000) || (n < 0))
    {
        return false;
    }
    return true;
}

bool EdgeError(int n, int m)
{
    if ((m < 0) || (m > (n * (n + 1) / 2)))
    {
        return false;
    }
    return true;
}

bool VertexError(int node_1, int node_2, int n)
{
    if ((node_1 > n) || (node_1 < 1))
    {
        return false;
    }
    if ((node_2 > n) || (node_2 < 1))
    {
        return false;
    }
    return true;
}

