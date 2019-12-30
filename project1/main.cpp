
#include <iostream>
#include <ctime> // used for seeding random number generator with current time
#include <cmath> // used for operators in if and for loops

using namespace std;

void initialize_array(int [], int); // declared functions for initializing array, shuffling array, and printing array
int * shuffle_array(const int [], int);
void print_array(const int [], int);

int * createOddArray(const int [], int, int &); // declared functions to create odd and even array
int * createEvenArray(const int [], int, int &);

void array_war(int *, int, int *, int); // declared functions for an array war and selection sort array
void sort_array(int *, int);

void initialize_array(int array[], int SIZE) // function initializes the array with a for loop according to the size from user input
{
	for (int i = 0; i < SIZE; i++) // for loop puts ascending whole numbers in array starting from 0, 1, 2, 3, ...
	{
		array[i] = i;
	}
}

int * shuffle_array(const int array[], int SIZE) // function shuffles array from pointer
{
	int * secondArray = new int[SIZE]; // initializes a second array pointer with dynamic allocation

	for (int i = 0; i < SIZE; i++) // for loop to set both arrays equal
	{
		secondArray[i] = array[i];
	}

	for (int i = 0; i < SIZE; i++) // for loop to put elements in random locations
	{
		int r = rand() % SIZE; // generates random whole numbers up to the array's size number

		int x = secondArray[r]; // initializes a variable to place temporary array with random positions
		secondArray[r] = secondArray[i]; // sets temporary array to equal new array
		secondArray[i] = x; // new array with new positions is equal to x
	}
	return secondArray; // returns the shuffled array
}

void print_array(const int array[], int SIZE) // function for printing array
{
	cout << "[ ";
	for (int i = 0; i < SIZE; i++) // for loop to print each element of array according to size
	{
		cout << array[i] << " ";
	}
	cout << "]" << endl;
}

int * createOddArray(const int array[], int SIZE, int &oddSIZE) // function to create an odd array
{
	oddSIZE = 0; // sets odd size to 0

	for (int i = 0; i < SIZE; i++)  // for loop to only take all odd numbers from array with modulus operator
	{
		if (array[i] % 2 == 1) // if remainder equals 1, then number is odd
		{
			oddSIZE++; // increments odd array's size each time an odd number is found
		}
	}

	int * secondArray = new int[oddSIZE]; // initializes a pointer for odd array using odd size found with dynamic allocation
	int x = 0; // sets counter to 0

	for (int i = 0; i < SIZE; i++) // for loop to put odd numbers found into second array
	{
		if (array[i] % 2 == 1) // checks if number divides by 2 with a remainder of 1 for odd numbers
		{
			secondArray[x++] = array[i]; // places the odd number into second array using x variable to have a continuous index counter
		}
	}
	return secondArray; // returns odd array
}

int * createEvenArray(const int array[], int SIZE, int &evenSIZE) // function to create even array
{
	evenSIZE = 0; // sets size for even array to 0

	for (int i = 0; i < SIZE; i++) // for loop to only take even numbers from array
	{
		if (array[i] % 2 == 0) // if remainder equals 0, then number is even
		{
			evenSIZE++; // size is incremented every time an even number is found
		}
	}

	int * secondArray = new int[evenSIZE]; // initializes a pointer for even array using even size from for loop with dynamic allocation
	int x = 0; // sets counter to 0

		for (int i = 0; i < SIZE; i++) // for loop to find even numbers
		{
			if(array[i] % 2 == 0) // checks if elements in array divides evenly by 2
			{
				secondArray[x++] = array[i]; // places even numbers found into second array with x as a counter
			}
		}
	return secondArray; // returns even array
}

void array_war(int * arrayOne, int SIZE1, int * arrayTwo, int SIZE2) // function for doing array war game with two arrays
{
	int SIZE, x = 0, i = 0; // initializes size variable for array, x for counting, and i for array index

	if (SIZE1 > SIZE2) // if statement to set the third array's size to the largest of the two
	{
		SIZE = SIZE1; // size equals first array's size if greater than second array's size
	}
	else
	{
		SIZE = SIZE2; // size equals second array's size if lesser than first array's size
	}

	int thirdArray[SIZE]; // initializes third array using new size

	for (i = 0; i < SIZE1 && i < SIZE2; i++) // for loop to compare same index elements of both arrays and continues until it reaches size
	{
		if (arrayOne[i] > arrayTwo[i]) // if an element of the first array is greater than second array, then element goes into third array
		{
			thirdArray[x++] = arrayOne[i];
		}
		else // if an element of second array is greater than first array, then element goes into third array
		{
			thirdArray[x++] = arrayTwo[i];
		}
	}

	if (i == SIZE1) // when size of both arrays is uneven, this takes the last element of the largest array
	{
		for (;i < SIZE2; i++)
		{
			thirdArray[x++] = arrayTwo[i];
		}
	}
	else
	{
		for (;i < SIZE1; i++)
		{
			thirdArray[x++] = arrayOne[i];
		}
	}

	cout << "ArrayFight winner is: " << endl;
	print_array(thirdArray, SIZE); // prints third array with highest values of each index

	sort_array(thirdArray, SIZE); // calls function for selection sort on third array
	cout << "Sorted ArrayFight winner is: " << endl;
	print_array(thirdArray, SIZE); // prints third array sorted
}

void sort_array(int * array, int SIZE) // function for selection sort
{
	int minIndex, minValue; // initializes variable for minimum index and value

	for (int i = 0; i < (SIZE - 1); i++)
	{
		minIndex = i;
		minValue = array[i];

		for (int index = i + 1; index < SIZE; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[i]);
	}
}

int main()
{
	srand(time(0)); // seeds random number generator using current time
	int SIZE; // initializes size variable for arrays

	cout << "Please enter the size of the array from 1-52: " << endl;
	cin >> SIZE; // asks user input for a size between 1-52

	while (SIZE < 1 || SIZE > 52) // while loop to make sure size is within 1-52
	{
		cout << "The size isn't correct. It must be from 1-52. Please try again: " << endl; // lets user know if size is too large or too small
		cin >> SIZE; // asks user for size input until it meets conditions
	}

	int array[SIZE]; // initializes array variable
	initialize_array(array, SIZE); // calls function to initialize the array

	cout << "Original array is: " << endl;
	print_array(array, SIZE); // prints first array created

	int * shuffle = shuffle_array(array, SIZE); // calls function to shuffle array
	cout << "Shuffled array is: " << endl;
	print_array(shuffle, SIZE); // calls function to print the returned shuffled array

	int oSIZE; // initializes size for odd array
	int * oArray = createOddArray(shuffle, SIZE, oSIZE); // initializes pointer for odd array created by odd array function

	int eSIZE; // initializes size for even array
	int * eArray = createEvenArray(shuffle, SIZE, eSIZE); // initializes pointer for even array created by even array function

	cout << "After call to createOddArray, oddArray is: " << endl;
	print_array(oArray, oSIZE); // prints odd array
	cout << "After call to createEvenArray, evenArray is: " << endl;
	print_array(eArray, eSIZE); // prints even array

	array_war(oArray, oSIZE, eArray, eSIZE); // calls array war function to print third array from array war and sorted version

	system("pause");

	return 0;

}
