#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#include "data_structures.c"
typedef struct Node;
Node* createNode(int data);
int getData(Node* node);
Node* gotoNextNode(Node* node);
Node* gotoPreviousNode(Node* node);
#endif