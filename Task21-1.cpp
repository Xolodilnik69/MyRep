#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

struct statement
{
    std::string name;
    std::string date;
    int cash;
};

void save_stat(std::ofstream &words, statement &word)
{
    if (!words.is_open())
    {
        std::cerr << "He удалось открыть файл!" << std::endl;
    }
    else
        words << word.name << " " << word.date << " " << word.cash << std::endl;
    words.close();
}

void load_stat(std::ifstream &words, statement &word)
{
    if (!words.is_open())
    {
        std::cerr << "He удалось открыть файл!" << std::endl;
    }
    else
        while (words >> word.name)
        {
            words >> word.date;
            words >> word.cash;
            std::cout << word.name << " " << word.date << " " << word.cash << std::endl;
        }
    words.close();
}

int main()
{
    std::string command;
    statement word;
    do
    {
        std::cout << "Input command: (list, add, exit):" << std::endl;
        std::cin >> command;
        if (command == "add")
        {
            std::cout << "Input: Name Date(DD.MM.YYYY) Cash" << std::endl;
            std::cin >> word.name >> word.date >> word.cash;
            // по умолчанию в месяце 30 дней, и год рождения не больше 2024
            if (std::stoi(word.date.substr(0, 2)) > 0 && std::stoi(word.date.substr(0, 2)) < 31 &&
                std::stoi(word.date.substr(3, 2)) > 0 && std::stoi(word.date.substr(3, 2)) < 13 &&
                std::stoi(word.date.substr(6)) <= 2024)
            {
            }
            else
            {
                std::cerr << "Wrong date!" << std::endl;
            }
            std::ofstream in_words("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\words.txt", std::ios::app);
            save_stat(in_words, word);
        }
        if (command == "list")
        {
            std::ifstream words("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\words.txt");
            load_stat(words, word);
        }
    } while (command != "exit");

    return 0;
}