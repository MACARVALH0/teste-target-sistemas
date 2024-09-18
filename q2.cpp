#include <iostream>
#include <unordered_set>

int main()
{
    int num = 0;
    bool isFibonacci = false;
    std::unordered_set<int> set;

    while(1)
    {
        std::cout << "Digite um número para checar (ou -1 para sair): ";
        std::cin >> num;
        if(num < 0){ break; }

        int a = 0; // Primeiro valor do set;
        int b = 1; // Segundo valor do set;


        set.insert(a);
        set.insert(b);
        int next = 0;

        while (b < num)
        {
            next = a+b;
            set.insert(next);
            a = b;
            b = next;
        }

        isFibonacci = set.find(num) != set.end();

        if(isFibonacci) { std::cout << "O número " << num << " faz parte da sequência fibonacci.\n\n"; }
        else{ std::cout << "O número " << num << " NÃO faz parte da sequência fibonacci.\n\n"; }
    }

    return 0;
}