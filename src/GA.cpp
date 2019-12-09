/**
 * @file GA.cpp
 * @author Joe Biwer
 * @date 12/8/2019
 * @brief Implementation of the GA class
 */

#include "../include/GA.h"
#include "../include/Network.h"
#include "../include/Graph.h"
#include <vector>
#include <iostream>

GA::GA(int _gens, int _popSize) {
	gens = _gens;
	popSize = _popSize;
}

float GA::calculateFitness(Network *network) {
	Graph g = network->graph;
	float distance = 0;
	for(int i = 0; i < graph.nodes.size(); i++) {
		Node n = graph.nodes[i];
		for(int j = 0; j < n.connections.size(); j++)
			distance += n.connections[j].distance;	
	}

	return distance;
}
