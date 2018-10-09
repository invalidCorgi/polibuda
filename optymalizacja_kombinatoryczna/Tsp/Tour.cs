//////////////////////////////////////////////////////////////////////////////////////////////////
// File Name: Tour.cs
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
using System.Text;

namespace Tsp
{
    /// <summary>
    /// This class represents one instance of a tour through all the cities.
    /// </summary>
    public class Tour : List<int>
    {
        /// <summary>
        /// Constructor that takes a default capacity.
        /// </summary>
        /// <param name="capacity">Initial size of the tour. Should be the number of cities in the tour.</param>
        public Tour(int capacity)
            : base(capacity)
        {
            //resetTour(capacity);
        }

        /// <summary>
        /// Private copy of this fitness of this tour.
        /// </summary>
        private double fitness;
        /// <summary>
        /// The fitness (total tour length) of this tour.
        /// </summary>
        public double Fitness
        {
            set
            {
                fitness = value;
            }
            get
            {
                return fitness;
            }
        }

        /// <summary>
        /// Creates the tour with the correct number of cities and creates initial connections of all -1.
        /// </summary>
        /// <param name="numberOfCities"></param>
        private void resetTour(int numberOfCities)
        {
            this.Clear();

            for (int i = 0; i < numberOfCities; i++)
            {
                this.Add(i);
            }
        }

        /// <summary>
        /// Determine the fitness (total length) of an individual tour.
        /// </summary>
        /// <param name="cities">The cities in this tour. Used to get the distance between each city.</param>
        public void DetermineFitness(Cities cities)
        {
            Fitness = 0;

            for (int i = 0; i < this.Count - 1; i++)
            {
                Fitness += cities[this[i]].Distances[this[i + 1]];
            }
            Fitness += cities[this[0]].Distances[this[this.Count - 1]];
        }

        /// <summary>
        /// Perform the crossover operation on 2 parent tours to create a new child tour.
        /// This function should be called twice to make the 2 children.
        /// In the second call, the parent parameters should be swapped.
        /// </summary>
        /// <param name="parent1">The first parent tour.</param>
        /// <param name="parent2">The second parent tour.</param>
        /// <param name="cityList">The list of cities in this tour.</param>
        /// <param name="rand">Random number generator. We pass around the same random number generator, so that results between runs are consistent.</param>
        /// <returns>The child tour.</returns>
        public static Tour Crossover(Tour parent1, Tour parent2, Cities cityList, Random rand)
        {
            Tour child = new Tour(parent1.Count);
            int start = rand.Next(parent1.Count);
            int end = rand.Next(parent1.Count);
            if (start > end)
            {
                int tmp = start;
                start = end;
                end = tmp;
            }
            int len = end - start + 1;
            List<int> parent1Subset = parent1.GetRange(start, len);
            int i = 0, index = 0;
            while (index < start)
            {
                if (!parent1Subset.Contains(parent2[i]))
                {
                    child.Add(parent2[i]);
                    index++;
                }
                i++;
            }
            child.AddRange(parent1Subset);
            index += len;
            while (index < parent1.Count)
            {
                if (!parent1Subset.Contains(parent2[i]))
                {
                    child.Add(parent2[i]);
                    index++;
                }
                i++;
            }
            child.DetermineFitness(cityList);
            return child;
        }

        /// <summary>
        /// Randomly change one of the links in this tour.
        /// </summary>
        /// <param name="rand">Random number generator. We pass around the same random number generator, so that results between runs are consistent.</param>
        public static void Mutate(Tour tour, Cities cityList, Random rand, int mutationRate)
        {
            if (rand.Next(101) < mutationRate)
            {
                int a = rand.Next(tour.Count);
                int b = a;
                while (a == b)
                {
                    b = rand.Next(tour.Count);
                }
                int tmp = tour[a];
                tour[a] = tour[b];
                tour[b] = tmp;
                tour.DetermineFitness(cityList);
            }
        }

        public static Tour MakeRandomTour(int tourLength, Random rand)
        {
            Tour tour = new Tour(tourLength);
            for (int i = 0; i < tourLength; i++)
            {
                tour.Add(i);
            }
            while (tourLength > 1)
            {
                tourLength--;
                int k = rand.Next(tourLength + 1);
                int temp = tour[k];
                tour[k] = tour[tourLength];
                tour[tourLength] = temp;
            }
            return tour;
        }
    }
}
