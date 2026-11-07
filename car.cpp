#include <iostream>

class Car
{
  public:
    virtual void displayInfo() const = 0; // Pure virtual function
    virtual void startEngine() const = 0; // Pure virtual function
    virtual void stopEngine() const = 0;  // Pure virtual function
    virtual ~Car()
    {
    } // Virtual destructor
};

class BMWCar : public Car
{
  public:
    BMWCar(const std::string &model, int year) : model_(model), year_(year)
    {
    }
    void displayInfo() const
    {
        std::cout << "Car Model: " << model_ << ", Year: " << year_ << std::endl;
    }
    void setFuelEfficiency(double efficiency)
    {
        fuelEfficiency_ = efficiency;
    }
    double getFuelEfficiency() const
    {
        return fuelEfficiency_;
    }
    void setColor(int color)
    {
        color_ = color;
    }
    int getColor() const
    {
        return color_;
    }
    void startEngine() const
    {
        isEngineRunning_ = true;
        std::cout << "Engine started for " << model_ << " (" << year_ << ")" << std::endl;
    }
    void stopEngine() const
    {
        isEngineRunning_ = false;
        std::cout << "Engine stopped for " << model_ << " (" << year_ << ")" << std::endl;
    }

  private:
    std::string model_;
    int year_;
    double fuelEfficiency_;        // Fuel efficiency in miles per gallon
    int color_;                    // Color represented as an integer (e.g., RGB value)
    bool isEngineRunning_ = false; // Engine state
};