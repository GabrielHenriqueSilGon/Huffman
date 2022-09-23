#ifndef TREE_HPP
#define TREE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <unordered_map>
#include <list>

using namespace std;

typedef struct Record Record;
typedef struct Tree Tree;

typedef struct Minheap Minheap;
typedef struct seiva seiva;

struct MinHeap
{
  int size;
  int cap;
  struct Tree **vet;
};


struct seiva
{
  unordered_map < string, float >m;
  int Max;
  int Min;
  int Tam;
};

struct Record
{
  float key;
  string word;
};

struct Tree
{
  Record reg;
  Tree *esq, *dir;
};

MinHeap *CreateMinHeap (int capacity);
void swapTree (Tree ** a, Tree ** b);
void HuffmanCodes (seiva * palavra);
void minHeapify (MinHeap * minHeap, int idx);
Tree *extractMin (MinHeap * minHeap);
Tree *newTree (string data, float freq);
void insertMinHeap (struct MinHeap *minHeap, struct Tree *t);
int isSizeOne (struct MinHeap *minHeap);
void buildMinHeap (MinHeap * minHeap);
void printArr(float arr[], int n);
MinHeap *createAndBuildMinHeap (seiva * palavra);
Tree *HuffmanTree (seiva * palavra);
void printCodes (Tree * root, float arr[], int top);
void HuffmanCodes (seiva * palavra);

#endif
