//////////////////////////////////////////////////////////////////////////////////////////////////
// File Name: Population.cs
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
using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Text;

namespace Tsp
{
    class Population : List<Tour>
    {
        /// <summary>
        /// Private copy of the best tour found so far by the Genetic Algorithm.
        /// </summary>
        private Tour bestTour = null;
        /// <summary>
        /// The best tour found so far by the Genetic Algorithm.
        /// </summary>
        public Tour BestTour
        {
            set
            {
                bestTour = value;
            }
            get
            {
                return bestTour;
            }
        }

        /// <summary>
        /// Create the initial set of random tours.
        /// </summary>
        /// <param name="populationSize">Number of tours to create.</param>
        /// <param name="cityList">The list of cities in this tour.</param>
        /// <param name="rand">Random number generator. We pass around the same random number generator, so that results between runs are consistent.</param>
        public void CreateRandomPopulation(int populationSize, Cities cityList, Random rand, int mutationRate)
        {
            for (int tourCount = 0; tourCount < populationSize; tourCount++)
            {
                //Tour tour = Tour.MakeRandomTour(cityList.Count,rand);
                
                Tour tour = new Tour(cityList.Count);
                if (tourCount<cityList.Count)
                {
                    List<int> notUsedCities = new List<int>();
                    double tourLength = 0;
                    for (int i = 0; i < cityList.Count; i++)
                    {
                        notUsedCities.Add(i);
                    }

                    tour.Add(tourCount);
                    notUsedCities.Remove(tourCount);
                    while (notUsedCities.Count > 0)
                    {
                        int actualNodeNumber = tour[tour.Count - 1];
                        double minLength = Double.MaxValue;
                        int chosenNode = -1;

                        foreach (int nodeNumber in notUsedCities)
                        {
                            double length = cityList[actualNodeNumber].Distances[nodeNumber];
                            if (length < minLength)
                            {
                                minLength = length;
                                chosenNode = nodeNumber;
                            }
                        }

                        tourLength += minLength;
                        tour.Add(chosenNode);
                        notUsedCities.Remove(chosenNode);
                    }
                    tour.DetermineFitness(cityList);
                }
                else
                {
                    tour.AddRange(this[rand.Next(cityList.Count)].ToArray());
                    //tour.AddRange(bestTour.ToArray());
                    Tour.Mutate(tour,cityList,rand,mutationRate);
                    tour.DetermineFitness(cityList);
                }

                tour.DetermineFitness(cityList);
                this.Add(tour);

                if ((bestTour == null) || (tour.Fitness < bestTour.Fitness))
                {
                    BestTour = tour;
                }
            }
        }

        public Tour tournamentSelection(Random rand)
        {
            Tour selectedTour = this[rand.Next(this.Count)];
            for (int i = 0; i < 4; i++)
            {
                Tour temp = this[rand.Next(this.Count)];
                if (temp.Fitness<selectedTour.Fitness)
                {
                    selectedTour = temp;
                }
            }
            return selectedTour;
        }
    }
}
