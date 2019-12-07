/**
 * @file Network.h
 * @author Joe Biwer
 * @date 12-6-2019
 * @brief Network class declaration
 */

#ifndef _NETWORK_H
#define _NETWORK_H

#include "Graph.h"

class Network {
	public:

		typedef struct {
			int x, y;
		} Dimension; ///< Dimensions of the cell architecture. The number of cells in the network will be x*y

		typedef struct {
			int x, y;
		} Bounds; ///< Boundaries of the network (unitless dimensions)
		
		/**
		 * @brief Create a network with the specified graph
		 * @param _graph Graph that the network is built on top of
		 * @param _dims Dimensions of the cells for the network - defaults to 1-by-1
		 * @param _bounds Bounds of the network - defaults to 100-by-100 (unitless)
		 */
		Network(Graph, Dimension, Bounds);

		/**
		 * @brief Set the dimensions of the cell in the network
		 * @param x X-dimension for the cells
		 * @param y Y-dimension for the cells
		 * @return none
		 */
		void set_dimensions(Dimension);

	private:

		Bounds bounds;
		Dimension dims;
		Graph graph;

};

#endif /* _NETWORK_H */
