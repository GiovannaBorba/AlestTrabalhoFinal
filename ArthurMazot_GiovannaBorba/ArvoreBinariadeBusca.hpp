#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#include "Nodo.hpp"

class ArvoreBinariadeBusca{
private:
  Nodo *root;
  int count;
  int cop;
public:
  ArvoreBinariadeBusca();
  ~ArvoreBinariadeBusca();
  void add(int e);
  Nodo *add(Nodo *r, int e, Nodo *f);
  Nodo *getParent(int e);
  void clear();
  bool contains(int e);
  Nodo *contains(int e, Nodo *n);
  int height();
  int height(Nodo *n);
  int size();
  bool isEmpty();
  ArvoreBinariadeBusca *clone();
  void AVL(Nodo *n);
  void print();
  void print(int height, Nodo *aux);
  vector<int> Pre();
  void Pre(Nodo *n, vector<int> &v);
  vector<int> Pos();
  void Pos(Nodo *n, vector<int> &v);
  vector<int> Cen();
  void Cen(Nodo *n, vector<int> &v);
};