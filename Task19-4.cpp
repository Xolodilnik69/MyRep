#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream image;
    std::string Path;
    int z;
    do
    {
        std::cout << "Enter the path to file: ";
        std::cin >> Path;
        z = Path.length();
        if ((Path[z - 3] == 'P' || Path[z - 3] == 'p') && 
            (Path[z - 2] == 'N' || Path[z - 2] == 'n') && 
            (Path[z - 1] == 'G' || Path[z - 1] == 'g'))
            image.open(Path, std::ios::binary);
        if (!image.is_open())
            std::cout << "Wrong path or file" << std::endl;
    } while (!image.is_open());

    char buffer[4];
    image.read(buffer, sizeof(buffer));
    if (buffer[0]==-119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G')
        std::cout << "This is PNG file" << std::endl;
    else
        std::cout << "This is NOT right PNG file!" << std::endl;
    image.close();

    return 0;
}