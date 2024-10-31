#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream words;
    words.open("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\words.txt");
    std::string word, Tword;
    int count = 0;
    std::cout << "Enter the word you are looking for: ";
    std::cin >> Tword;
    while (words >> word)
    {
        
        if (word == Tword)
            ++count;
    }
    words.close();
    if (count > 0)
        std::cout << "Your word occurs " << count << " times";
    else
        std::cout << "There are no such words";
    return 0;
}