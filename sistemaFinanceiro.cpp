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

vector<Pessoa> pessoas;

void criaPessoa()
{
    char respostaCadastro, respostaDeposito;

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
        pessoas.push_back(pessoa); // coloca a pessoa no final do vetor

        for (int i = 0; i < pessoas.size(); i++)
        {
            cout << "nome: " << pessoas[i].nome << " " << pessoas[i].sobrenome << endl;
            cout << "valor: " << pessoas[i].valor << endl;
        }
        cout << "Deseja cadastrar outra conta?[s/n]" << endl;
        cin >> respostaCadastro;
        cout << endl;
    } while (respostaCadastro == 's' || respostaCadastro == 'S');
}

int main()
{
    int escolha;

    do
    {
        // IR ADICIONANDO AS ESCOLHAS DO MENU
        cout << "1- criar conta" << endl;
        cout << "9- Sair" << endl;
        cin >> escolha;

        switch (escolha)
        {
            // DEIXAR 9 LIVRE PARA SER SAIDA
        case 1:
            criaPessoa();
            break;

        default:
            break;
        }
    } while (escolha != 9);
}