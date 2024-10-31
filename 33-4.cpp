#include <exception>
#include <iostream>
#include <string>
#include <vector>


template <typename T>
void input(T array[8])
{
    T sum=0;
    std::cout << "Fill the array (8):\n";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "input number " << i+1 << " :";
        std::cin >> array[i];
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.sync();
            throw std::invalid_argument("not equal!");
        }
        sum += array[i];
    }
    std::cout << "the arithmetic mean of a numeric array = " << sum/8 << std::endl;
}

int main()
{
    std::string choise;
bool exit=true;
int arrayInt[8];
double arrayDouble[8];
float arrayFloat[8];

    while (exit)
    {
        try
        {
            std::cout << "What type of data do you want to use? (i-int, d-double, f-float, e-exit) \n";
            std::cin >> choise;
            if (choise == "e")
                break;
            if (choise != "i" && choise != "d" && choise != "f")
                throw std::invalid_argument("wrong choise!");
            if (choise == "i")
                input(arrayInt);
            if (choise == "d")
                input(arrayDouble);
            if (choise == "f")
                input(arrayFloat);
                }
        catch (const std::invalid_argument &x)
        {
            std::cerr << "invalid argument:" << x.what() << std::endl;
        }
        catch (const std::exception &x)
        {
            std::cerr << "Caught exception:" << x.what() << std::endl;
            exit = false;
        }
        catch (...)
        {
            std::cerr << "some kind of exception\n";
            exit = false;
        }
    }
}
