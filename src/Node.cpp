/**
 * @file Node.cpp
 * @author Joe Biwer
 * @date 12-6-2019
 * @brief Implementation of Node functions
 */

#include "../include/Node.h"
#include <iostream>

Node::Node(int _id) {
	pos.x = pos.y = 1;
	id = _id;
	station = false;
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

void Node::set_position(Position _pos) {
	pos = _pos;
}

Node::Position Node::get_position() {
	return pos;
}

void Node::set_station() {
	station = true;
}

bool Node::is_station() {
	return station;
}

void Node::print() {
	
	std::cout << "Node " << id << std::endl;
	
	if(station)
		std::cout << " - Station\n";

	std::cout << " - pos: (" << pos.x << ", " << pos.y << ")\n";

	if(connections.size() > 0) {
		std::cout << " - connections:\n";
		for(int i = 0; i < connections.size(); i++) {
			std::cout << "   [" << i << "]: {";	
			std::cout << "index: " << connections[i].index << ", ";
			std::cout << "distance: " << connections[i].distance << "}\n";
		}
	}
}
