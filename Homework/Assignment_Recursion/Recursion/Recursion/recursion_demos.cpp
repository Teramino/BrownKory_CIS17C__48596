#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>

int sum(int *a, int n)
{
	if (n < 0)
	{
		return 0;
	}
	else
	{
		return a[n] + sum(a, n - 1);
	}
}

double futureValue(double presentValue, double rate, int time)
{
	if (time <= 0)
	{
		return presentValue;
	}
	else
	{
		return futureValue(presentValue * (1 + rate), rate, time - 1);
	}
}

int main(int argc, char *argv[])
{
	// Demo for RECURSIVELY calculating the sum of all
	// elements in an array of integers.
	
	std::cout << "Demo of recursively calculating the sum\n"
		      << "of all integers in a given array\n\n";

	int const SIZE_1 = 5;
	int mArray_1[SIZE_1] = { NULL };
	srand((unsigned int)time(NULL));

	for (int i = 0; i < SIZE_1; i++)
	{
		mArray_1[i] = rand() % 90 + 10;
		std::cout << mArray_1[i] << "\n";
	}

	std::cout << "\nSUM = " << sum(mArray_1, SIZE_1 - 1) << "\n\n";

	int const SIZE_2 = 7;
	int mArray_2[SIZE_2] = { NULL };
	srand((unsigned int)time(NULL));

	for (int i = 0; i < SIZE_2; i++)
	{
		mArray_2[i] = rand() % 90 + 10;
		std::cout << mArray_2[i] << "\n";
	}

	std::cout << "\nSUM = " << sum(mArray_2, SIZE_2 - 1) << "\n\n";

	int const SIZE_3 = 10;
	int mArray_3[SIZE_3] = { NULL };
	srand((unsigned int)time(NULL));

	for (int i = 0; i < SIZE_3; i++)
	{
		mArray_3[i] = rand() % 90 + 10;
		std::cout << mArray_3[i] << "\n";
	}

	std::cout << "\nSUM = " << sum(mArray_3, SIZE_3 - 1) << "\n\n";

	/* ------------------------------------------------------- */
	std::cout << "====================================\n\n";
	/* ------------------------------------------------------- */

	// Demo for RECURSIVELY calculating the future value
	// of savings given a present value, interest rate,
	// and number of years.

	std::cout << "Demo of recursively calculating the future value\n"
		      << "given a present value, interest rate, and period of time\n\n";

	double presentValue = 3000.00;
	double rate = 0.05;
	int time = 12;

	std::cout << std::fixed << std::setprecision(2)
		<< "Present Value = $" << presentValue << "\n"
		<< "Interest Rate = " << rate * 100 << "%\n"
		<< "         Time = " << time << " years\n\n"
		<< "FUTURE VALUE  = " << presentValue << " * ( 1 + " << rate << " ) ^ " << time << "\n\n"
		<< "FUTURE VALUE  = $" << std::showpoint << futureValue(presentValue, rate, time) << "\n\n";
	
	std::cout << "----------\n\n";

	presentValue = 50328.27;
	rate = 0.064;
	time = 22;

	std::cout << std::fixed << std::setprecision(2)
		<< "Present Value = $" << presentValue << "\n"
		<< "Interest Rate = " << rate * 100 << "%\n"
		<< "         Time = " << time << " years\n\n"
		<< "FUTURE VALUE  = " << presentValue << " * ( 1 + " << rate << " ) ^ " << time << "\n\n"
		<< "FUTURE VALUE  = $" << std::showpoint << futureValue(presentValue, rate, time) << "\n\n";

	std::cout << "----------\n\n";

	presentValue = 12300.50;
	rate = 0.0445;
	time = 7;

	std::cout << std::fixed << std::setprecision(2)
		<< "Present Value = $" << presentValue << "\n"
		<< "Interest Rate = " << rate * 100 << "%\n"
		<< "         Time = " << time << " years\n\n"
		<< "FUTURE VALUE  = " << presentValue << " * ( 1 + " << rate << " ) ^ " << time << "\n\n"
		<< "FUTURE VALUE  = $" << std::showpoint << futureValue(presentValue, rate, time) << "\n\n";

	return 0;
}