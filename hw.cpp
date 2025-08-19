#include <iostream>
#include <cstdlib>

int main() {
    std::srand(std::time(nullptr));
    std::cout << "hello world!" << std::endl;
    
    int array[10];
    int sum= 0;
    for (int i = 0; i<10; i++){
             array[i] = std ::rand ();
             sum+= array[i];

    }
    for (int i =0; i<10; i++)
            std::cout<< "[" << i << "]:" << array[i] << std::endl;
    std::cout << "Array sum: " << sum << std::endl;
}	


