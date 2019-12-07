/**
 * @file Graph.cpp
 * @author Joe Biwer
 * @date 12-6-2019
 * @brief Implementation of the Graph class
 */

#include "../include/Graph.h"
#include "../include/Node.h"
#include <iostream>

Graph::Graph() {
	std::cout << "Creating graph\n";	
}

void Graph::add_point(Node node) {
	nodes.push_back(node);
}

void Graph::print() {
	std::cout << "Printing graph contents:\n";
	for(int i = 0; i < nodes.size(); i++)
		nodes[i].print();
}
