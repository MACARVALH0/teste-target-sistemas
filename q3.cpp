#include <iostream>
#include <fstream>
#include <locale>

#include "nlohmann/json.hpp"
using json = nlohmann::json;


double getMonthlyAverage(std::vector<std::pair<int, double>> pairs)
{
    double sum = 0.0;
    for(const auto& [_, v] : pairs){ if(v > 0){ sum += v; } }

    return sum/pairs.size();
}

int main()
{
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    // Abrindo o arquivo de dados
    std::ifstream arquivo_dados("dados.json");

    if(!arquivo_dados.is_open()) // Caso tenha ocorrido algum erro ao abrir o arquivo.
    {
        std::cerr << "Por algum motivo, não foi possível abrir o arquivo de dados corretamente.";
        return 1; // Houve um erro durante a execução.
    }

    // Esse trecho cria 
    json json_dados;
    arquivo_dados >> json_dados;

    std::vector<std::pair<int, double>> dados;
    for(const auto& item : json_dados)
    {
        int dia = item["dia"];
        double valor = item["valor"];
        dados.push_back({dia, valor});
    }

    double average = getMonthlyAverage(dados);  // Média de arrecadamento.
    double lowest = average, highest = average; // Menor e maior valores faturados no mês.
    int  min_d = 0, max_d = 0;                  // Dias com menor e maior valores arrecadados.
    int higher_than_average = 0;                // Quantidade de dias cujo faturamento ultrapassou a média.
    for(const auto& [d, v] : dados)
    {
        if(!(v>0)){ continue; }

        if(v<lowest)
        {
            // Define menor valor arrecadado e dia com menor valor.
            lowest = v;
            min_d = d;
        }

        if(v > average)
        {
            higher_than_average++; // Adiciona ao contador de dias com arrecadamento acima da média.

            if(v > highest)
            {
                // Define maior valor arrecadado e dia com maior valor.
                highest = v;
                max_d = d;
            }
        }
    }

    std::cout << "< Média de faturamento mensal: R$" << average << ".\n";
    std::cout << "< O menor valor de faturamento no mês foi de R$" << lowest << " (dia " << min_d << ").\n";
    std::cout << "< O maior valor de faturamento no mês foi de R$" << highest << " (dia " << max_d << ").\n";
    std::cout << "< A média de faturamento foi superada " << higher_than_average << " dias no mês.";

    return 0;
}