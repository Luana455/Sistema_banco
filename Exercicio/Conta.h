#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Transacoes.h"


#ifndef CONTA_H
#define CONTA_H

using namespace std;

class Conta
{
protected: //dados protegidos 
    string banco;
    string agencia;
    string numero;
    double saldo;
    vector<Transacoes> transacoes;
    

public: //dados publicos
    void cadastrarConta(); 
    void removerConta(vector<Conta>& contas, int numero); //aqui temos que puxar o vetor da classe menu,então usamos esses parametros
    void mesclarConta(vector<Conta>& contas);
    string getInfo() const; 
    
};


#endif