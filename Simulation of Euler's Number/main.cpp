// found a way on reddit of simulating euler's number 
// its done by generating a random number from 0 to 1 and adding them until its greater than 1
// averaging the number of tries taken to make it greater than 1 simulates euler's number
// it gets better with the number of simulations

#include <iostream>
#include <cmath>

// found a way on stack overflow to approximate euler's number by just doing this
const double e = std::exp(1.0);

// number of iterations, higher is more accurate but takes longer
const int maxSimulations = 30000;

int main()
{
	// sum to be averaged out
	int sum = 0;

	for (int i = 0; i < maxSimulations; i++)
	{
		// variables used for logic
		int tries = 0;
		double localSum = 0;

		// loop for the amount of tries it takes to get over 1
		while (localSum < 1.0)
		{
			// found this way of generating a number from 0 to 1 on stackoverflow
			localSum += (double)rand() / RAND_MAX;
			tries++;
		}

		// adding the total number of attempts at the end of the loop
		sum += tries;
	}

	// results
	double simulatedEulersNumber = (double)sum / (double)maxSimulations;
	double percentOff = (simulatedEulersNumber / e) - 1.0;

	// print results
	std::cout << "Euler's Number: " << e << "\nSimulated Number: " << simulatedEulersNumber << "\nPercent Difference: " << percentOff << "%\nIterations: " << maxSimulations << "\n";

	// evil but i dont know another way to stop the console without a breakpoint
	system("pause");

	return 0;
}