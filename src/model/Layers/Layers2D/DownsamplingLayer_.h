//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_DOWNSAMPLINGLAYER__H
#define VANILLACNN_CLION_DOWNSAMPLINGLAYER__H


#include <memory>
#include <string>
#include "Layer2D.h"


class DownsamplingLayer_ : public Layer2D
{
public:
    DownsamplingLayer_(Layer* previousLayer, int downsamplerHeight, int downsamplerWidth);

    std::string getSummary() override;

protected:
    int downsamplerHeight;
    int downsamplerWidth;

public:
    int getDownsamplerHeight();
    int getDownsamplerWidth();

    void connect() override;

    void populate() override;
};



#endif //VANILLACNN_CLION_DOWNSAMPLINGLAYER__H
