#include "tree.hpp"

MinHeap *
CreateMinHeap (int capacity)
{
  MinHeap *minHeap = (MinHeap *) malloc (sizeof (MinHeap));

  minHeap->size = 0;

  minHeap->cap = capacity;

  minHeap->vet = (Tree **) malloc (minHeap->cap * sizeof (Tree *));
  return minHeap;
}


void
minHeapify (MinHeap * minHeap, int idx)
{

  int menor = idx;
  int esq = 2 * idx + 1;
  int dir = 2 * idx + 2;

  if (esq < minHeap->size
      && minHeap->vet[esq]->reg.key < minHeap->vet[menor]->reg.key)
    menor = esq;

  if (dir < minHeap->size
      && minHeap->vet[dir]->reg.key < minHeap->vet[menor]->reg.key)
    menor = dir;

  if (menor != idx)
    {
      swapTree (&minHeap->vet[menor], &minHeap->vet[idx]);
      minHeapify (minHeap, menor);
    }
}

void
swapTree (Tree ** a, Tree ** b)
{

  Tree *t = *a;
  *a = *b;
  *b = t;
}

Tree *
extractMin (MinHeap * minHeap)
{

  Tree *temp = minHeap->vet[0];
  minHeap->vet[0] = minHeap->vet[minHeap->size - 1];

  --minHeap->size;
  minHeapify (minHeap, 0);

  return temp;
}

Tree *
newTree (string data, float freq)
{
  struct Tree *temp = (struct Tree *) malloc (sizeof (struct Tree));

  temp->dir = temp->esq = NULL;
  temp->reg.word = data;
  temp->reg.key = freq;

  return temp;
}


void
insertMinHeap (struct MinHeap *minHeap, struct Tree *t)
{
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && t->reg.key < minHeap->vet[(i - 1) / 2]->reg.key)
    {

      minHeap->vet[i] = minHeap->vet[(i - 1) / 2];
      i = (i - 1) / 2;
    }

  minHeap->vet[i] = t;
}

int
isSizeOne (struct MinHeap *minHeap)
{

  return (minHeap->size == 1);
}

void
buildMinHeap (MinHeap * minHeap)
{

  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    minHeapify (minHeap, i);
}

int
isLeaf (Tree * root)
{

  return !(root->esq) && !(root->dir);
}

void
printArr (float arr[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
    cout << arr[i];

  cout << endl;
}


MinHeap *
createAndBuildMinHeap (seiva * palavra)
{
  int i = 0;
  MinHeap *minHeap = CreateMinHeap (palavra->Tam);

  unordered_map < string, float >::iterator it;
  for (it = palavra->m.begin (); it != palavra->m.end (); it++)
    {
      minHeap->vet[i] = newTree (it->first, it->second);
      i++;
    }

  minHeap->size = palavra->Tam;
  buildMinHeap (minHeap);

  return minHeap;
}

Tree *
HuffmanTree (seiva * palavra)
{
  Tree *left, *right, *top;

  struct MinHeap *minHeap = createAndBuildMinHeap (palavra);

  while (!isSizeOne (minHeap))
    {

      left = extractMin (minHeap);
      right = extractMin (minHeap);

      top = newTree ("$", left->reg.key + right->reg.key);

      top->dir = left;
      top->esq = right;

      insertMinHeap (minHeap, top);
    }

  return extractMin (minHeap);
}

void
printCodes (Tree * root, float arr[], int top)
{

  if (root->esq)
    {

      arr[top] = 0;
      printCodes (root->esq, arr, top + 1);
    }

  if (root->dir)
    {

      arr[top] = 1;
      printCodes (root->dir, arr, top + 1);
    }

  if (isLeaf (root))
    {

      cout << root->reg.word << ": ";
      printArr (arr, top);
    }
}

void
HuffmanCodes (seiva * palavra)
{
  Tree *root = HuffmanTree (palavra);
  float arr[palavra->Tam], top = 0;

  printCodes (root, arr, top);
}
