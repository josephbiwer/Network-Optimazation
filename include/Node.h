/**
 * @file Node.h
 * @author Joe Biwer
 * @date 12-6-2019
 * @brief Class declaration of a Node
 */


#ifndef _NODE_H
#define _NODE_H

#include <vector>

class Node {
	public:

		/**
		 * @brief Constructor that initializes the node
		 * @param id Unique identifier for the Node
		 * @return none
		 */
		Node(int);

		/**
		 * @brief Make a connection to another Node
		 * @param index Index of the specified node to attach the current node to
		 * @param distance Distance of the connection
		 * @return none
		 */
		void connect(int, int);

		/**
		 * @brief Disconnect the current node from a specified node
		 * @param index Index of the specified node to remove the connection from
		 * @return disconnect True if the disconnect was successful, false if the disconnect wasn't successful
		 */
		int disconnect(int);

		/**
		 * @brief Print out information about Node
		 * @return none
		 */
		void print();

	private:
		
		typedef struct {
			int index;
			int distance;
		} Connection; ///< Connection to another node that holds the index that the node is connected to, as well as the distance from the current Node to the specified Node

		std::vector<Connection> connections;
		int id;

};

#endif /* _NODE_H */
