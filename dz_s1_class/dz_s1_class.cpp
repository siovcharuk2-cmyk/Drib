#include <iostream>
#include "Drib.h"

int main()
{
    Drib drib1;
    Drib drib2;
    short choice;
    
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
        
        if (choice == 0) break;

        drib2.input();
        switch (choice)
        {
        case 1:
            drib1 = drib1 + drib2;
            break;
        case 2:
            drib1 = drib1 - drib2;
            break;
        case 3:
            drib1 = drib1 * drib2;
            break;
        case 4:
            drib1 = drib1 / drib2;
            break;
        }
        drib1.print();
    }

    std::cout << "Number of created Dribs: " << Drib::getObjCount() << std::endl;
}