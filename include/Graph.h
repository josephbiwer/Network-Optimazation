/**
 * @file Graph.h
 * @author Joe Biwer
 * @date 12-6-2019
 * @brief Creating a graph of Nodes
 */

#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include "Node.h"

class Graph {
	public:

		/**
		 * @brief Initialize the graph as empty
		 * @return none
		 */
		Graph();

		/**
		 * @brief Append the specified Node onto the nodes vector
		 * @param node Node to append onto the vector (add to the graph)
		 * @return none
		 */
		void add_point(Node);

		/**
		 * @brief Print the information about the graph to the terminal
		 * @return none
		 */
		void print();

	private:

		std::vector<Node> nodes;

};

#endif /* _GRAPH_H */
