//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_WEIGHTLESSMATRICESFACTORY_H
#define VANILLACNN_CLION_WEIGHTLESSMATRICESFACTORY_H


#include "MatricesFactory.h"
#include "../../ContainersConnectingStrategy/ContainersConnectingStrategy.h"

class WeightlessMatricesFactory : public MatricesFactory
{
public:
    WeightlessMatricesFactory(int matrixHeight, int matrixWidth);
    std::unique_ptr<Container> createContainer() override;

private:
    int matrixHeight;
    int matrixWidth;
};




#endif //VANILLACNN_CLION_WEIGHTLESSMATRICESFACTORY_H
