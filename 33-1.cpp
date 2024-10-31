#include <cassert>
#include <exception>
#include <iostream>
#include <map>
#include <string>

class MinusException : public std::exception
{
    const char *what() const noexcept override
    {
        return "The quantity of the product is less than 0";
    }
};

bool fill(std::string &art, int &co)
{
    std::cout << "Input articles(c-cancel): \n";
    std::cin >> art;
    if (art == "c")
    {
        return false;
    }
    std::cout << "and count: \n";
    std::cin >> co;
    if (co < 0 || std::cin.fail())
    {
       std::cin.clear();
       std::cin.sync();
       throw std::invalid_argument(" count < 0 or not equal ");
    }
    else
        return true;
}

void add(std::map<std::string, int> &pr, std::string &art, int &co)
{
    bool find = false;
    fill(art, co);
    for (auto iter{pr.begin()}; iter != pr.end(); iter++)
    {
        if (iter->first == art)
        {
            iter->second += co;
            find = true;
            break;
        }
    }
    if (!find)
        throw std::invalid_argument("No such article\n");
}

void remove(std::map<std::string, int> &pr, std::string &art, int &co)
{
    bool find = false;
    fill(art, co);
    for (auto iter{pr.begin()}; iter != pr.end(); iter++)
    {
        if (iter->first == art)
        {
            if (iter->second >= co)
            {
                iter->second -= co;
                break;
            }
            else
                throw MinusException();
        }
    }
    if (!find)
        throw std::invalid_argument("No such article\n");
}

int main()
{
    std::map<std::string, int> prod;
    bool exit = true;
    bool input = true;
    std::string choise;
    std::string articles;
    int count;
    std::cout << "Fill the warehouse: \n";

    while (exit)
    {

        try
        {
            while (input)
            {
                if (fill(articles, count))
                    prod[articles] = count;
                else
                    input = false;
            }
            for (auto iter{prod.begin()}; iter != prod.end(); iter++)
            {
                std::cout << iter->first << "\t" << iter->second << std::endl;
            }
            std::cout << "What do you want to do? (a-add,r-remove,e-exit) \n";
            std::cin >> choise;
            if (choise == "e")
                exit = false;
            else if (choise == "a")
                add(prod, articles, count);
            else if (choise == "r")
                remove(prod, articles, count);
            else
                throw std::invalid_argument("wrong choise!");
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