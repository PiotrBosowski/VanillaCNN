//
// Created by piotr on 20/04/13.
//

#ifndef VANILLACNN_CLION_IPRINTABLE_H
#define VANILLACNN_CLION_IPRINTABLE_H


#include <string>

struct IPrintable {
    virtual std::string getSummary() = 0;
};


#endif //VANILLACNN_CLION_IPRINTABLE_H
