#include <locale>
#include <iostream>
#include <cstring>

#include <string>

int main()
{
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    /*
        O método `reverse()` é bastante eficiente, porém, como não é este o objetivo,
        farei um processo manual de inversão, utilizando strings em C.
    */
    
    std::cout << "Invertendo strings.\n";

    size_t txt_size = 127; // Tamanho máximo do buffer de caracteres.
    char txt[txt_size];
    char txt_invertido[txt_size];

    while(1)
    {
        std::cout << "Digite uma string para ser invertida.\nUma entrada vazia encerra a execução do programa.\n> ";
        std::cin.getline(txt, txt_size);
        strcpy(txt_invertido, txt);

        if(txt[0] == '\0'){ break; }

        const size_t len = strlen(txt); // Total de caracteres na string.
        for(int i = len; i > 0; i--){ txt_invertido[len-i] = txt[i-1]; } // Inverte utilizando um loop.
        txt_invertido[len] = '\0'; // Adiciona o caractere final necessário em uma string em C.

        std::cout << "< Texto inserido:\t" << "\"" << txt << "\"\n";
        std::cout << "< Texto invertido:\t" << "\"" << txt_invertido << "\"\n\n";
    }

    std::cout << "Encerrando a aplicação.";
}