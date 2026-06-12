#include <iostream>

int main(){
    std::string name;
    int age;

    std::cout << "Whats Your name ? ";
    std::cin >> name;

    std::cout << "Whats your age ? ";
    std::cin >> age;


    std::cout << "Hi ur name is " << name << " and ur age is " << age;
    return 0;
}