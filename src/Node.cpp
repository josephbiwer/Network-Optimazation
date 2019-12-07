/**
 * @file Node.cpp
 * @author Joe Biwer
 * @date 12-6-2019
 * @brief Implementation of Node functions
 */

#include "../include/Node.h"
#include <iostream>

Node::Node(int _id) {
	std::cout << "Initializing a new Node\n";	
	id = _id;
}

void Node::connect(int index, int distance) {
	Connection conn;
	conn.index = index;
	conn.distance = distance;
	connections.push_back(conn);	
}

int Node::disconnect(int index) {
	for(int i = 0; i < connections.size(); i++)
		if(connections[i].index == index) {
			connections.erase(connections.begin() + i);
			return true;
		}
	return false;
}

void Node::print() {
	
	std::cout << "Node " << id << std::endl;
	std::cout << " - connections:\n";
	for(int i = 0; i < connections.size(); i++) {
		std::cout << "   [" << i << "]: {";	
		std::cout << "index: " << connections[i].index << ", ";
		std::cout << "distance: " << connections[i].distance << "}\n";
	}
}
