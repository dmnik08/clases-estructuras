#include <iostream>
#include <cstdlib>
#include <iomanip>

int main(int arcg, char **argv) {
    std::srand(std::time(nullptr));

    for (int i=0; i< arcg; i++)
            std::cout << "[" << std::setw(4) << i << "]:" << argv[i] << std::endl;
}