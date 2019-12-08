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

}

void Graph::add_point(Node node) {
	nodes.push_back(node);
}

int Graph::size() {
	return nodes.size();
}

Node* Graph::get_node(int index) {
	if(index < nodes.size())
		return &nodes[index];
	return NULL;
}

void Graph::print() {
	std::cout << "Printing graph contents:\n";
	for(int i = 0; i < nodes.size(); i++)
		nodes[i].print();
}
