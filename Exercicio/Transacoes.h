#pragma once
#include <iostream>
#include <string>


#ifndef TRANSACOES_H
#define TRANSACOES_H

using namespace std;

class Transacoes
{
public: 
    
    Transacoes(double valor, std::string data) : valor(valor), data(data) {}

    double getValor() const { return valor; }
    void setValor(double valor) { this->valor = valor; }
    string getData() const { return data; }
    void setData(string data) { this->data = data; }

    void ExtratoConta();
    void IncluirTransacao();
    void EditarUltimaTransacao();
    void TransferirFundos();

protected: //dados protegidos 
    double valor;
    string data;
};

#endif