#pragma once

#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <cinttypes>
#include <vector>

#include "constants.hpp"

enum MenuItems {
  Congratulate = 1,
  Exit,
  PrintData,
  StoreData
};

struct PersonInfo
{
    std::string name;
    int age;
};

std::ostream& operator<<(std::ostream& os, PersonInfo const &user_data) { 
    return os << "{ Name: " << user_data.name 
              << ", Age: " << user_data.age << "}";
}

void clear_stream(std::istream& stream) {
    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

PersonInfo congratulate() {
    std::string name;
    do
    {
      std::cout << "Как тебя зовут?" << std::endl;
      std::cin >> name;
      clear_stream(std::cin);

      for (char c : name)
      {
          if (!isalpha(c))
          {
              std::cout << "Неправильный формат имени: можно ввести только буквы, недопустимый символ: "
                        << c << std::endl;
              continue;
          }
      }
    } while (!std::cin);

    int age = 0;
    do
    {
        std::cout << "Сколько тебе лет?" << std::endl;
        std::cin >> age;
        clear_stream(std::cin);
    } while (!std::cin);

    std::cout << std::endl
            << name << ", поздравляю тебя!" << std::endl
            << "Сегодня тебе " << age << " лет" << std::endl
            << "Желаю счастья и здоровья!" << std::endl;

    if (age >= 35 && age <= 60)
    {
        std::cout << constants::note << std::endl 
                        << std::endl 
                        << std::endl;
    }

    PersonInfo info;
    info.age = age;
    info.name = name;
    return info;
}

bool run(std::vector<PersonInfo>& data) {
    bool is_running = true;
    
    std::uint16_t menu_item_id = 0;
    std::cout << constants::welcome_menu << std::endl;
    std::cin >> menu_item_id;

    switch (menu_item_id)
    {
    case MenuItems::Congratulate:
      {
        PersonInfo info = congratulate();
        data.push_back(info);
      }
      break;
    case MenuItems::Exit:
        std::cout << "Цикл завершен\n\n" << std::endl;
        is_running = false;
        break;
    case MenuItems::PrintData:
        for(PersonInfo& user_data : data) {
            std::cout << user_data << ",\n";
        }
        break;
    case MenuItems::StoreData:
        {
            std::filesystem::path path_to_file = std::filesystem::absolute(constants::output_file_name);
            std::cout << "Path to file: " << path_to_file << std::endl;

            if(std::ofstream file{path_to_file}) {
                for(PersonInfo& user_data : data) {
                    file << user_data << ",\n";
                }
            } else {
                std::cerr << "ERROR: can't open file " << constants::output_file_name;
            }
        }
        break;
    default:
        std::cerr << "ERROR: invalid menu item id " << menu_item_id;
        break;
    }

    clear_stream(std::cin);

    return is_running;
}