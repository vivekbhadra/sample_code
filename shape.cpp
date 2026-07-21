#include <iostream>
#include <vector>

class Shape
{
  public:
    virtual void draw() = 0; // pure virtual function making Shape an abstract class
    virtual ~Shape()
    {
    } // virtual destructor for proper cleanup of derived class objects
};

class Circle : public Shape
{
  public:
    void draw() override // overriding the base class method
    {
        std::cout << "Drawing a Circle\n";
    }
};

class Square : public Shape
{
  public:
    void draw() override // overriding the base class method
    {
        std::cout << "Drawing a Square\n";
    }
};

class Triangle : public Shape
{
  public:
    void draw() override // overriding the base class method
    {
        std::cout << "Drawing a Triangle\n";
    }
};

void drawShape(std::vector<Shape *> shapes)
{
    for (Shape *shape : shapes)
    {
        shape->draw(); // calls the appropriate draw method based on the actual object type
    }
}

int main()
{
    std::vector<Shape *> shapes; // vector to hold Shape pointers

    shapes.push_back(new Circle());
    shapes.push_back(new Square());
    shapes.push_back(new Triangle());

    drawShape(shapes);

    for (Shape *shape : shapes)
    {
        delete shape; // free the allocated memory
    }

    return 0;
}