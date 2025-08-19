#include <iostream>

int main() {
    std::cout << "hello world!" << std::endl;
    
    int array[] = {10,20,30,40,50};
    int sum= 0;
    for (int i = 0; i<5; i++){
             sum+= array[i];
    }
    std::cout << "Array sum: " << sum << std::endl;
}	


