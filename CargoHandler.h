
#ifndef CARGOHANDLER_H
#define CARGOHANDLER_H

class CargoHandler
{
    public:
        CargoHandler();
        ~CargoHandler();
        void add(CargoHandler* n);
        virtual void handleCargo(Cargo* c);
    private:
        CargoHandler* next;
};

#endif
