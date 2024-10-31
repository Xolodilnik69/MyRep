#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int sum = 0;
    std::string fish, rod;
    std::cout << "What kind of fish will you catch:" << std::endl;
    std::cin >> fish;

    std::ifstream river("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\river.txt");
    if (!river.is_open())
    {
        std::cerr << "He удалось открыть файл!" << std::endl;
        return 1;
    }
    std::ofstream basket("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\basket.txt", std::ios::app);
    if (!basket.is_open())
    {
        std::cerr << "He удалось открыть файл!" << std::endl;
        return 1;
    }
    while (river >> rod)
    {
        if (fish == rod)
        {
            ++sum;
            basket << fish << std::endl;

        }
    }
    basket.close();
    river.close();
    std::cout << sum << " " << fish << " were caught" << std::endl;

    return 0;
}