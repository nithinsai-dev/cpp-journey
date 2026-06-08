#include <iostream>

namespace first{
    int x =1;
}

namespace second{
    int x = 2;
}

int main(){
    using namespace first;
    std::cout << "Namespace first is " << x << '\n';
    std::cout << "Namespace second is " << second::x << '\n';

    return 0;
}