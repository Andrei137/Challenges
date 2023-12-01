#include "Interface.hpp"
#include "MarkovGenerator.hpp"
#include <rlutil.h>
#include <iostream>

void Interface::run(const str& a_file_name)
{
    MarkovGenerator generator{ a_file_name };

    rlutil::cls();
    rlutil::setColor(rlutil::LIGHTGREEN);
    std::cout << "Markov Chain Generator\n";
    rlutil::setColor(rlutil::WHITE);
    std::cout << "[1] Generate a normal sentence\n";
    std::cout << "[2] Generate a shitpost sentence\n";
    std::cout << "[0] Exit\n";
    std::cout << "-> ";

    int choice{};
    std::cin >> choice;
    rlutil::cls();
    if (choice != 1 && choice != 2)
    {
        return;
    }
    std::cin.ignore();
    std::cout << generator.generate_sentence(choice == 2) << '\n';
}

Interface& Interface::get_instance()
{
    static Interface instance;
    return instance;
}