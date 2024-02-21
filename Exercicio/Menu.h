#pragma once
#ifndef MENU_H // Esse comando serve para que o menu.h seja incluido apenas uma vez durante a compilação, mesmo que ele seja utilizado em varios lugares
#define MENU_H 
#include <vector> // o include que faz o vetor funcionar
#include "Conta.h" //include de todas classes que vamos usar para acessar pelo menu
#include "Transacoes.h"
#include "PainelGeral.h"

#include <iostream>
//esses dois comandos servem para o cout e cin funcionarem corretamente 
using namespace std; 

class Menu 
{
public:
    void MenuPrincipal();
    void Menuconta();
    void MenuTransacoes(); //as funções de Menu, para poder chamar cada um deles
    void MenuPainelGeral();
    void exibirTodasContas() const; //metodo para exibir dados de cada uma das contas
    

protected:
    int opcao = 0;
    vector<Conta> contas; //o vetor que salva cada conta criada

    
};



#endif
