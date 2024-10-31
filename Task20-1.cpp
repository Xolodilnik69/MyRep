#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

int main()
{
    std::string word,name,date;
    int cash;
    std::ofstream words("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\words.txt", std::ios::app);
    if (!words.is_open())
    {
        std::cerr << "He удалось открыть файл!" << std::endl;
        return 1;
    }
    std::cout << "Input: Name Date(DD.MM.YYYY) Cash (>0):" << std::endl;
    std::getline(std::cin, word);
    std::stringstream buffer_stream(word);
    buffer_stream >> name >> date >> cash;
    
        // по умолчанию в месяце 30 дней, и год рождения не больше 2024
    if (date.length() == 10 && (date.substr(2,1) == ".") && (date.substr(5,1) == ".") && std::stoi(date.substr(0, 2)) > 0 && std::stoi(date.substr(0, 2)) < 31 &&
        std::stoi(date.substr(3, 2)) > 0 && std::stoi(date.substr(3, 2)) < 13 &&
        std::stoi(date.substr(6)) <= 2024 && cash > 0)
    {
        words << word << std::endl;
    }
        else {
            std::cerr << "Incorrect data!" << std::endl;
        }
    words.close();

    return 0;
}