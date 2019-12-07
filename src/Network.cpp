/**
 * @file Network.cpp
 * @author Joe Biwer
 * @date 12-6-2019
 * @brief Implementation of the Network class
 */

#include "../include/Network.h"
#include "../include/Graph.h"
#include <iostream>

Network::Network(
	Graph _graph,
	Network::Dimension _dims = (Network::Dimension){.x=1, .y=1},
	Network::Bounds _bounds = (Network::Bounds){.x=100, .y=100})
{
	std::cout << "Initializing Network\n";
}
