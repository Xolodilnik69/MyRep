#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

void recursive(nlohmann::json &j, const std::string &key1, const std::string &name1, std::vector<std::string> &film1, bool &fin1, bool &act1)
{
  std::string name;
  std::string family;
  for (auto &[key, value] : j.items())
  {
    if (key.find("Actor") != std::string::npos)
      act1 = true;
    if ((act1 || fin1) && key == "family")
    {
      name = j.at("name").get<std::string>();
      family = j.at("family").get<std::string>();
      if (fin1)
      {
        film1.emplace_back("\tin role: " + name + " " + family);
        fin1 = false;
      }
      if (name == name1 || family == name1)
      {
        if (film1.size() == 0)
        {
          film1.emplace_back(name + " " + family);
        }
        fin1 = true;
        film1.emplace_back(key1);
      }
      act1 = false;
    }
    if (!key.empty())
      recursive(value, key1, name1, film1, fin1, act1);
  }
}

int main()
{
  bool fin = false, act = false;
  nlohmann::json dict;
  std::vector<std::string> film;
  std::string Name; 
  std::ifstream file{"record1.json"};
  if (!file.is_open())
  {
    std::cerr << "Unable to open file\n";
    throw 1;
  }
  dict = nlohmann::json::parse(file);
  file.close();
  while (Name!="e"){
  std::cout << "Enter the name of the actor you want to find(e-exit): ";
  std::cin >> Name;
  for (auto &[key, value] : dict.items())
  {
    recursive(value, key, Name, film, fin, act);
  }
  if (film.size())
  {
    std::cout << film[0] << " playing in:" << std::endl;
    for (int i = 1; i < film.size(); ++i)
    {
      std::cout << film[i] << std::endl;
    }
  }
  else
    std::cout << Name << " not found!" << std::endl;
  }
}