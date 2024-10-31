#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
    std::ifstream words;
    int cash, max, sum = 0;

    std::string buffer, name1, name2, data, win;

    words.open("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\words.txt");

    while (!words.eof())
    {
        cash = 0;
        getline(words, buffer);
        //std::cout << buffer << std::endl;
        std::stringstream buffer_stream(buffer);
        buffer_stream >> name1 >> name2 >> cash >> data;
        if (cash > max)
        {
            max = cash;
            win = buffer;
        }
        sum += cash;
    }
    words.close();
    std::cout << "Cash summ: " << sum << "\n"
              << "Winner: " << win << std::endl;

    return 0;
}