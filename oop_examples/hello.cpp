#include <iostream>
#include <string>

struct Car
{
  public:
    Car();
    void setSpeed(int s);
    int getSpeed() const;
    void setColor(int c);
    int getColor() const;
    void setModel(const std::string &m);
    std::string getModel() const;
    void setManufacturer(const std::string &m);
    std::string getManufacturer() const;
    void setRegistration(const std::string &r);
    std::string getRegistration() const;
    void setFuelLevel(double f);
    double getFuelLevel() const;
    ~Car();

  private:
    int speed;
    int color;
    std::string model;
    std::string manufacturer;
    std::string registration;
    double fuel_level;
};

Car::Car() : speed{ 0 }, color{ 0 }, model{ "" }, manufacturer{ "" }, registration{ "" }, fuel_level{ 0.0 }
{
    std::cout << "Car object created." << "\n";
}
void Car::setSpeed(int s)
{
    speed = s;
    std::cout << "Speed set to: " << speed << " km/h" << "\n";
}
int Car::getSpeed() const
{
    std::cout << "Getting speed: " << speed << " km/h" << "\n";
    return speed;
}
void Car::setColor(int c)
{
    color = c;
    std::cout << "Color set to: " << color << "\n";
}
int Car::getColor() const
{
    std::cout << "Getting color: " << color << "\n";
    return color;
}
void Car::setModel(const std::string &m)
{
    model = m;
    std::cout << "Model set to: " << model << "\n";
}
std::string Car::getModel() const
{
    std::cout << "Getting model: " << model << "\n";
    return model;
}
void Car::setManufacturer(const std::string &m)
{
    manufacturer = m;
    std::cout << "Manufacturer set to: " << manufacturer << "\n";
}
std::string Car::getManufacturer() const
{
    std::cout << "Getting manufacturer: " << manufacturer << "\n";
    return manufacturer;
}
void Car::setRegistration(const std::string &r)
{
    registration = r;
    std::cout << "Registration set to: " << registration << "\n";
}
std::string Car::getRegistration() const
{
    std::cout << "Getting registration: " << registration << "\n";
    return registration;
}
void Car::setFuelLevel(double f)
{
    fuel_level = f;
    std::cout << "Fuel level set to: " << fuel_level << " liters" << "\n";
}
double Car::getFuelLevel() const
{
    std::cout << "Getting fuel level: " << fuel_level << " liters" << "\n";
    return fuel_level;
}
Car::~Car()
{
    std::cout << "Car object destroyed." << "\n";
}

int main()
{
    Car myCar;
    myCar.setSpeed(120);
    myCar.setColor(1);
    myCar.setModel("Sedan");
    myCar.setManufacturer("Toyota");
    myCar.setRegistration("ABC123");
    myCar.setFuelLevel(50.5);

    std::cout << "Car Details:" << "\n";
    std::cout << "Speed: " << myCar.getSpeed() << " km/h" << "\n";
    std::cout << "Color: " << myCar.getColor() << "\n";
    std::cout << "Model: " << myCar.getModel() << "\n";
    std::cout << "Manufacturer: " << myCar.getManufacturer() << "\n";
    std::cout << "Registration: " << myCar.getRegistration() << "\n";
    std::cout << "Fuel Level: " << myCar.getFuelLevel() << " liters" << "\n";

    return 0;
}