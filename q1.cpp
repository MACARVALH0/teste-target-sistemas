#include <iostream>

int main()
{
    // Na prática, a questão pode ser escrita dessa forma:
    const int INDICE = 13;
    int SOMA = 0;
    int K = 0;

    while(K < INDICE)
    {
        K = K + 1;
        SOMA = SOMA + K;
    }

    std::cout << SOMA << "\n"; // Retorna 91;

    // O valor final de SOMA é 91.

    return 0;
}

