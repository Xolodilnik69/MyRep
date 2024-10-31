#include <exception>
#include <iostream>
#include <string>
#include <vector>

template <class T>
struct A
{
    T key;
    T element;
};

template <typename T>
void input(T &num, std::string st)
{
    std::cout << "Input " << st << ": " << std::endl;
    std::cin >> num;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.sync();
        throw std::invalid_argument("not equal!");
    }
}

template <typename T>
void fill(std::vector<std::pair<T, T>> &v)
{
    A<T> a;
    input(a.key, "key");
    input(a.element, "element");
    v.push_back(std::make_pair(a.key, a.element));
}

template <typename T>
void remove(std::vector<std::pair<T, T>> &v)
{
    if (v.size() == 0)
        throw std::runtime_error("This massive is empty");
    bool find = false;
    A<T> a;
    input(a.key, "key");
    int i = 0;
    while (i < v.size())
        if (v[i].first == a.key)
        {
            v.erase(v.begin() + i);
            find = true;
        }
        else
            i++;
    if (!find)
        throw std::runtime_error("key not found!");
}

template <typename T>
void find(std::vector<std::pair<T, T>> &v)
{
    if (v.size() == 0)
        throw std::runtime_error("This massive is empty");
    bool find = false;
    A<T> a;
    input(a.key, "key");
    int i = 0;
    for (auto i : v)
    {
        if (i.first == a.key)
        {
            std::cout << i.first << "\t" << i.second << std::endl;
            find = true;
        }
    }
    if (!find)
        throw std::runtime_error("key not found!");
}

template <typename T>
void print(std::vector<std::pair<T, T>> &v)
{
    for (auto i : v)
    {
        std::cout << i.first << "\t" << i.second << std::endl;
    }
}

int main()
{
    bool exit = true;
    std::string choise1, choise2;
    std::vector<std::pair<int, int>> in;
    std::vector<std::pair<double, double>> d;
    std::vector<std::pair<std::string, std::string>> s;

    while (exit)
    {
        try
        {
            std::cout << "What do you want to do? (a-add,r-remove,p-print,f-find,e-exit) \n";
            std::cin >> choise1;
            if (choise1 == "e")
                break;
            if (choise1 != "a" && choise1 != "r" && choise1 != "p" && choise1 != "f")
                throw std::invalid_argument("wrong choise!");
            if (choise1 == "p")
            {
                if (in.size() != 0)
                    print(in);
                if (d.size() != 0)
                    print(d);
                if (s.size() != 0)
                    print(s);
            }
            else
            {
                std::cout << "and what types of keys do you want to use? (i-int, d-double, s-string.) \n";
                std::cin >> choise2;
                if (choise2 != "i" && choise2 != "d" && choise2 != "s")
                    throw std::invalid_argument("wrong choise!");
                if (choise1 == "a" && choise2 == "i")
                    fill(in);
                if (choise1 == "a" && choise2 == "d")
                    fill(d);
                if (choise1 == "a" && choise2 == "s")
                    fill(s);
                if (choise1 == "r" && choise2 == "i")
                    remove(in);
                if (choise1 == "r" && choise2 == "d")
                    remove(d);
                if (choise1 == "r" && choise2 == "s")
                    remove(s);
                if (choise1 == "f" && choise2 == "i")
                    find(in);
                if (choise1 == "f" && choise2 == "d")
                    find(d);
                if (choise1 == "f" && choise2 == "s")
                    find(s);
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
            exit = false;
        }
    }
}
