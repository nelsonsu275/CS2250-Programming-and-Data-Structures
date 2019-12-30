#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cmath>

using namespace std;

void selectionSort(int solutions[], int size); // function for sorting array
int distanceToClosest(const int solutions[], int SIZE, int guess); // function for finding distance to closest number from array

int main() {
	srand(time(0)); // random seed using current time

	const int SIZE = 5; // declared constant size for array
	int solutions[SIZE], guess = 0, newDistance = 0, oldDistance = 0; // initialized array, guess variable, distance variables
	bool correct = false, check = false; // booleans for loop control

	for (int i = 0; i < SIZE; i++) { // for loop generating a random number from 1 to 1000 for each element of array
		solutions[i] = 1 + rand() % 1000;
	}

	selectionSort(solutions, SIZE); // function used to sort generated array in ascending order using selection sort

	/*for (int i = 0; i < SIZE; i++) // block comment of array answers for debugging purposes
	{
		cout << solutions[i] << endl;
	}*/

	cout << "Hello! Please try and guess one of my numbers between 1 and 1000." << endl; // asks user for input
	cin >> guess;

	for (int i = 0; i < SIZE; i++) { // checks if guess was correct
		if (solutions[i] == guess) {
			cout << "Correct! " << guess << " was my number! " << endl;
			correct = true;
		}
	}

	while (!correct) { // continues with while loop if guess was incorrect
		cout << "I am sorry. That is incorrect! Try again: " << endl;

		oldDistance = distanceToClosest(solutions, SIZE, guess); // uses function to find initial distance to closest random number and placed into variable

		while (!correct) {
			cin >> guess;  //second guess
			check = false; // boolean changed back to false after first loop to check new guess for distance

			for (int i = 0; i < SIZE; i++) { // compares each element of array to guess to see if it was correct
				if (solutions[i] == guess) {
					cout << "Correct! " << guess << " was my number! " << endl;
					correct = true; // boolean to stop loop after correct answer
					check = true; // boolean to disable next while loop after correct answer
				}
			}

			while (!check) // loop for finding distance
			{
				newDistance = distanceToClosest(solutions, SIZE, guess); // finds distance to closest number again and placed into new variable

				if (newDistance < oldDistance) { // compares distances to see if guess is closer to a nearest random number				
					cout << "Getting warmer!" << endl;
					oldDistance = newDistance; // new distance is updated
				} else if (newDistance > oldDistance) { // compares distances to see if guess is farther from nearest random number		
					cout << "Getting colder!" << endl;
					oldDistance = newDistance; // new distance is updated
				} else if (newDistance == oldDistance) { // displays message if distance is same from opposite direction
					cout << "Same distance apart! Try again: " << endl;
				}
				check = true; // boolean changed to true to stop checking for distance
			}
		}
	}

	cout << "Thank you for playing the random numbers array guessing game!" << endl;

	system("pause");

	return 0;
}

void selectionSort(int solutions[], int SIZE) { // selection sort function
	int minIndex, minValue;

	for (int i = 0; i < (SIZE - 1); i++) {
		minIndex = i;
		minValue = solutions[i];
		for (int index = i + 1; index < SIZE; index++) {
			if (solutions[index] < minValue) {
				minValue = solutions[index];
				minIndex = index;
			}
		}
		swap(solutions[minIndex], solutions[i]);
	}
}

int distanceToClosest(const int solutions[], int SIZE, int guess) {

	int distance = 1000; // initialized distance at largest possible distance from a guess and random number

	for (int i = 0; i < SIZE; i++) {// takes smallest absolute difference from the guess and array elements
		if (abs(guess - solutions[i]) < distance) {
			distance = abs(guess - solutions[i]);
		}
	}

	return distance; // distance is returned to body for comparing
}
