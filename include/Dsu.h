#pragma once

typedef struct Tree
{
    int *parent;
    int *rank;
} Tree;

int Find(int element, Tree *tree);

void UniteSets(int element_1, int element_2, Tree *tree);

Tree *CreateDsu(int count);

void DestroyDsuTree(Tree *DsuTree);

