/*
Savio Decaro - 842735
Fabio Coral - 842538
Eduardo Pacheco - 842421
Rene Sant'Anna - 842640
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct Entrada
{
    string tipo = "placeHolder";
    double valor = 0;
};

struct Saida
{
    string tipo = "placeHolder";
    double valor = 0;
};

struct Categoria
{
    string nome;
    double orcamento;
};
struct Investimento
{
    double poupanca = 0.0;
    double despesa = 0.0;
    double pessoal = 0.0;
};

struct Financeiro
{
    vector<Entrada> entradas;
    vector<Saida> saidas;
    vector<Categoria> categorias;
    double totalEntradas = 0;
    double totalSaidas = 0;
};

void cadastrarEntrada(Financeiro &financeiro)
{
    Entrada entrada;
    cout << "Digite o tipo da entrada: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada.tipo);
    cout << "Digite o valor da entrada: ";
    cin >> entrada.valor;
    financeiro.entradas.push_back(entrada);
    financeiro.totalEntradas += entrada.valor;
}

void cadastrarSaida(Financeiro &financeiro)
{
    Saida saida;
    cout << "Digite o tipo da saida: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, saida.tipo);
    cout << "Digite o valor da saida: ";
    cin >> saida.valor;
    financeiro.saidas.push_back(saida);
    financeiro.totalSaidas += saida.valor;
}

void cadastrarCategoria(Financeiro &financeiro)
{
    Categoria categoria;
    cout << "Digite o nome da categoria: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, categoria.nome);
    cout << "Digite o orçamento da categoria: ";
    cin >> categoria.orcamento;
    financeiro.categorias.push_back(categoria);
}
void realizaInvestimento(double valorInvestido, Investimento &investimento)
{
    int opcao;

    if (valorInvestido <= 0)
    {
        cout << "Antes de realizar os investimentos, adicione um valor maior que zero." << endl;
    }
    else
    {
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

        if (opcao != 1 && opcao != 2)
        {
            cout << "Escolha uma opcao valida.\n";
        }
        else if (opcao == 1)
        {
            investimento.poupanca += poupanca;
            investimento.despesa += despesa;
            investimento.pessoal += pessoal;
        }
        else
        {
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

void mostrarTotal(Financeiro financeiro, Entrada entrada, Saida saida)
{
    cout << "\n\nentradas: " << endl;
    for (const Entrada &entrada : financeiro.entradas)
    {
        cout << entrada.tipo << ": " << entrada.valor << endl;
    }
    cout << "__________\n" << endl;
    cout << "saidas: " << endl;
    for (const Saida &saida : financeiro.saidas)
    {
        cout << saida.tipo << ": " << saida.valor << endl;
    }
    cout << "\nSaldo: " << financeiro.totalEntradas - financeiro.totalSaidas << endl;
}

void mostrarCategorias(Financeiro financeiro)
{
    cout << "\n\ncategorias:" << endl;
    for (const Categoria &categoria : financeiro.categorias)
    {
        cout << "Nome: " << categoria.nome << ", Orçamento: " << categoria.orcamento << endl;
    }
}

int main()
{
    cout << fixed << setprecision(2);
    int escolha;
    double valorInvestido;
    char continuar = 's';
    Financeiro meuFinanceiro;
    Entrada entrada;
    Saida saida;
    Investimento meuInvestimento;

    do
    {
        cout << "\n1- Cadastrar entrada" << endl;
        cout << "2- Cadastrar saida" << endl;
        cout << "3- Cadastrar categoria" << endl;
        cout << "4- Mostrar total" << endl;
        cout << "5- Mostrar categorias" << endl;
        cout << "6- investimentos" << endl;
        cout << "7- total investimentos" << endl;
        cout << "9- Sair" << endl;
        cin >> escolha;
        cout << endl;

        switch (escolha)
        {
        case 1:
            cadastrarEntrada(meuFinanceiro);
            break;
        case 2:
            cadastrarSaida(meuFinanceiro);
            break;
        case 3:
            cadastrarCategoria(meuFinanceiro);
            break;
        case 4:
            mostrarTotal(meuFinanceiro, entrada, saida);
            break;
        case 5:
            mostrarCategorias(meuFinanceiro);
            break;
        case 6:
            // Realizar investimento

            while (continuar == 's' || continuar == 'S')
            {
                cout << "Quanto deseja investir?: ";
                cin >> valorInvestido;

                realizaInvestimento(valorInvestido, meuInvestimento);

                cout << "Deseja fazer outro investimento? (s/n): ";
                cin >> continuar;
            }
        case 7:
        {
            cout << "Investimentos finais:\n";
            cout << "Poupanca acumulada: " << meuInvestimento.poupanca << "\n";
            cout << "Despesas acumuladas: " << meuInvestimento.despesa << "\n";
            cout << "Estilo de vida acumulado: " << meuInvestimento.pessoal << "\n";
        }

        break;
        case 9:
            cout << "Saindo...\nFeito por:\n";
            cout << "Savio Decaro - 842735" <<endl;
            cout << "Fabio Coral - 842538" <<endl;
            cout << "Eduardo Pacheco - 842421"<<endl;
            cout << "Rene Sant'Anna - 842640"<<endl;
            break;
        default:
            cout << "Opção inválida, tente novamente.\n";
            break;
        }
    } while (escolha != 9);

    return 0;
}