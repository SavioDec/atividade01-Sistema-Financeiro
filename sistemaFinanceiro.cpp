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

struct Investimento {
    double poupanca = 0.0;
    double despesa = 0.0;
    double pessoal = 0.0;
};

void realizaInvestimento(double valorInvestido, Investimento &investimento) {
    int opcao;

    if (valorInvestido <= 0) {
        cout << "Antes de realizar os investimentos, adicione um valor maior que zero." << endl;
    } else {
        cout << "\n1) - Primeiro modelo (Foco em Acumular Patrimonio):" << "\n";
        double poupanca = valorInvestido * 60 / 100;
        double despesa = valorInvestido * 30 / 100;
        double pessoal = valorInvestido * 10 / 100;

        cout << "60% para investimentos e poupanca - " << poupanca << "\n";
        cout << "30% para despesas essencias - " << despesa << "\n";
        cout << "10% para estilo de vida - " << pessoal << "\n\n";

        cout << "2) - Segundo modelo (Foco em aproveitar a vida):" << "\n";
        double poupanca2 = valorInvestido * 20 / 100;
        double despesa2 = valorInvestido * 30 / 100;
        double pessoal2 = valorInvestido * 50 / 100;

        cout << "20% para investimentos e poupanca - " << poupanca2 << "\n";
        cout << "30% para despesas essencias - " << despesa2 << "\n";
        cout << "50% para estilo de vida - " << pessoal2 << "\n\n";

        cout << "Qual forma deseja aplicar seu patrimonio? (1 ou 2): ";
        cin >> opcao;

        if (opcao != 1 && opcao != 2) {
            cout << "Escolha uma opcao valida.\n";
        } else if (opcao == 1) {
            investimento.poupanca += poupanca;
            investimento.despesa += despesa;
            investimento.pessoal += pessoal;
        } else {
            investimento.poupanca += poupanca2;
            investimento.despesa += despesa2;
            investimento.pessoal += pessoal2;
        }

        cout << "Realizado com sucesso.\n";
        cout << "Investimento em poupanca: " << investimento.poupanca << "\n";
        cout << "Despesas: " << investimento.despesa << "\n";
        cout << "Estilo de vida: " << investimento.pessoal << "\n\n";
    }
}

int main()
{
    cout << fixed << setprecision(2);
    int escolha;
    double valorInvestido;
    double conta = 0;

    Investimento meuInvestimento;  // Definido fora do loop para acumular investimentos
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
            cout << "Saldo atual: " << novoSaldo << "\n\n";
            break;
            
        }
        case 2:
        {
            // Realizar investimento
            char continuar = 's';

            while (continuar == 's' || continuar == 'S') {
                cout << "Quanto deseja investir?: ";
                cin >> valorInvestido;

                realizaInvestimento(valorInvestido, meuInvestimento);

                cout << "Deseja fazer outro investimento? (s/n): ";
                cin >> continuar;
            }

            break;  // Adicionado o break para evitar cair no próximo case
        }
        case 3:
        {
            // Exibir total de investimentos e saldo
            cout << "Investimentos finais:\n";
            cout << "Poupanca acumulada: " << meuInvestimento.poupanca << "\n";
            cout << "Despesas acumuladas: " << meuInvestimento.despesa << "\n";
            cout << "Estilo de vida acumulado: " << meuInvestimento.pessoal << "\n";
            cout << "Saldo da conta: " << conta << "\n\n";
            break;
        }
        case 9: {
            cout << "Saindo...\n";
            break;
        }
        default:
            cout << "Opção inválida, tente novamente.\n";
            break;
        }
    } while (escolha != 9);

    return 0;
}