#include <ctime>
#include <exception>
#include <iostream>
#include <string>

class FishException : public std::exception
{
    const char *what() const noexcept override
    {
        return "Well done, you caught a fish!";
    }
};

class BootException : public std::exception
{
    const char *what() const noexcept override { return "You got a boot!!!"; }
};

class NothingException : public std::exception
{
    const char *what() const noexcept override { return "Empty!"; }
};

class Field
{
public:
    std::string fish;
    std::string boot;
    std::string nothing;

    std::string Fish() { return "fish"; }
    std::string Boot() { return "boot"; }
};

int main()
{
    std::srand(std::time(nullptr));
    int count = 1;
    int temp, fill = 0;
    bool find = true;
    Field field[10] = {};
    field[std::rand() % 9].fish = field->Fish();
    while (fill < 3)
    {
        temp = std::rand() % 9;
        if (field[temp].fish == "" && field[temp].boot == "")
        {
            field[temp].boot = field->Boot();
            ++fill;
        }
    }
    /*
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " " << field[i].fish << "\t\t" << field[i].boot << std::endl;
    }*/
    while (find)
    {
        try
        {
            std::cout << "Enter the number of the cell(0-9): ";
            int index;
            std::cin >> index;
            if (index < 0 || index > 9)
                throw std::invalid_argument("wrong cell!");
            if (field[index].fish != "")
            {
                std::cout << "it took: " << count << " attemps\n";
                find = false;
                throw FishException();
            }
            if (field[index].boot != "")
            {
                std::cout << "You loose!\n";
                find = false;
                throw BootException();
            }
            if (field[index].fish == "" && field[index].boot == "")
            {
                count++;
                throw NothingException();
            }
        }
        catch (const std::invalid_argument &x)
        {
            std::cerr << "invalid argument:" << x.what() << std::endl;
        }
        catch (const std::exception &x)
        {
            std::cerr << "Caught exception:" << x.what() << std::endl;
        }
        catch (...)
        {
            std::cerr << "some kind of exception\n";
        }
    }
}