#include <iostream>
#include "Drib.h"

int main()
{
    Drib drib1;
    Drib drib2;
    short choice;
    void (Drib:: * option[4])(Drib) =
    {
        &Drib::sum,
        &Drib::minus,
        &Drib::mult,
        &Drib::div
    };
    
    drib1.input();
    
    while (true)
    {
        std::cout
            << "1. Plus\n"
            << "2. Minus\n"
            << "3. Mult\n"
            << "4. Div\n"
            << "0. Exit\n";
        std::cin >> choice;
        
        if (choice < 0 || choice>4) { std::cout << "Unknown option!"; continue; }
        if (choice == 0) break;

        drib2.input();
        (drib1.*option[choice - 1])(drib2);
        drib1.print();
    }

    std::cout << "Number of created Dribs: " << Drib::getObjCount() << std::endl;
}