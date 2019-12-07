#include <iostream>
#include "../include/Node.h"
#include "../include/Graph.h"
#include "../include/Network.h"

int main(int argc, char **argv) {
   
	#ifdef DEBUG
		std::cout << " ----- CSCI443 - Project 4 ----- \n";
		std::cout << " Author: Joe Biwer\n";
		std::cout << " Network Architecture Optimization\n";
	#endif /* DEBUG */

	Node n(1);

	n.connect(1, 4);
	n.connect(3, 2);
	n.disconnect(1);

	Graph g;
	g.add_point(n);
	g.print();

	Network network(
		g,
		(Network::Dimensions){.x = 10, .y = 10},
		(Network::Bounds){.x = 120, .y = 120}
	);

   return 0;
}
