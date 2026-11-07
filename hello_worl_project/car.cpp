#include "Car.h"
#include "BaseCar.h"
#include <iostream>

BMWCar::BMWCar(const std::string &model, int year) : model_(model), year_(year)
{
}

void BMWCar::setFuelEfficiency(double efficiency)
{
    fuelEfficiency_ = efficiency;
}
double BMWCar::getFuelEfficiency() const
{
    return fuelEfficiency_;
}
void BMWCar::setColor(int color)
{
    color_ = color;
}
int BMWCar::getColor() const
{
    return color_;
}