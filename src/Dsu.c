#include "Dsu.h"
#include <stdlib.h>
#include <assert.h>

Tree *CreateDsu(int count)
{
    Tree *DsuTree = malloc(sizeof(Tree));
    assert(DsuTree != NULL);
    DsuTree->parent = calloc(count, sizeof(int));
    assert(DsuTree->parent != NULL);
    for (int i = 0; i < count; i++)
    {
        DsuTree->parent[i] = i + 1;
    }
    DsuTree->rank = calloc(count, sizeof(int));
    assert(DsuTree->rank);
    return DsuTree;
}

int Find(int element, Tree *tree)
{
    if (tree->parent[element - 1] == element)
    {
        return element;
    }
    return tree->parent[element - 1] = Find(tree->parent[element - 1], tree);
}

void UniteSets(int element_1, int element_2, Tree *tree)
{
    int set_1 = Find(element_1, tree);
    int set_2 = Find(element_2, tree);
    if (set_1 == set_2)
    {
        return;
    }

    if (tree->rank[set_1 - 1] < tree->rank[set_2 - 1])
    {
        tree->parent[set_1 - 1] = set_2;
    }
    else
    {
        tree->parent[set_2 - 1] = set_1;
        if (tree->rank[set_1 - 1] == tree->rank[set_2 - 1])
        {
            tree->rank[set_1 - 1]++;
        }
    }
}

void DestroyDsuTree(Tree *DsuTree)
{
    free(DsuTree->rank);
    free(DsuTree->parent);
    free(DsuTree);
}
