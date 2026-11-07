#include "Car.h"
#include <iostream>
int main()
{
    BMWCar myCar(std::string("BMW X5"), 2022);
    myCar.setFuelEfficiency(25.5);
    myCar.setColor(0xFF5733); // Example color in hexadecimal (RGB)

    myCar.displayInfo();
    std::cout << "Fuel Efficiency: " << myCar.getFuelEfficiency() << " MPG" << std::endl;
    std::cout << "Color: " << std::hex << myCar.getColor() << std::dec << std::endl;

    myCar.startEngine();
    myCar.stopEngine();

    return 0;
}