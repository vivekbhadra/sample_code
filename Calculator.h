class Calculator
{
  public:
    // list initializer
    Calculator();
    Calculator(int f);
    int normalize(int val);
    int get_factor();

  private:
    int factor{ 2 };
};