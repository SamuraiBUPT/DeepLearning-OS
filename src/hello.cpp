//
// Created by 27813 on 2023-02-24.
//
#include "hello.h"
#include <iostream>

Hello::Hello() {
    std::cout << "This is our Operating System demo." << std::endl;
    std::cout << "This gonna be a brilliant project." << std::endl;
    std::cout
            << "If needed, please check https://github.com/ttroy50/cmake-examples/tree/master/01-basic/B-hello-headers for further help."
            << std::endl;
}

Hello::~Hello() {
    delete[] this->ptr_arr;
}


