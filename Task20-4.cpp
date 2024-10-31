#include <iostream>
#include <fstream>
#include <ctime>

int bill(int cup)
{
    if (cup == 1)
        return 100;
    if (cup == 2)
        return 200;
    if (cup == 3)
        return 500;
    if (cup == 4)
        return 1000;
    if (cup == 5)
        return 2000;
    if (cup == 6)
        return 5000;
    return 0;
}

void give(bool &check, int temp, int (&bank)[1000], int (&value)[6])
{
    for (int y = 6; y > 0; --y)
    {
        for (int i = 0; i < 1000; ++i)
        {
            if (bank[i] == bill(y) && temp >= bill(y))
            {
                temp -= bill(y);
                if (check)
                {
                    bank[i] = 0;
                    --value[y - 1];
                }
                if (temp == 0)
                {
                    check = true;
                    break;
                }
            }
        }
    }
}

int main()
{
    int bank[1000] = {0};
    int value[6] = {0};
    std::srand(std::time(nullptr));
    int cash, sum, temp;
    bool check;
    std::ifstream storage("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\storage.bin", std::ios::binary);
    if (storage.is_open())
    {
        for (int i = 0; i < 1000; ++i) // заполняем банкомат из файла
        {
            storage.read((char *)&bank[i], sizeof(bank[i]));
            if (bank[i] == 100)
                ++value[0];
            if (bank[i] == 200)
                ++value[1];
            if (bank[i] == 500)
                ++value[2];
            if (bank[i] == 1000)
                ++value[3];
            if (bank[i] == 2000)
                ++value[4];
            if (bank[i] == 5000)
                ++value[5];
        }
        
    }
    storage.close();
    std::string choise;

    do
    {
        sum = 0;
        std::cout << "Banknotes are available:\n";
        for (int i = 0; i < 6; ++i)
        {
            std::cout << bill(i + 1) << " \t" << value[i] << std::endl;
            sum += value[i] * bill(i + 1);
        }
        std::cout << "Total: " << sum << std::endl;

        std::cout << "Input command ('+'- add cash, '-' - give cash, '=' - exit):\n";
        std::cin >> choise;

        if (choise == "+") // заполняем банкомат
        {
            for (int i = 0; i < 1000; ++i)
            {
                if (bank[i] == 0)
                {
                    temp = (std::rand() % 6);
                    bank[i] = bill(temp + 1);
                    ++value[temp];
                }
            }
        }
        if (choise == "-")
        {
            std::cout << "How much money do you need?: ";
            std::cin >> cash;
            check = false;
            for (int c = 0; c < 2; ++c)
            { // цикл c проверкой возможности выдачи
                if (cash < 100)
                {
                    std::cout << "Wrong!!!\n";
                    break;
                }
                else
                    give(check, cash, bank, value);
            }
            if (!check)
                std::cout << "The amount cannot be issued\n";
        }

    } while (choise != "=");
    std::ofstream instorage("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\storage.bin", std::ios::binary);
    if (!instorage.is_open())
    {
        std::cerr << "Не удалось открыть файл!" << std::endl;

        return 1;
    }
    else
    {
        for (int i = 0; i < 1000; ++i)
        {
            instorage.write((char *)&bank[i], sizeof(bank[i]));
        }
        }
    instorage.close();
    return 0;
}