#include <iostream>




int main()
{
    int w = 0;
    int x = 1;
    int y = 2;
    int z = 3;
    std::cout << "Stack memory: \n";
    std::cout <<std::dec << &w <<'\n' << &x << '\n' << &y << '\n' << &z << '\n';

    std::cout << "Heap memory: \n";
    int* heapMem = new int[4] {0,1,2,3};
    std::cout <<&heapMem[0] << '\n';
    std::cout << &heapMem[1] << '\n';
    std::cout << &heapMem[2] << '\n';
    std::cout << &heapMem[3] << '\n';


    return 0;
}


