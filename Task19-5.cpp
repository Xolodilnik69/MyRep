#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void spin(int &sect, bool (&dr)[13])
{
    int num;
    do
    {
        std::cout << "Spin the drum!";
        std::cin >> num;
        if (num < 1)
            std::cout << "Wrong number!\n";
    } while (num < 1);
    sect += num;
    do
    {
        if (sect > 13)
        {
            sect = sect % 13;
            // std::cout << dr[sect - 1];
        }
        else if (dr[sect - 1])
            ++sect;
        if (sect <= 13)
            std::cout << "Sector " << sect << " on the drum\n";
    } while (dr[sect - 1]);
}

int main()
{
    std::ifstream question;
    std::ifstream answer;
    std::string buffer, Answer, path = "C:\\develop\\skillbox-projects\\profession-c-plus-plus\\";

    std::string name[]{"q1", "q2", "q3", "q4", "q5", "q6", "q7", "q8", "q9", "q10", "q11", "q12", "q13",
                       "a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "a9", "a10", "a11", "a12", "a13"};
    bool drum[13] = {false};
    int exp = 0, view = 0, z, sector = 1;
    while (exp < 6 && view < 6)
    {
        // for (int i = 0; i < 13; ++i) std::cout << drum[i];
        spin(sector, drum);
        std::cout << "Attention, question - ";
        question.open(path + name[sector - 1] + ".txt");
        while (!question.eof())
        {
            getline(question, buffer);
            std::cout << buffer << std::endl;
        }
        drum[sector - 1] = true;
        question.close();
        std::cin >> Answer;
        answer.open(path + name[sector + 12] + ".txt");
        getline(answer, buffer);
        std::cout << buffer << std::endl;
        if (Answer == buffer)
        {
            std::cout << "Experts +1\n";
            ++exp;
        }
        else
        {
            std::cout << "Viewers +1\n";
            ++view;
        }
        answer.close();
        std::cout << "Score: Experts - " << exp << ", Viewers - " << view << "\n";
    }
    if (exp == 6)
        std::cout << "Experts WINS!!!\n";
    else
        std::cout << "Viewers WINS!!!\n";
    return 0;
}