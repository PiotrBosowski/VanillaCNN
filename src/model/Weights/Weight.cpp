//
// Created by piotr on 20/04/21.
//

#include "Weight.h"

Weight::Weight() : weight(getRandomWeight()) {}

double Weight::getRandomWeight() {
    static std::mt19937 rng{std::random_device()()};
    static std::uniform_real_distribution uni(0.10, 1.00);
    return uni(rng);
}

Weight::operator double() const {
    return weight;
}

Weight::Weight(double init)
: weight(init)
{
}

Weight &Weight::operator=(double new_value) {
    weight = new_value;
    return *this;
}
