#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Pessoa
{
    string nome;
    string sobrenome;
    double valor;
    
};

int main()
{
    char respostaCadastro, respostaDeposito;
    vector<Pessoa> pessoas;

    cout << fixed << setprecision(2);

    do
    {
        Pessoa pessoa;

        // cadastra as pessoas
        cout << "digite o seu nome e ultimo sobrenome: ";
        cin >> pessoa.nome >> pessoa.sobrenome;
        cout << endl;

        cout << "deseja realizar um deposito?[s/n]" << endl;
        cin >> respostaDeposito;
        cout << endl;
        if (respostaDeposito == 's' || respostaDeposito == 'S')
        {
            cout << "digite o valor do deposito: ";
            cin >> pessoa.valor;
            cout << endl;
        }
        pessoas.push_back(pessoa);//coloca a pessoa no final do vetor

        for(int i = 0; i < pessoas.size(); i++){
            cout << "nome: " << pessoas[i].nome << " "<< pessoas[i].sobrenome << endl;
            cout << "valor: " << pessoas[i].valor << endl;
        }
        cout << "Deseja cadastrar uma conta?[s/n]" << endl;
        cin >> respostaCadastro;
        cout << endl;
    } while (respostaCadastro == 's' || respostaCadastro == 'S');

    return 0;
}