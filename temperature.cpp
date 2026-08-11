#include <iostream>
#include <string>

int main(){
    int temperature = 0;
    std::cout << "Inserisci la temperatura: ";
    std::cin >> temperature;
    
    if(temperature >= 30){
        std::cout << "Temperature is so high!";
    } else if(temperature >= 10 && temperature <= 20){
        std::cout << "Temperature is warm!";
    } else if(temperature >= 0 && temperature <= 10){
        std::cout << "Temperature is low!";    
    }
    
    return 0;
}
