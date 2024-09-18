#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


double getTotal(std::vector<std::pair<std::string, double>> pairs)
{
    double sum = 0.0;
    for(const auto& [_, v] : pairs){ sum += v; }

    return sum;
}

int main()
{
    std::vector<std::pair<std::string, double>> faturamento =
    {
        {"SP", 67836.43},
        {"RJ", 36678.66},
        {"MG", 29229.88},
        {"ES", 27165.48},
        {"Outros", 19849.53}
    };

    const double total = getTotal(faturamento); 

    // Criando um segundo vetor de pares de valor com sigla e porcentagem.
    std::vector<std::pair<std::string, float>> percentages;
    for(const auto& [nome, valor] : faturamento)
    {
        float porcentagem = 100 * (valor/total);
        percentages.push_back({nome, porcentagem});
    }

    // Exibindo os valores.
    std::cout << "< Participação de cada estado no faturamento final:\n";
    for(const auto& [nome, porcentagem] : percentages)
    {
        std::cout << "- " << nome << " -> " << std::fixed << std::setprecision(2) << porcentagem << "%\n";
    }

    return 0;
}
