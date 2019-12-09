/**
 * @file GA.h
 * @author Joe Biwer
 * @date 12/08/2019
 * @brief Class declaration of GA (genetic algorithm)
 */

#ifndef _GA_H
#define _GA_H

#include "Network.h"
#include <vector>

class GA {
	public:
		std::vector<Network *> networks;
		
		int gens, popSize;

		/**
		 * @brief Initializes the GA with the specified generation length and population size
		 * @param _gens Number of generations
		 * @param _popSize Number of chromosomes in the population
		 */
		GA(int, int);

		/**
		 * @brief Calculate the fitness of the specified network
		 * @param network Network to calculate the fitness for
		 * @return The numerical representation of the fitness
		 */
		float calculateFitness(Network *);

		/**
		 * @brief Print the relevant information about the GA to the file
		 * @return none
		 */
		void print();

	private:
		typedef struct {
			float distance;
			int stations;
		} Fitness;

		std::vector<Fitness *> fitnesses;
};

#endif
