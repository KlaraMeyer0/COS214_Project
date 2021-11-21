#include "OrderCargo.h"

OrderCargo::OrderCargo(BaseStation *b)
{
    equipment_factory = new EquipmentFactory();
    human_factory = new HumanFactory();
    base_station = b;
}
OrderCargo::~OrderCargo()
{
    delete equipment_factory;
    delete human_factory;
}

void OrderCargo::execute()
{
    Cargo *cargo;
    int choice;
    bool valid;
    bool flag;
    bool done = false;
    int amount = 0;
    while (!done)
    {
        do
        {
            flag = false;
            valid = true;
            cout << "What do you want to do? Choose the corresponding number: " << endl;
            cout << "1. Recruit humans" << endl;
            cout << "2. Order equipment" << endl;
            cout << "3. Quit" << endl;
            cin >> choice;

            string cargo_string;
            switch (choice)
            {
            case 1:
                cout << "Enter the name of the human you want to recruit: ";
                cin >> cargo_string;
                cargo = human_factory->startFactory(cargo_string);
                break;
            case 2:
                cout << "What equipment do you want to order: ";
                cin >> cargo_string;
                cout << "How many " << cargo_string << "s do you want to order: ";
                cin >> amount;
                while (!cin.good() || amount <= 0)
                {
                    cin.clear();
                    cin.ignore(15, '\n');
                    cout << "Please enter a valid number: ";
                    cin >> amount;
                }
                cargo = equipment_factory->startFactory(cargo_string);
                break;
            case 3:
                cout << "Exiting..." << endl;
                valid = false;
                done = true;
                break;
            default:
                cout << "Input was not a number or out of range" << endl;
                flag = true;
                break;
            }
        } while (flag);
        if (valid)
        {
            for (int i = 0; i < amount; i++)
                base_station->receiveCargo(cargo);  //Many instances of cargo must be created. How?
        }
    }
}

void OrderCargo::undo() {}