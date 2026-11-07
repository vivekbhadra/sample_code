#pragma once

#include "BaseCar.h"
#include <iostream>
#include <string>

class BMWCar : public Car
{
  public:
    BMWCar(const std::string &model, int year);
    void displayInfo() const override
    {
        std::cout << "Car Model: " << model_ << ", Year: " << year_ << std::endl;
    }
    void startEngine() override
    {
        isEngineRunning_ = true;
        std::cout << "Engine started for " << model_ << " (" << year_ << ")" << std::endl;
    }
    void stopEngine() override
    {
        isEngineRunning_ = false;
        std::cout << "Engine stopped for " << model_ << " (" << year_ << ")" << std::endl;
    }
    void setFuelEfficiency(double efficiency);
    double getFuelEfficiency() const;
    void setColor(int color);
    int getColor() const;

  private:
    std::string model_;
    int year_;
    double fuelEfficiency_;        // Fuel efficiency in miles per gallon
    int color_;                    // Color represented as an integer (e.g., RGB value)
    bool isEngineRunning_ = false; // Engine state
};