/**
 * @file Network.cpp
 * @author Joe Biwer
 * @date 12-6-2019
 * @brief Implementation of the Network class
 */

#include "../include/Network.h"
#include "../include/Graph.h"
#include "../include/Node.h"
#include <iostream>

#include "../parameters.h"

Network::Network(Graph _graph, Network::Dimension _dims, Network::Bounds _bounds) {
	graph = _graph; 				// Copying data values into class vars
	dims = _dims;
	bounds = _bounds;
}


void Network::set_dimensions(Network::Dimension _dims) {
	dims = _dims;
}


void Network::construct() {

	// Divide the network into sections
	int dx = G_DIMS_X / dims.x;
	int dy = G_DIMS_Y / dims.y;

	// Creating cells and stations for each cell
	for(int x = 0; x < dims.x; x++) {
		int xVal = (x * dx) + (dx / 2);
		for(int y = 0; y < dims.y; y++) {
			int yVal = (y * dy) + (dy / 2);	
			Node n(graph.size()); 					// Creating new node
			Node::Position pos = {xVal, yVal};
			n.set_position(pos); 					// Setting the position of the node to the middle of the current cell
			n.set_station(); 							// Declaring the node as a station
			graph.add_point(n); 						// Adding the node to the graph
		}
	}

	for(int i = 0; i < graph.size(); i++) {
		Node *n = graph.get_node(i); 											// Get child node
		if(n != NULL)
			if(!n->is_station()) {
				Node::Position pos = n->get_position(); 					// Get position of child node
				int xIndex = pos.x / (G_DIMS_X / dims.x); 				// Get x and y index of it's corresponding cell
				int yIndex = pos.y / (G_DIMS_Y / dims.y);
				
				for(int j = 0; j < graph.size(); j++) { 					// Loop through all of the nodes to try and find the corresponding cell
					Node *par = graph.get_node(j);
					if(par != NULL) {
						par->print();
						if(par->is_station()) { 								// If the node is a station
							Node::Position parPos = par->get_position(); // Obtain position of node
							int parX = parPos.x / (G_DIMS_X / dims.x); 	// If a station, find it's cell indexes
							int parY = parPos.y / (G_DIMS_Y / dims.y);

							//std::cout << " child: (" << xIndex << ", " << yIndex << std::endl;
							//std::cout << " par: (" << parX << ", " << parY << std::endl;

							if(xIndex == parX && yIndex == parY) 			// If the indexes align, connect the node to the station
								par->connect(i, 4);
						}
					}
				}
			}
	}

}


void Network::print() {
	std::cout << " ----- Network Information -----\n";
	std::cout << " Dimensions: " << dims.x << " by " << dims.y << std::endl;
	std::cout << " Boundaries: " << bounds.x << " by " << bounds.y << std::endl;
	std::cout << " Graph:\n";
	graph.print();
}
