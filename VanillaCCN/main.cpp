#include <iostream>
#include "NeuralNetwork.h"
#include "InputLayer.h"
#include "ConvolutionLayer.h"
#include "DownsamplingLayer.h"
#include "FullyConnectedLayer.h"
#include "OutputLayer.h"
#include <optional>

int main()
{
	try
	{
		NeuralNetwork firstOfTheYear;
		firstOfTheYear.addLayer(new InputLayer{ 32, 32 }); //dont!!! delete the object you pass to the function, the ownership is transferred to unique_ptrs from now on
		firstOfTheYear.addLayer(new ConvolutionLayer(6, 5, 5));
		firstOfTheYear.addLayer(new DownsamplingLayer(2, 2));
		firstOfTheYear.addLayer(new ConvolutionLayer(16, 5, 5));
		firstOfTheYear.addLayer(new DownsamplingLayer(2, 2));
		firstOfTheYear.addLayer(new FullyConnectedLayer(120));
		firstOfTheYear.addLayer(new FullyConnectedLayer(100));
		firstOfTheYear.addLayer(new OutputLayer(10));
		firstOfTheYear.compile();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "unknown error" << std::endl;
	}
}