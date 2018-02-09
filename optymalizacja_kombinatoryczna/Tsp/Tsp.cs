//////////////////////////////////////////////////////////////////////////////////////////////////
// File Name: Tsp.cs
//      Date: 06/01/2006
// Copyright (c) 2006 Michael LaLena. All rights reserved.  (www.lalena.com)
// Permission to use, copy, modify, and distribute this Program and its documentation,
//  if any, for any purpose and without fee is hereby granted, provided that:
//   (i) you not charge any fee for the Program, and the Program not be incorporated
//       by you in any software or code for which compensation is expected or received;
//   (ii) the copyright notice listed above appears in all copies;
//   (iii) both the copyright notice and this Agreement appear in all supporting documentation; and
//   (iv) the name of Michael LaLena or lalena.com not be used in advertising or publicity
//          pertaining to distribution of the Program without specific, written prior permission. 
///////////////////////////////////////////////////////////////////////////////////////////////////
using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Text;
using System.Data;
using System.Drawing;

namespace Tsp
{
    /// <summary>
    /// This class performs the Travelling Salesman Problem algorithm.
    /// </summary>
    class Tsp
    {
        /// <summary>
        /// Delegate used to raise an event when a new best tour is found.
        /// </summary>
        /// <param name="sender">Object that generated this event.</param>
        /// <param name="e">Event arguments. Contains information about the best tour.</param>
        public delegate void NewBestTourEventHandler(Object sender, TspEventArgs e);

        /// <summary>
        /// Event fired when a new best tour is found.
        /// </summary>
        public event NewBestTourEventHandler foundNewBestTour;

        /// <summary>
        /// Random number generator object.
        /// We allow the GUI to set the seed for the random number generator to assist in debugging.
        /// This allows errors to be easily reproduced.
        /// </summary>
        Random rand;

        /// <summary>
        /// The list of cities. This is only used to calculate the distances between the cities.
        /// </summary>
        Cities cityList;

        /// <summary>
        /// The complete list of all the tours.
        /// </summary>
        Population population;

        /// <summary>
        /// Private copy of a flag that will stop the TSP from calculating any more generations.
        /// </summary>
        private bool halt = false;
        /// <summary>
        /// The GUI sets this flag to true to stop the TSP algorithm and allow the Begin() function to return.
        /// </summary>
        public bool Halt
        {
            get
            {
                return halt;
            }
            set
            {
                halt = value;
            }
        }

        /// <summary>
        /// Default Constructor
        /// </summary>
        public Tsp()
        {
        }

        /// <summary>
        /// Starts the TSP algorithm.
        /// To stop before all generations are calculated, set <see cref="Halt"/> to true.
        /// </summary>
        /// <param name="populationSize">Number of random tours to create before starting the algorithm.</param>
        /// <param name="maxGenerations">Number of times to perform the crossover operation before stopping.</param>
        /// <param name="mutationRate">Odds that a child tour will be mutated..</param>
        /// <param name="cityList">List of cities in the tour.</param>
        public void Begin(int populationSize, int maxGenerations, int mutationRate, Cities cityList)
        {
            rand = new Random();

            this.cityList = cityList;

            population = new Population();
            population.CreateRandomPopulation(populationSize, cityList, rand, mutationRate);

            displayTour(population.BestTour, 0, false);

            bool foundNewBestTour = false;
            int generation;
            for (generation = 0; generation < maxGenerations; generation++)
            {
                if (Halt)
                {
                    break;  // GUI has requested we exit.
                }
                foundNewBestTour = makeChildren(mutationRate);

                if (foundNewBestTour)
                {
                    displayTour(population.BestTour, generation, false);
                }
            }

            displayTour(population.BestTour, generation, true);
        }

        /// <summary>
        /// Randomly select a group of tours from the population. 
        /// The top 2 are chosen as the parent tours.
        /// Crossover is performed on these 2 tours.
        /// The childred tours from this process replace the worst 2 tours in the group.
        /// </summary>
        /// <param name="mutation">Odds that a child will be mutated.</param>
        bool makeChildren(int mutationRate)
        {
            bool foundNewBestTour = false;
            Population newPopulation = new Population();
            newPopulation.Add(population.BestTour);
            newPopulation.BestTour = population.BestTour;
            for (int i = 0; i < population.Count-1; i++)
            {
                Tour parent1 = population.tournamentSelection(rand);
                Tour parent2 = population.tournamentSelection(rand);
                Tour newTour = Tour.Crossover(parent1, parent2, cityList, rand);
                Tour.Mutate(newTour,cityList,rand,mutationRate);
                newPopulation.Add(newTour);
                if (newTour.Fitness < newPopulation.BestTour.Fitness)
                {
                    newPopulation.BestTour = newTour;
                }
            }
            if (newPopulation.BestTour.Fitness < population.BestTour.Fitness)
            {
                foundNewBestTour = true;
            }
            population = newPopulation;
            return foundNewBestTour;
        }

        /// <summary>
        /// Raise an event to the GUI listener to display a tour.
        /// </summary>
        /// <param name="bestTour">The best tour the algorithm has found so far.</param>
        /// <param name="generationNumber">How many generations have been performed.</param>
        /// <param name="complete">Is the TSP algorithm complete.</param>
        void displayTour(Tour bestTour, int generationNumber, bool complete)
        {
            if (foundNewBestTour != null)
            {
                this.foundNewBestTour(this, new TspEventArgs(cityList, bestTour, generationNumber, complete));
            }
        }
    }
}
