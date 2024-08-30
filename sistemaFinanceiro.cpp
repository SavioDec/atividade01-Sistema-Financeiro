#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int realizaDeposito(double conta)
{

    double deposito = 0, contaNovoValor;
    cout << "digite o valor do deposito: ";
    cin >> deposito;
    cout << endl;
    contaNovoValor = conta + deposito;

    return contaNovoValor;
}

int main()
{
    cout << fixed << setprecision(2);
    int escolha;
    double conta = 0;

    do
    {
        // IR ADICIONANDO AS ESCOLHAS DO MENU
        cout << "1- realizar deposito" << endl;
        cout << "9- Sair" << endl;
        cin >> escolha;

        // DEIXAR 9 LIVRE PARA SER SAIDA
        switch (escolha)
        {
        case 1:
        {
            double novoSaldo = realizaDeposito(conta);
            conta = novoSaldo;
            break;
        }

        default:
            break;
        }
    } while (escolha != 9);
}