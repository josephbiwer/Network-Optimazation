#include <iostream>
#include <stdlib.h>
#include "../include/Node.h"
#include "../include/Graph.h"
#include "../include/Network.h"
#include "../include/GA.h"

#include "../parameters.h"

int main(int argc, char **argv) {
   
	#ifdef DEBUG
		std::cout << " ----- CSCI443 - Project 4 ----- \n";
		std::cout << " Author: Joe Biwer\n";
		std::cout << " Network Architecture Optimization\n";
	#endif /* DEBUG */

	srand(0); 					// Setting random number seed
	Graph g; 					// Creating graph

	// Creating random nodes to add to the array
	for(int i = 0; i < NODE_COUNT; i++) {
		Node n(i); 					// Create new Node
		Node::Position pos = { 		\
			rand() % G_DIMS_X + 1,  \
			rand() % G_DIMS_Y + 1 	\
		};
		n.set_position(pos); 	// Setting the position of the node 
		g.add_point(n); 			// Adding the point to the graph
	}

	Network::Dimension dims = {NET_DIMS_X, NET_DIMS_Y};
	Network::Bounds bounds = {G_DIMS_X, G_DIMS_Y};
	Network network(g, dims, bounds); 			// Creating network

	network.construct();  		// Construct the network

	network.print();

   return 0;
}
