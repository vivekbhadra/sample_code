#pragma once

class Car
{
  public:
    virtual void displayInfo() const = 0; // Pure virtual function
    virtual void startEngine() = 0;       // Pure virtual function
    virtual void stopEngine() = 0;        // Pure virtual function
    virtual ~Car()
    {
    } // Virtual destructor
};