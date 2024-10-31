#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream words;
    std::string Path;

    // words.open("C:\\develop\\skillbox-projects\\profession-c-plus-plus\\words.txt");
    do
    {
        std::cout << "Enter the Path to file: ";
        std::cin >> Path;
        words.open(Path, std::ios::binary);
        if (!words.is_open())
            std::cout << "Wrong path" << std::endl;
    } while (!words.is_open());
    int count = 0, buf = 0;
    while (!words.eof())
    {
        char buffer[50];
        words.read(buffer, sizeof(buffer));
        count += words.gcount();
        for (int i = 0; i < 50; ++i)
        {
            std::cout << buffer[i];
            ++buf;
            if (buf >= count)
                break;
        }
    }
    words.close();

    return 0;
}