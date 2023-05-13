#include <locale>

#include "buisness_logic.hpp"

int main()
{
#if defined(WIN32)
    setlocale(LC_ALL, "ru_RUS.utf8");
#endif

    std::vector<PersonInfo> data;
    while (run(data)) {};

    return EXIT_SUCCESS;

    {
        // int menu2;
        // std::cout << "Хотите ли вы вывести информацию в таблицу?"
        //<< std::endl
        //<< "1. Да" << std::endl
        //<< "2. Нет" << std::endl;
        // std::cin >> menu2;

        // if (std::cin.fail()) {
        // std::cout << "Ошибка! Ввести можно только число 1 или 2" << std::endl << std::endl << std::endl;
        // std::cin.clear();
        // std::cin.ignore(1000, '\n');
        //} else if (menu2 == 1) {
        // const int ROWS = n;
        // std::const int COLS = 2;
        //}

        // std::ofstream file(NameAges.txt);
        // if (!file.is_open()) {
        // std::cout << "Закройте файл. Запись невозможна" << std::endl;
        // return 1

        // file << age, name << std::endl;

        //}
    } 
}
