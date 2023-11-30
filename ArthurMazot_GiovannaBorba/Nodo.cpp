#include "Nodo.hpp"

Nodo::Nodo(int e){
  left = NULL;
  right = NULL;
  father = NULL;
  element = e;}

Nodo::~Nodo(){
  delete left;
  delete right;}