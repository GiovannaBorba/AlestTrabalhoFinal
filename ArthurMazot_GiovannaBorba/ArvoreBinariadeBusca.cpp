#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#include "ArvoreBinariadeBusca.hpp"

ArvoreBinariadeBusca::ArvoreBinariadeBusca(){
    root = nullptr;
    count = 0;
    cop = 0;}

ArvoreBinariadeBusca::~ArvoreBinariadeBusca(){
    delete root;}

void ArvoreBinariadeBusca::add(int e){//chama o metodo add passando "root" como parametro
    root = add(root, e, nullptr);
    count++;
    if(!cop)//Se não for uma copia
        AVL(root);}

Nodo *ArvoreBinariadeBusca::add(Nodo *n, int e, Nodo *f){//adciona um Nodo na arvore
    if(n == nullptr){
        Nodo *aux = new Nodo(e);
        aux->father = f;
        return aux;}
    if(e > n->element){
        n->right = add(n->right, e, n);}
    else{
        n->left = add(n->left, e, n);}
    return n;}

Nodo *ArvoreBinariadeBusca::getParent(int e){//retorna o pai do Nodo
    if(contains(e))
        return contains(e, root)->father;
    else 
        return nullptr;}

void ArvoreBinariadeBusca::clear(){//limpa a arvore
    if(!isEmpty()) delete root;
    root = nullptr;
    count = 0;}

bool ArvoreBinariadeBusca::contains(int e){//Verifica se um element esta na arvore
    return contains(e, root);}//Retorna true se achou o element e false se não achou

Nodo *ArvoreBinariadeBusca::contains(int e, Nodo *n){//Parte recursiva do metodo contains()
    if(n == nullptr)//Não achou o element
        return nullptr;
    if(e == n->element)//Retorna o endereço do element que achou
        return n;
    if(e < n->element)
        return contains(e, n->left);//Procura o element a esquerdo do Nodo atual
    else 
        return contains(e, n->right);}//Procura o element a direita do Nodo atual

int ArvoreBinariadeBusca::height(){//retorna a altura da arvore
    return height(root);}

int ArvoreBinariadeBusca::height(Nodo *n){//Retorna a altura da arvore
    if(n == nullptr)
        return 0;
    int altE = height(n->left) + 1;//Acha a altura da esquerda
    int altD = height(n->right) + 1;//Acha a altura da direita
    if(altE > altD) //retorna a maior altura
        return altE;
    else 
        return altD;}

int ArvoreBinariadeBusca::size(){//Retorna o tamanho da arvore
    return count;}

bool ArvoreBinariadeBusca::isEmpty(){//Verifica se arvore esta vazia
    return root == NULL;}

ArvoreBinariadeBusca *ArvoreBinariadeBusca::clone(){//Retorna um ponteiro de uma arvore igual, mas a arvore não é a mesma
    ArvoreBinariadeBusca *lc = new ArvoreBinariadeBusca();
    lc->cop = 1;//"Desativa" o AVL() para a arvore clone, porque atrapalha na hora da copia
    vector<int> v = Pre();
    for(int i = 0; i < v.size(); i++)//Copia a arvore principal para uma arvore clone
        lc->add(v[i]);
    lc->cop = 0;//"Reativa" o AVL() para a arvore clone, porque se adcionar um novo element a arvore se arruma
    return lc;}

void ArvoreBinariadeBusca::AVL(Nodo *n){//Arruma a arvore rotacionando pra esquerda ou pra direita, simples ou duplamente
    if(n == nullptr)
        return;
    AVL(n->left);
    AVL(n->right);
    int FB = height(n->right) - height(n->left);
    if(FB >= 2){//Verifica se precisa de rotação simples pra esquerda
    Nodo *aux;
        if(n->right != nullptr)
            if(height(n->right->right) - height(n->right->left) <= -1){//Verifica se precisa da rotação dupla se sim rotaciona simples pra direita, linhas 84-90
                Nodo *aux150 = n->right->left;  //aux150 e aux200 são porque eu estava olhando essa arvore 
                Nodo *aux200 = n->right;        //  130
                aux150->father = n;             //   "\"
                aux150->right = aux200;         //    200
                aux200->father = aux150;        //   "/"
                aux200->left = nullptr;         //  150 
                n->right = aux150;}
        Nodo *aux150 = n->right; //Rotaciona simples pra esquerda, linhas 91-96
        aux = n->right->left;
        aux150->father = n->father;
        aux150->left = n;
        n->father = aux150;
        n->right = aux;
        if(n == root)
            root = aux150;
        else aux150->father->right = aux150;}
    else if(FB <= -2){//Verifica se precisa de rotação simples pra direita
    Nodo *aux;
        if(n->left != nullptr)
            if(height(n->left->right) - height(n->left->left) >= 1){//Verifica se precisa da rotação dupla se sim rotaciona simples pra esquerda linhas 103-110
                Nodo *aux150 = n->left->right;
                Nodo *aux200 = n->left;
                aux150->father = n;
                aux150->left = aux200;
                aux200->father = aux150;
                aux200->right = nullptr;
                n->left = aux150;}
        Nodo *aux150 = n->left;//Rotaciona pra simples pra direita, linhas 112-116
        aux = n->left->right;
        aux150->father = n->father;
        aux150->right = n;
        n->father = aux150;
        n->left = aux;
        if(n == root)
            root = aux150;
        else aux150->father->left = aux150;}}

void ArvoreBinariadeBusca::print(){//Mostra a arvore
    print(0, root);}

void ArvoreBinariadeBusca::print(int height, Nodo *aux){//Parte recursiva do metodo print()
    string tracinhos;
    for(int i = 0; i < height; i++){
        tracinhos.append("-");}
    if(aux != NULL)
        cout << tracinhos << " " << aux->element << endl;
    else{
        cout << tracinhos << " null" << endl;
        return;}
    print(height+1, aux->left);
    print(height+1, aux->right);}

vector<int> ArvoreBinariadeBusca::Pre(){//Retorna um vector<int> na ordem pré-fixado
    vector<int> v;
    Pre(root, v);
    return v;}

void ArvoreBinariadeBusca::Pre(Nodo *n, vector<int> &v){//Parte recursiva do metodo Pre()
    if(n == nullptr)
        return;
    v.push_back(n->element);
    Pre(n->left, v);
    Pre(n->right, v);}

vector<int> ArvoreBinariadeBusca::Pos(){//Retorna um vector<int> na ordem pos-fixado
    vector<int> v;
    Pos(root, v);
    return v;}

void ArvoreBinariadeBusca::Pos(Nodo *n, vector<int> &v){//Parte recursiva do metodo Pos()
    if(n == nullptr)
        return;
    Pos(n->left, v);
    Pos(n->right, v);
    v.push_back(n->element);}

vector<int> ArvoreBinariadeBusca::Cen(){//Retorna um vector<int> na ordem central
    vector<int> v;
    Cen(root, v);
    return v;}

void ArvoreBinariadeBusca::Cen(Nodo *n, vector<int> &v){//Parte recursiva do metodo Cen()
    if(n == nullptr)
        return;
    Cen(n->left, v);
    v.push_back(n->element);
    Cen(n->right, v);}