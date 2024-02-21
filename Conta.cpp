#include "conta.h"


void Conta::cadastrarConta()
{
    
    system("CLS");
    cout << "Cadastrar Conta" << endl;
    cout << "Banco: ";
    cin >> banco;
    cout << "Agencia: ";
    cin >> agencia;
    cout << "Numero: ";
    cin >> numero;
    saldo = 2.0; //saldo sempre come�a em 0
    cout <<"Saldo:" << saldo << endl;
    cout << endl;
    cout << "Conta cadastrada com sucesso!" << endl;
    system("pause"); //aqui basicamente tem apenas o cout e cin, j� que o vetor que salva as contas est� na classe Menu
    
}

void Conta::removerConta(vector<Conta>& contas, int numero)
{
    system("CLS");
    cout << "Contas cadastradas:" << endl;
    for (size_t i = 0; i < contas.size(); ++i) //mostra as contas cadastradas 
    {
        cout << "Conta " << (i) << endl;
        contas[i].getInfo(); 
        cout << endl;
    }

    cout << "Digite o n�mero da conta que voc� deseja remover: ";
    cin >> numero;
    if (numero < 0 || numero >= contas.size()) //aqui ele testa o numero digitado para o usuario para ver se � valido
    {
       cout << "N�mero inv�lido. Por favor, tente novamente." <<endl;
       system("pause");
    }
    else 
    {
        system("CLS");
        contas.erase(contas.begin() + numero);//se for valido, ele usa erase para remover, para localizar a conta certa, ele faz (inicio + numero digitado)
        cout << "Conta removida com sucesso." << endl;
        system("pause");//sempre uso system("pause") para o codigo n�o sair direto, e ter o tempo do usuario ler o que foi imprimido na tela
    }

}

void Conta::mesclarConta(vector<Conta>& contas)
{
    int n1=0, n2=0;

    cout << "Contas cadastradas:" << endl;
    for (size_t i = 0; i < contas.size(); ++i) //comando que mostra as contas cadastradas 
    {
        cout << "Conta " << (i) << endl; //As contas armazenadas no vetor, sempre iniciam com 0, ent�o � �til mostrar para o usuario
        contas[i].getInfo();  //assim ele pode saber quantas contas tem cadastrada e qual numero vinculado a ela, para poder remover/mesclar com precis�o
        cout << endl;
    }

    cout << "Digite o n�mero da primeira conta a ser mesclada: ";
    cin >> n1;
    cout << "Digite o n�mero da segunda conta a ser mesclada: ";
    cin >> n2;

    if (n1 >= 0 && n1 < contas.size() && n2 >= 0 && n2 < contas.size()) 
    {
       
        contas[n1].saldo += contas[n2].saldo; //mesclar ambas contas

        // Remover a segunda conta
        contas.erase(contas.begin() + n2);
        system("CLS");
        cout << "Conta mesclada com sucesso" << endl;
        system("pause");
    }
    else 
    {
        cout << "Um ou ambos os n�meros digitados s�o inv�lidos. Tente novamente" << endl;
        system("pause"); //caso o usuario escreva um numero inexistente
    }

}


string Conta::getInfo()const
{
    ostringstream dados; //ostringstream � uma fun��o que funciona como string, mas permite stream de saida
    dados << "Banco: " << banco <<endl
        << "Ag�ncia: " << agencia<< endl
        << "N�mero: " << numero<< endl //aqui ele retorna e imprime todos dados da conta
        << "Saldo: " << saldo;
    return dados.str(); 

}