#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Pessoa
{
    string nomeCompleto;
    float valor;
};

void registraPessoa()
{
    char respostaCadastro, respostaDeposito, respostaPessoas;
    vector<Pessoa> pessoas;

    cout << setprecision(1);

    do
    {
        Pessoa pessoa;

        // cadastra as pessoas
        cout << "digite o seu nome completo: ";
        getline(cin, pessoa.nomeCompleto);
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
        pessoas.push_back(pessoa);

        cout << "Deseja cadastrar uma conta?[s/n]" << endl;
        cin >> respostaCadastro;
        cout << endl;
    } while (respostaCadastro == 's' || respostaCadastro == 'S');
}