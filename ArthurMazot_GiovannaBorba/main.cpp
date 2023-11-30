#include "ArvoreBinariadeBusca.hpp"
using namespace std;
int main(){
    ArvoreBinariadeBusca *arvore = new ArvoreBinariadeBusca();
    arvore->add(1);
    arvore->add(2);
    arvore->add(3);
    arvore->add(4);
    arvore->add(5);
    arvore->add(6);
    arvore->add(7);
    arvore->add(8);
    arvore->add(9);
    cout << "------------------------------" << endl;
    cout << "=> Altura = " << arvore->height() << endl;
    arvore->clear();
    arvore->add(9);
    arvore->add(8);
    arvore->add(7);
    arvore->add(6);
    arvore->add(5);
    arvore->add(4);
    arvore->add(3);
    arvore->add(2);
    arvore->add(1);

    cout << "------------------------------" << endl;
    vector<int> v = arvore->Cen();
    cout << "=> Caminho central = ";
    for(int i = 0; i < v.size() - 1; i++)
        cout << v[i] <<", ";
    cout << v[v.size()-1] << endl;

    ArvoreBinariadeBusca *arvoreCop = arvore->clone();

    v = arvoreCop->Pre();
    cout << "=> Caminho Pré-fixado = ";
    for(int i = 0; i < v.size() - 1; i++)
        cout << v[i] <<", ";
    cout << v[v.size()-1] << endl;

    v = arvoreCop->Pos();
    cout << "=> Caminho Pós-fixado = ";
    for(int i = 0; i < v.size() - 1; i++)
        cout << v[i] <<", ";
    cout << v[v.size()-1] << endl;

    cout << "------------------------------";

    arvore->clear();
    arvore->add(10);
    arvore->add(12);
    arvore->add(11);//RDE no 10
    arvore->add(13);
    arvore->add(14);//RSE no 12
    arvore->add(8);
    arvore->add(9); //RDD no 10
    arvore->add(7);
    arvore->add(6); //RSD no 8

    cout << endl; 

    arvore->print();
    cout << "------------------------------" << endl;
    delete arvoreCop;
    delete arvore;
}