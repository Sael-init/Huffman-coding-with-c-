//
// Created by Toshiba on 22/12/2021.
//

#ifndef UNTITLED_CODIGO_HUFFMAN_H
#define UNTITLED_CODIGO_HUFFMAN_H
#include <iostream>
#include <map>
using namespace std;

//Imprimir un Contenedor
template <typename T1>
void printc(T1 Vec){ for(auto i:Vec) cout<<i<<" ";}

//Imprimir un map
template <typename unmap>
void print_m(unmap map){
    for(auto[key,value]: map) cout<< key <<" "<<value<<endl;
}


class Node{
private:
    char simbolo;
    int frecuencia;
    Node *izq,*der;
    //Funcion para asignar un nuevo nodo en el arbol
public:
//Constructor default
    Node()=default;
    //Constructor
    Node(char simbolo, int frecuencia, Node *izq, Node *der): simbolo{simbolo}, frecuencia{frecuencia},izq{izq},der{der}{
    }
    //Constructor copia
    Node(const Node& other):simbolo{other.simbolo},frecuencia{other.frecuencia},izq{other.izq},der{other.der}{
    }

    //Operador de asignacion copia
    Node operator=(const Node& other){
        if(&other == this) {return *this;}
        simbolo = other.simbolo;
        frecuencia = other.frecuencia;
        izq =  other.izq;
        der =  other.der;
        return *this;
    }

    //Destructor
    ~Node(){};

    Node* getNode(char simbolo,int frecuencia, Node* izq, Node* der){
        Node* nodo=new Node();
        nodo->simbolo=simbolo;
        nodo->frecuencia=frecuencia;
        nodo->izq=izq;
        nodo->der=der;
        return nodo;
    }
    int getFrecuencia(){return this->frecuencia;}
    int getSimbolo(){return this->simbolo;}
    Node* getIzq(){return this->izq;}
    Node* getDer(){return this->der;}
};

//Funcion Codificar
template<class char_t>
void codificar(Node* raiz,string str,map<char_t, string> &CodigoHuffman){
    if(raiz==nullptr) return; //no retorna
    if(!raiz-> getIzq() && !raiz->getDer()) CodigoHuffman[raiz->getSimbolo()]= str;
    if(raiz-> getIzq()) codificar(raiz->getIzq(), str +"0", CodigoHuffman);
    if(raiz-> getDer()) codificar(raiz->getDer(), str +"1", CodigoHuffman);
}

// Funcion Decodficar
template<class char_t>
void decodificar(Node* raiz,int &pos,char_t code){
    if(raiz==nullptr) return;
    if(!raiz-> getIzq() && !raiz->getDer()){
        char palabra=raiz->getSimbolo();
        cout<<palabra;
        return;
    }
    pos++;
    if(code[pos]=='0')
        decodificar(raiz->getIzq(),pos,code);
    else
        decodificar(raiz->getDer(),pos,code);

}

class comp{
public:
    bool operator()(Node* i,Node* d){return i->getFrecuencia() > d->getFrecuencia(); }
};

void AlgoritmoHuffman();


#endif //UNTITLED_CODIGO_HUFFMAN_H
