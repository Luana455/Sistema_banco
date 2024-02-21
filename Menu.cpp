#include "Menu.h" 
#include <vector>

void Menu::MenuPrincipal()
{
    setlocale(LC_ALL, "ptb"); // para poder usar acentos 
    
    do { //é importante ter um do para caso o usuario digite um numero invalido, dai o programa roda novamente sem a necessidade de abrir todo de novo 
        system("CLS");//system CLS para manter a tela de execução limpa a cada reset, para ficar organizadinho
        cout << "********************************************" << endl;
        cout << "*              1 - Conta                   *" << endl;
        cout << "*              2 - Transações              *" << endl;
        cout << "*              3 - Painel Geral            *" << endl;
        cout << "*              4 - Sair                    *" << endl;
        cout << "********************************************" << endl;
        cout << "                Opção:                      " << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            Menuconta(); //aqui chama a função do Menu de contas, para poder acessar o gerenciamento delas
            break;
        case 2:
            MenuTransacoes(); //para ir para o menu das Transações
            break;
        case 3:
            MenuPainelGeral(); // para ir para o menu de painel geral
            break;
        case 4:
            system("CLS");
            cout << "Obrigada, até a próxima!" << endl;
            break;

        default:
            cout << "Opção invalida! Tente novamente" << endl; // se o usuario digitar algum numero que não esteja ali, aparecerá mensagem de erro
            system("pause");
            break;
        }

    } while (opcao != 4); //enquanto a pessoa nao digitar 4, o programa segue em loop
     
}

void Menu::Menuconta()
{
    setlocale(LC_ALL, "ptb");
    Conta conta; // aqui chamamos a classe conta para poder ter acesso as funções que eu criei lá, como a de cadastro
    
    do {
        system("CLS");
        cout << "********************************************" << endl;
        cout << "*              Gerenciar conta             *" << endl;
        cout << "*              1 - Cadastrar conta         *" << endl;
        cout << "*              2 - Remover conta           *" << endl;
        cout << "*              3 - Mesclar contas          *" << endl;
        cout << "*              4 - Exibir contas           *" << endl;
        cout << "*              5 - Voltar                  *" << endl;
        cout << "********************************************" << endl;
        cout << "*               Opção:                     *" << endl;
        cin >> opcao;

        switch (opcao) 
        {
        case 1:
            conta.cadastrarConta();
            contas.push_back(conta);
            break;
        case 2:
            conta.removerConta(contas,0);
            break;
        case 3:
            conta.mesclarConta(contas);
            break;
        case 4:
            exibirTodasContas();
            break;
        case 5:
            cout << "Voltar para o menu" << endl; //opção para retornar para o menu principal, caso queira acessar outra opção e ter um fluxo legal entre menus
            MenuPrincipal();
            system("CLS");
            break;

        default:
            cout << "Opção invalida!" << endl; 
            system("pause");
            break;
        } cout << endl;
    } while (opcao != 5);
}

void Menu::MenuTransacoes()
{
    Transacoes transacao;
    setlocale(LC_ALL, "ptb");

    do {
        system("CLS");
    cout << "********************************************" << endl;
    cout << "*               Transações                 *" << endl;
    cout << "*              1 - Extrato da conta        *" << endl;
    cout << "*              2 - Incluir Transação       *" << endl;
    cout << "*              3 - Editar última transação *" << endl;
    cout << "*              4 - Transferir fundos       *" << endl;
    cout << "*              5 - Voltar                  *" << endl;
    cout << "********************************************" << endl;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        transacao.ExtratoConta();
        break;
    case 2:
        transacao.IncluirTransacao();
        break;
    case 3:
        transacao.EditarUltimaTransacao();
        break;
    case 4:
        transacao.TransferirFundos();
        break;
    case 5:
        cout << "Voltar para o menu" << endl; //opção para retornar para o menu principal, caso queira acessar outra opção e ter um fluxo legal entre menus
        MenuPrincipal();
        break;

    default:
        cout << "Opção invalida!" << endl;
        system("pause");
        break;
    } cout << endl;
} while (opcao != 5);

}

void Menu::MenuPainelGeral()
{
    setlocale(LC_ALL, "ptb");
    PainelGeral painel;

    do {
        system("CLS");
    cout << "********************************************" << endl;
    cout << "*             Painel Geral                 *" << endl;
    cout << "*      1 - Resumo das contas               *" << endl;
    cout << "*      2 - Resumo de receita e despesas    *" << endl;
    cout << "*      3 - Saldo Geral dos últimos 6 meses *" << endl;
    cout << "*      4 - Voltar                          *" << endl;
    cout << "********************************************" << endl;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        painel.ResumoContas();
        break;
    case 2:
        painel.ResumoDeReceitas();
        break;
    case 3:
        painel.SaldoGeral6Meses();
        break;
    case 4:
        cout << "Voltar para o menu" << endl; //opção para retornar para o menu principal, caso queira acessar outra opção e ter um fluxo legal entre menus
        MenuPrincipal();
        break;

    default:
        cout << "Opção invalida!" << endl;
        system("pause");
        break;
    } cout << endl;
    } while (opcao != 4);
}

void Menu::exibirTodasContas() const 
{
    system("CLS");
    cout << "Contas cadastradas" << endl;
    for (vector<Conta>::const_iterator it = contas.cbegin(); it != contas.cend(); ++it) //o const_iterator funciona parecido com um ponteiro
    { //metodo para percorrer o vetor de contas 
        cout << it->getInfo() <<endl; //getInfo para pegar os dados de cada uma
        cout << endl;
        system("pause");
    }
}

