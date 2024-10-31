#include <iostream>
#include <sstream>
#include <string>

void accord(bool notes[])
{

    if (notes[0])
    {
        std::cout << "DO ";
    }
    if (notes[1])
    {
        std::cout << "RE ";
    }
    if (notes[2])
    {
        std::cout << "MI ";
    }
    if (notes[3])
    {
        std::cout << "FA ";
    }
    if (notes[4])
    {
        std::cout << "SOL ";
    }
    if (notes[5])
    {
        std::cout << "LA ";
    }
    if (notes[6])
    {
        std::cout << "SI ";
    }
}
int main()
{
    int number = 1;
    std::string acc;
    do
    {
        bool notes[7] = {false};
        acc = std::to_string(number);
        for (int i = 0; i < acc.length(); ++i)
        {
            number = (int)acc[i] - 49;
            if (number < 0 || number > 6)
            {
                std::cerr << "Wrong accord!";
                break;
            }
            notes[number] = true;
        }
        accord(notes);
        std::cout << "\n";
        std::cout << "Input accord 1 - 7 (0 - exit):\n";
        std::cin >> number;
        if (number > 1000000000)
        {
            std::cerr << "Wrong accord!";
            number = 1;
        }
    } while (number != 0);
    return 0;
}