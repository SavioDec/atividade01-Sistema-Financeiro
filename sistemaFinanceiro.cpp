#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
struct Entrada
{
    string tipo = "placeHolder";
    double valor = 0;
};
vector<Entrada> entradas;
int realizaDeposito(double conta)
{
    Entrada entrada;
    cin.sync();
    double contaNovoValor = 0;
    cout << "digite o tipo da entrada do deposito: ";
    getline(cin, entrada.tipo);
    cout << "digite o valor do deposito: ";
    cin >> entrada.valor;
    cout << endl;
    contaNovoValor = conta + entrada.valor;
    entradas.push_back(entrada);

    return contaNovoValor;
}

// int realizarInvestimento(int conta){
//     int investir_no_banco = conta*1/3;
//     int reservar_comida = (investir_no_banco - conta)*1/3;
//     int reservar_energia = reservar_comid
// }

int main()
{
    cout << fixed << setprecision(2);
    int escolha;
    double conta = 0;

    do
    {
        // IR ADICIONANDO AS ESCOLHAS DO MENU
        cout << "1- realizar deposito" << endl;
        cout << "2- formas de investimentos" << endl;
        cout << "3- Total" << endl;
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
        case 2:
        {
            if (conta == 0)
            {
                cout << "Antes de realizar os investimentos, adicione um valor inicial a sua conta" << endl;
            }
            else
            {
            }
        }
        case 3:
        {
            // total
        }
        default:
            break;
        }
    } while (escolha != 9);
}