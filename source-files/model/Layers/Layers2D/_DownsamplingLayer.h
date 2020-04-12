//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION__DOWNSAMPLINGLAYER_H
#define VANILLACNN_CLION__DOWNSAMPLINGLAYER_H


#include <memory>
#include <string>
#include "Layer2D.h"


class _DownsamplingLayer : public Layer2D
{
public:
    _DownsamplingLayer(Layer* previousLayer, int downsamplerHeight, int downsamplerWidth);

    std::string getSummary() override;

protected:
    int downsamplerHeight;
    int downsamplerWidth;

public:
    int getDownsamplerHeight();
    int getDownsamplerWidth();
};



#endif //VANILLACNN_CLION__DOWNSAMPLINGLAYER_H
