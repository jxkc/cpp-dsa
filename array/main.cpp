#include <iostream>
#include "ary.h"

int main(){
    Array<int, 3> arr;

    arr[0] = 10;
    arr[2] = 10;

    std::cout << arr.to_string() << std::endl;

    std::cout << "size: " << arr.size() << std::endl;
    std::cout << "size: " << arr.max_size() << std::endl;

    return 0;
}
