#include <iostream>
#include <iomanip>
using namespace std;

double newPopulation(double previous, double birthRate, double deathRate)
{
    return previous * (1 + birthRate) * (1 - deathRate);
}

int main()
{
    double startingPop, birthRate, deathRate;
    int years;

    cout << "Enter the starting population size (minimum 2): ";
    cin >> startingPop;
    while (startingPop < 2)
    {
        cout << "The starting population must be at least 2. Re-enter: ";
        cin >> startingPop;
    }

    cout << "Enter the annual birth rate (as a decimal): ";
    cin >> birthRate;
    while (birthRate < 0)
    {
        cout << "The birth rate cannot be negative. Re-enter: ";
        cin >> birthRate;
    }

    cout << "Enter the annual death rate (as a decimal): ";
    cin >> deathRate;
    while (deathRate < 0)
    {
        cout << "The death rate cannot be negative. Re-enter: ";
        cin >> deathRate;
    }

    cout << "Enter the number of years to display (minimum 1): ";
    cin >> years;
    while (years < 1)
    {
        cout << "The number of years must be at least 1. Re-enter: ";
        cin >> years;
    }

    cout << fixed << setprecision(0);
    cout << "\nStarting population: " << startingPop << endl;
    cout << "\nYear\tPopulation\n";

    double population = startingPop;
    for (int year = 1; year <= years; year++)
    {
        population = newPopulation(population, birthRate, deathRate);
        cout << setw(4) << year << "\t" << setw(10) << population << endl;
    }

    return 0;
}