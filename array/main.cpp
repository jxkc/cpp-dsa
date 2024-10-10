#include <iostream>
#include "ary.h"
#include "uary.h"

int array_sandbox() {
    Array<int, 3> arr ;

    arr.at(0) = 10;
    arr[1] = 10;

    std::cout << arr.to_string() << std::endl;


    std::cout << arr.to_string() << std::endl;

    std::cout << "size: " << arr.size() << std::endl;
    std::cout << "size: " << arr.max_size() << std::endl;

    return 0;
}

int unsorted_sandbox() {

    UnsortedArray<int, 3> uarr;

    uarr.insert(20);
    uarr.insert(20);
    uarr.insert(20);


    std::cout << uarr.to_string() << std::endl;

    uarr.remove(2);

    std::cout << "size: " << uarr.size() << std::endl;
    std::cout << "size: " << uarr.max_size() << std::endl;

    std::cout << uarr.to_string() << std::endl;

    return 0;
}

int main(){

    Array<Array<int, 3>, 3> arr3;


    arr3.at(0).at(9);


    std::cout << arr3.at(0).to_string();

    return 0;
}
