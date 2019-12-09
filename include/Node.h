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

	private:
		
		typedef struct {
			int index;
			float distance;
		} Connection; ///< Connection to another node that holds the index that the node is connected to, as well as the distance from the current Node to the specified Node

		int id;

	public:

		typedef struct {
			int x, y;
		} Position; ///< Position of a Node in 2D space

		Position pos;
		std::vector<Node::Connection> connections;
		bool station;

		/**
		 * @brief Constructor that initializes the node
		 * @param id Unique identifier for the Node
		 * @return none
		 */
		Node(int);
	

		/**
		 * @brief Set position of the node
		 * @param pos Position of the node
		 * @return none
		 */
		void set_position(Position);

		/**
		 * @brief Get the position of the node
		 * @return Position of the node
		 */
		Node::Position get_position();

		/**
		 * @brief Make a connection to another Node
		 * @param index Index of the specified node to attach the current node to
		 * @param distance Distance of the connection
		 * @return none
		 */
		void connect(int, Node);

		/**
		 * @brief Disconnect the current node from a specified node
		 * @param index Index of the specified node to remove the connection from
		 * @return disconnect True if the disconnect was successful, false if the disconnect wasn't successful
		 */
		int disconnect(int);

		/**
		 * @brief Set node as a station
		 * @return none
		 */
		void set_station();

		/**
		 * @brief Returns a bool dependent on whether or not the node is a station
		 * @return Returns true if the node is a station, false otherwise
		 */
		bool is_station();

		/**
		 * @brief Print out information about Node
		 * @return none
		 */
		void print();

};

#endif /* _NODE_H */
