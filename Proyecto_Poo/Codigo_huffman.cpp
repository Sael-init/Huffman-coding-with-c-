//
// Created by Toshiba on 22/12/2021.
//

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include "Codigo_huffman.h"

using namespace std;

void CrearArbol(string texto){
    //Halla la frecuencia
    map<char,int> frecuencia; //-------------------------
    for(auto i:texto) frecuencia[i]++;
    priority_queue< Node*, vector<Node*>, comp> raices;
    for(auto [k,V]: frecuencia){
        Node* Prueba;
        raices.push( Prueba->getNode(k,V,nullptr,nullptr));
    }
//Crea las raices con sus ramas cada una
    while(true){
        if(size(raices)== 1) break;
        Node* izq=raices.top(); raices.pop();
        Node* der=raices.top(); raices.pop();
        int sum=izq->getFrecuencia() + der->getFrecuencia();
        Node* Prueba;
        raices.push( Prueba->getNode(0,sum,izq,der));
    }
    //Comienza a codificar
    Node* raiz=raices.top();
    map<char, string > CodigoHuffman;//-------------------------
    codificar(raiz,"",CodigoHuffman);
    string codificado="";//-------------------------
    for(auto i:texto) codificado+=CodigoHuffman[i];

    //Presentación del Interfaz
    cout<<"-----------------------\nFRECUENCIAS POR PALABRA: "<<endl;
    print_m(frecuencia);
    cout<<"----------------------- \nMAP CON LA CODIFICACION: "<<endl;
    print_m(CodigoHuffman);
    cout<<">>> Codificado:\n  > "<<codificado;
    cout<<"\n>>> Decodificado:\n  > ";
    //Comienza a Decodificar
    int pos=-1;
    while(pos < (int) codificado.size()-2){
        decodificar(raiz, pos ,codificado);
    }
}


void AlgoritmoHuffman(){
    ifstream archivo("texto.txt");
    string linea; getline(archivo, linea);
    CrearArbol(linea);
}