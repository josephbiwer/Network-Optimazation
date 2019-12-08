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
		 * @brief Get node from the nodes vector, specified by array index
		 * @param index Index of the node in the nodes vector
		 * @return Specified node (as pointer)
		 */
		Node* get_node(int);

		/**
		 * @brief Get the size of the graph
		 * @return Size of the graph
		 */
		int size();

		/**
		 * @brief Print the information about the graph to the terminal
		 * @return none
		 */
		void print();

	private:

		std::vector<Node> nodes;

};

#endif /* _GRAPH_H */
