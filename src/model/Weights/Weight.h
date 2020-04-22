//
// Created by piotr on 20/04/21.
//

#ifndef VANILLACNN_CLION_WEIGHT_H
#define VANILLACNN_CLION_WEIGHT_H



#include <random>

class Weight {
public:
    Weight();

    //because of the random-like nature of Weight, copying it can be misleading - copying operators are deleted
    Weight(const Weight&) = delete;
    explicit Weight(double init);
    Weight& operator=(Weight) = delete;
    Weight& operator=(double);
    explicit operator double() const;


private:
    double weight;

    static double getRandomWeight();
};


#endif //VANILLACNN_CLION_WEIGHT_H
