using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GreedyTSP
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: GreedyTSP.exe <filename>"); 
                return;
            }

            StreamReader file = new StreamReader(args[0]);
            int numberOfNodes = int.Parse(file.ReadLine());
            int [,] nodes = new int[numberOfNodes,2];
            double globalRouteLength = double.MaxValue;
            List<int> globalRoute = new List<int>();

            for (int i = 0; i < numberOfNodes; i++)
            {
                string temp = file.ReadLine();
                nodes[i, 0] = int.Parse(temp.Split(' ')[1]);
                nodes[i, 1] = int.Parse(temp.Split(' ')[2]);
            }
            file.Close();

            for (int k = 0; k < numberOfNodes; k++)
            {
                List<int> route = new List<int>();
                List<int> notUsedNodes = new List<int>();
                double routeLength = 0;
                for (int i = 0; i < numberOfNodes; i++)
                {
                    notUsedNodes.Add(i);
                }

                int firstNode = k;
                route.Add(firstNode);
                notUsedNodes.Remove(firstNode);
                while (notUsedNodes.Count > 0)
                {
                    int actualNodeNumber = route[route.Count - 1];
                    int actualNodeX = nodes[actualNodeNumber, 0];
                    int actualNodeY = nodes[actualNodeNumber, 1];
                    double minLength = Double.MaxValue;
                    int chosenNode = -1;

                    foreach (int nodeNumber in notUsedNodes)
                    {
                        int x = nodes[nodeNumber, 0];
                        int y = nodes[nodeNumber, 1];
                        double length = Math.Sqrt(Math.Pow(actualNodeX - x, 2) + Math.Pow(actualNodeY - y, 2));
                        if (length < minLength)
                        {
                            minLength = length;
                            chosenNode = nodeNumber;
                        }
                    }

                    routeLength += minLength;
                    route.Add(chosenNode);
                    notUsedNodes.Remove(chosenNode);
                }

                routeLength += Math.Sqrt(Math.Pow(nodes[route[0], 0] - nodes[route[route.Count - 1], 0], 2) +
                                         Math.Pow(nodes[route[0], 1] - nodes[route[route.Count - 1], 1], 2));

                if (routeLength<globalRouteLength)
                {
                    globalRouteLength = routeLength;
                    globalRoute.Clear();
                    for (int i = 0; i < route.Count; i++)
                    {
                        globalRoute.Add(route[i]);
                    }
                }
            }
            Console.WriteLine("Route length: {0}",globalRouteLength);
            Console.WriteLine("Route:");
            for (int i = 0; i < globalRoute.Count; i++)
            {
                Console.Write("{0}->",globalRoute[i]+1);
            }
            Console.Write(globalRoute[0]);

            
            Console.Read();
        }
    }
}
