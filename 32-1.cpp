#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

struct Record
{
  std::string movie;
  std::string country;
  std::string mans[8] = {"Director", "Writer", "1st Actor", "1st Role", "2st Actor", "2st Role", "3st Actor", "3st Role"};
  std::string name[8];
  std::string family[8];
  int year;
};

int main()
{
  Record record;
  nlohmann::json dict;
  std::cout << "Enter the film:\n";
  std::getline(std::cin, record.movie);
  std::cout << "Enter the country:\n";
  std::getline(std::cin, record.country);
  std::cout << " and year production:\n";
  std::cin >> record.year;

  if (record.year < 1900 || record.year > 2024)
  {
    std::cout << "Wrong year!";
    return 1;
  }
  for (int i = 0; i < 8; ++i)
  {
    std::cout << "Input name and family " << record.mans[i] << ":\n";
    std::cin >> record.name[i] >> record.family[i];
  }

  dict[record.movie][" country"] = record.country;
  dict[record.movie][" year"] = record.year;
  for (int i = 0; i < 8; ++i)
  {
    dict[record.movie][record.mans[i]]["name"] = record.name[i];
    dict[record.movie][record.mans[i]]["family"] = record.family[i];
  }
  std::ofstream file("record.json");
  if (file.is_open())
  {
    file << std::setw(4) << dict;
  }
}