#include <iostream>
#define BOOST_ERROR_CODE_HEADER_ONLY 1
#include "test.h"

int main(int argc, char** argv) {
    std::cout << "Hello World" << std::endl;
    marshal::test();

    return 0;
}
