#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    int height, width;

    std::ofstream pic("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\pic.txt");
    if (!pic.is_open())
    {
        std::cerr << "He удалось открыть файл!" << std::endl;
        return 1;
    }
    std::cout << "Input Height and Wigth picture:" << std::endl;
    std::cin >> height >> width;
    assert(height > 0 && width > 0);
    for (int i = 0; i < height; ++i)
    {
        for (int y = 0; y < width; ++y)
        {
            pic << std::rand() % 2;
        }
        pic << std::endl;
    }
    pic.close();

    return 0;
}