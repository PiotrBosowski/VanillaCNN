//
// Created by piotr on 20/04/11.
//

#ifndef VANILLACNN_CLION_DOWNSAMPLINGLAYER_H
#define VANILLACNN_CLION_DOWNSAMPLINGLAYER_H

#include "PrototypeLayer.h"

class DownsamplingLayer : public PrototypeLayer
{
public:
    DownsamplingLayer(int downsamplerHeight, int downsamplerWidth);
    std::unique_ptr<Layer> embodyLayer(Layer* previousLayer) override;

private:
    int downsamplerHeight;
    int downsamplerWidth;
};

#endif //VANILLACNN_CLION_DOWNSAMPLINGLAYER_H
