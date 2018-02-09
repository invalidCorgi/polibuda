//////////////////////////////////////////////////////////////////////////////////////////////////
// File Name: Cities.cs
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
using System.Text;
using System.Data;
using System.IO;
using System.Globalization;

namespace Tsp
{
    /// <summary>
    /// This class contains the list of cities for this test.
    /// Each city has a location and the distance information to every other city.
    /// </summary>
    public class Cities : List<City>
    {
        /// <summary>
        /// Determine the distances between each city.
        /// </summary>
        public void CalculateCityDistances()
        {
            foreach (City city in this)
            {
                city.Distances.Clear();

                for (int i = 0; i < this.Count; i++)
                {
                    city.Distances.Add(Math.Sqrt(Math.Pow(city.Location.X - this[i].Location.X, 2) +
                                       Math.Pow(city.Location.Y - this[i].Location.Y, 2)));
                }
            }
        }

        /// <summary>
        /// Open the txt file that contains the list of cities.
        /// </summary>
        /// <param name="fileName">Name of the txt file.</param>
        public void OpenCityList(string fileName)
        {
            this.Clear();
            using (StreamReader fileWithInstanceReader = new StreamReader(fileName))
            {
                try
                {
                    int numberOfCities = int.Parse(fileWithInstanceReader.ReadLine());

                    for (int i = 0; i < numberOfCities; i++)
                    {
                        string temp = fileWithInstanceReader.ReadLine();
                        this.Add(new City(int.Parse(temp.Split(' ')[1]), int.Parse(temp.Split(' ')[2])));
                    }
                }
                finally
                {
                    fileWithInstanceReader.Close();
                }
            }
        }

        public int FindAppropiateGuiRatio()
        {
            int x = Int32.MinValue;
            int y = Int32.MinValue;
            int ratio = 1;
            for (int i = 0; i < this.Count; i++)
            {
                if (this[i].Location.X > x)
                {
                    x = this[i].Location.X;
                }
                if (this[i].Location.Y > y)
                {
                    y = this[i].Location.Y;
                }
            }
            int xyMax = x > y ? x : y;
            ratio = xyMax / 500;
            if (xyMax % 500 != 0)
            {
                ratio++;
            }
            return ratio;
        }
    }
}
