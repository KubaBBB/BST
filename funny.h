#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#ifndef fun
#define fun

void keyMIN( node *root);

void keyMAX (node *root);
void inOrder(node* root);
int countNode(node * currentNode, int *);
void wypisz(node *root);
void simulation(node *root);

#endif
