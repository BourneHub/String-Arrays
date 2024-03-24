// Author Name: Iftiar Mullah
// Project name: String Arrays
// UID: 806212501

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Function to check if all strings in the array have no capital letters
bool hasNoCapitals(const string array[], int n) {
	if (n <= 0) {     // If the size of the array is non-positive, return true
		return true;
	}
	for (int i = 0; i < n; i++) { // Iterate through each string in the array
		for (char c : array[i]) { // Iterate through each character in the string
			if (isupper(c)) { // If a character is uppercase, return false
				return false;
			}
		}
	}
	return true; // If no uppercase characters were found, return true
}
// Function to locate the index of the maximum string in the array
int locateMaximum(const string array[], int n) {
	if (n <= 0) {
		return -1;
	}
	int maximumIndex = 0;
	for (int i = 1; i < n; i++) {
		if (array[i] > array[maximumIndex]) { // Compare strings
			maximumIndex = i;
		}
	}
	return maximumIndex; // Return the index of max string
}

// Function to shift elements of the array to the left by a certain amount and replace shifted out elements with a placeholder
int shiftLeft(string array[], int n, int amount, string placeholder) {
	if (n <= 0 || amount < 0) { // If the size of the array is non-positive or the shift amount is negative, return -1
		return -1; 
	}
	int phCount = 0;
	for (int i = 0; i < n; i++) {
		if (i + amount < n) {
			array[i] = array[i + amount]; // Shift elements to the left by 'amount'
		}
		else {
			array[i] = placeholder; // Replace shifted out elements with the placeholder and count how many placeholders are inserted
			phCount++;
		}
	}

	return phCount; // Return the count of placeholders inserted
}
// Function to count the number of floating point values in the array
int countFloatingPointValues(const string array[], int n) {
	if (n <= 0) {
		return -1;
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		bool floatPoint = true;
		bool decimal = false;
		if (array[i].size() == 0) { // Checks if the string is empty
			floatPoint = false;
		}
		else {
			for (char c : array[i]) {
				if (c == '.') { // Checks if the character is a decimal point
					if (decimal) { // Check if a decimal point has already occurred in the string
						floatPoint = false;
						break;
					}
					decimal = true;
				}
				else if (!isdigit(c)) { // Checks if the character is a digit
					floatPoint = false;
					break;
				}
			}
		}
		if (floatPoint) { // If the string represents a valid floating-point number, increment num
			num++;
		}
	}
	return num; // Return the number of floating point values
}

int main() {

}