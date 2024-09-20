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
    string nome = "placeHolder";
    double teto = 0;
    double orcamento = 0;
};

struct Investimento
{
    double poupancaAcumulada = 0.0;
    double despesaAcumulada = 0.0;
    double pessoalAcumulado = 0.0;
};
struct Financeiro
{
    vector<Entrada> entradas;
    vector<Saida> saidas;
    vector<Categoria> categorias;
    vector<Investimento> investimentos;
    double totalEntradas = 0;
    double totalSaidas = 0;
};

void cadastrarEntrada(Financeiro &financeiro)
{
    Entrada entrada;
    cout << "Digite o tipo da entrada[Ex: job, empresa, etc...]: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada.tipo);
    cout << "Digite o valor da entrada: ";
    cin >> entrada.valor;
    financeiro.entradas.push_back(entrada);
    financeiro.totalEntradas += entrada.valor;
}

void cadastrarSaida(Financeiro &financeiro)
{
    if (financeiro.totalEntradas - financeiro.totalSaidas <= 0)
    {
        cout << "Saldo insuficiente para realizar a saída." << endl;
        return;
    }
    Saida saida;
    cout << "Digite o tipo da saida[Ex: Cinema, aluguel, etc...]: ";
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
    if (financeiro.totalEntradas - financeiro.totalSaidas <= 0)
    {
        cout << "Saldo insuficiente para realizar o cadastro de categoria." << endl;
        return;
    }

    cout << "Digite o nome da categoria: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, categoria.nome);
    cout << "Digite o teto da categoria: ";
    cin >> categoria.teto;
    cout << "Digite quanto sera gasto nessa categoria: ";
    cin >> categoria.orcamento;
    if(categoria.orcamento <= categoria.teto){
        financeiro.totalEntradas -= categoria.orcamento;
        financeiro.categorias.push_back(categoria);
    }else{
        cout << "O orcamento da categoria nao pode ser maior que o teto." << endl;
    }
}

void realizaInvestimento(double valorInvestido, Investimento &investimento, Financeiro &financeiro)
{

    if (financeiro.totalEntradas - financeiro.totalSaidas <= 0)
    {
        cout << "Você não tem saldo suficiente para realizar investimentos." << endl;
        return;
    }
    else if (valorInvestido > financeiro.totalEntradas - financeiro.totalSaidas)
    {
        cout << "Você não tem saldo suficiente para realizar esse investimento." << endl;
        return;
    }
    int opcao;
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
        investimento.poupancaAcumulada += poupanca;
        investimento.despesaAcumulada += despesa;
        investimento.pessoalAcumulado += pessoal;
    }
    else
    {
        investimento.poupancaAcumulada += poupanca2;
        investimento.despesaAcumulada += despesa2;
        investimento.pessoalAcumulado += pessoal2;
    }
    financeiro.investimentos.push_back(investimento);
    // Subtrair o valor investido do totalEntradas
    financeiro.totalEntradas -= valorInvestido;
}

void mostrarTotal(Financeiro financeiro, Entrada entrada, Saida saida)
{
    cout << "\n\nentradas: " << endl;
    for (const Entrada &entrada : financeiro.entradas)
    {
        cout << entrada.tipo << ": " << entrada.valor << endl;
    }
    cout << "__________\n"
         << endl;
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
        cout << "Nome: " << categoria.nome << ",teto: " << categoria.teto <<" ,Orçamento: " << categoria.orcamento << endl;
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
            cout << "Quanto deseja investir?: ";
            cin >> valorInvestido;

            realizaInvestimento(valorInvestido, meuInvestimento, meuFinanceiro);
            break;
        case 7:
        {
            cout << "_______" << endl;
            for (const Investimento &Investimento : meuFinanceiro.investimentos)
            {
                cout << "Investimentos finais:\n";
                cout << "Poupanca acumulada: " << Investimento.poupancaAcumulada << "\n";
                cout << "Despesas acumuladas: " << Investimento.despesaAcumulada << "\n";
                cout << "Estilo de vida acumulado: " << Investimento.pessoalAcumulado << "\n";
            }
        }

        break;
        case 9:
            cout << "Saindo...\nFeito por:\n";
            cout << "Savio Decaro - 842735" << endl;
            cout << "Fabio Coral - 842538" << endl;
            cout << "Eduardo Pacheco - 842421" << endl;
            cout << "Rene Sant'Anna - 842640" << endl;
            break;
        default:
            cout << "Opção invalida, tente novamente.\n";
            break;
        }
    } while (escolha != 9);

    return 0;
}