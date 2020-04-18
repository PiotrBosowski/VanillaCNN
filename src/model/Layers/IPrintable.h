//
// Created by piotr on 20/04/13.
//

#ifndef VANILLACNN_CLION_IPRINTABLE_H
#define VANILLACNN_CLION_IPRINTABLE_H


#include <sstream>

struct IPrintable {
    virtual std::string getName() = 0;
    virtual std::stringstream getSummary() = 0;
};


#endif //VANILLACNN_CLION_IPRINTABLE_H
