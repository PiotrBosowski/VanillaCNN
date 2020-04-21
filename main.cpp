#include <iostream>
#include "src/model/NeuralNetwork.h"
#include "src/model/Layers/LayerPrototypes/InputLayer.h"
#include "src/model/Layers/LayerPrototypes/ConvolutionLayer.h"
#include "src/model/Layers/LayerPrototypes/DownsamplingLayer.h"
#include "src/model/Layers/LayerPrototypes/FullyConnectedLayer.h"
#include "src/model/Layers/LayerPrototypes/OutputLayer.h"

int main()
{
    NeuralNetwork firstOfTheYear;
    firstOfTheYear.addLayer(new InputLayer(160,160)); //DONT!!! delete the object you pass to the function, the ownership is transferred to unique_ptr from now on
    firstOfTheYear.addLayer(new ConvolutionLayer(6, 5, 5));
    firstOfTheYear.addLayer(new DownsamplingLayer(2, 2));
    firstOfTheYear.addLayer(new ConvolutionLayer(16, 5, 5));
    firstOfTheYear.addLayer(new DownsamplingLayer(2, 2));
    firstOfTheYear.addLayer(new FullyConnectedLayer(120));
    firstOfTheYear.addLayer(new FullyConnectedLayer(100));
    firstOfTheYear.addLayer(new OutputLayer(10));
    firstOfTheYear.compile();
}