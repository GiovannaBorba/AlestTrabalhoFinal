#include <iostream>
using namespace std;

class Nodo{
  public:
    int element;
    Nodo *father;
    Nodo *left;
    Nodo *right;
    Nodo(int e);
    ~Nodo();
};