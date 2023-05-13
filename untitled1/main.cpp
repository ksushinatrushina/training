#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

int main()
{
    bool is_running = true;
    while (is_running)
    {

        int menu;
        std::cout << "Выбери пункт меню, указав соответствующую цифру" << std::endl
                  << "1. Получить поздравление" << std::endl
                  << "2. Завершить и выйти из цикла" << std::endl;
        std::cin >> menu;

        if (menu == 1)
        {
            std::string name;
            std::cout << "Как тебя зовут?" << std::endl;
            std::cin >> name;
                bool valid = true;
                for (char c : name)
                {
                    if (!isalpha(c))
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    std::cout << "Неправильный формат имени: можно ввести только буквы" << std::endl;
        }

        int age;
        std::cout << "Сколько тебе лет?" << std::endl;
        std::cin >> age;

            if (std::cin.fail()) {
                std::cout << "Ошибка! Ввести можно только число" << std::endl << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');

                do {
                    std::cout << "Сколько тебе лет?" << std::endl;
                    std::cin >> age;

                    std::cout << std::endl << name << ", поздравляю тебя!" << std::endl;
                    std::cout << "Сегодня тебе " << age << " лет" << std::endl;
                    std::cout << "Желаю счастья и здоровья!" << std::endl;

                    if (age >= 35 && age <= 60) {
                        std::cout << std::endl <<
                                  "Кризис среднего возраста — это эмоциональное состояние, которое человек испытывает в возрасте 30–50 лет."
                                  << std::endl <<
                                  "Чаще всего оно связано с переоценкой жизненного опыта." << std::endl <<
                                  "Кажется, что многие возможности и мечты юности упущены, при этом старость (или смерть) наступит довольно скоро."
                                  << std::endl <<
                                  "У разных людей кризис наступает в разном возрасте, это зависит от индивидуальных особенностей."
                                  << std::endl <<
                                  std::endl <<
                                  "Как пережить кризис среднего возраста:" << std::endl <<
                                  "1. Заботьтесь о себе" << std::endl <<
                                  "2. Следите за здоровьем" << std::endl <<
                                  "3. Примите изменения" << std::endl <<
                                  "4. Тренируйте мозг" << std::endl <<
                                  "5. Получайте новые эмоции" << std::endl;

                        std::cout << std::endl << std::endl;
                        continue;
                    }
                    continue;
                } while (!std::cin.fail());
            }
        }

        if (menu == 2) {
            std::cout << "Цикл завершен" << std::endl << std::endl << std::endl;
        }

        if (std::cin.fail())
        {
            std::cout << "Ошибка! Ввести можно только число 1 или 2" << std::endl << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        //int menu2;
        //std::cout << "Хотите ли вы вывести информацию в таблицу?"
                  //<< std::endl
                  //<< "1. Да" << std::endl
                  //<< "2. Нет" << std::endl;
        //std::cin >> menu2;

       //if (std::cin.fail()) {
            //std::cout << "Ошибка! Ввести можно только число 1 или 2" << std::endl << std::endl << std::endl;
            //std::cin.clear();
            //std::cin.ignore(1000, '\n');
        //} else if (menu2 == 1) {
            //std::const int ROWS = n;
            //std::const int COLS = 2;
        //}

            //std::ofstream file(NameAges.txt);
            //if (!file.is_open()) {
                //std::cout << "Закройте файл. Запись невозможна" << std::endl;
                //return 1


            //file << age, name << std::endl;


        //}
    }
}
