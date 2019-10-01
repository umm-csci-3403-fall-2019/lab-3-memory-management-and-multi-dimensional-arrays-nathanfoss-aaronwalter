#include <stdlib.h>

#include "../mergesort/mergesort.h"
#include "array_merge.h"

int array_size(int num_arrays, int* sizes);
void insert_values(int* initial_array, int num_arrays, int* sizes, int** values);
void get_uniques(int* sorted_values, int initial_size);

// This takes a group of unsorted arrays, combines them, and then returns
//  a new array that contains all the unique values, as well
// as the length of the array as the first element.
int* array_merge(int num_arrays, int* sizes, int** values) {

	// Use a helper function to calculate the maximum possible array size
	const int initial_size = array_size(num_arrays, sizes);
	int* combined_values = (int*)calloc(initial_size, sizeof(int));

	// Now combine all the arrays into one.
	insert_values(combined_values, num_arrays, sizes, values);

	// Sort the values.
	mergesortRange(combined_values, 1, initial_size);

	// Now get all the unique values and destructively overwrite the old array. (this is to save memory)
	get_uniques(combined_values, initial_size);
	int* sorted_values = (int*)realloc(combined_values, (combined_values[0]+1)*sizeof(int));

	return sorted_values;
}

// We use this function to determine how much space to initially allocate for our array.
int array_size(int num_arrays, int* sizes) { 
	int array_size = 0;
	for (int i=0; i<num_arrays; i++) {
		array_size = array_size + sizes[i];
	}
	return array_size + 1;
}

// This combines many arrays into one array.
void insert_values(int* initial_array, int num_arrays, int* sizes, int** values) {
	initial_array[0] = 0; //We reserve this space to hold our counter for unique values
	int initial_array_index = 1;
	for (int i = 0; i<num_arrays; i++) { //We go through this loop once for each array we're provided
		int values_length = sizes[i]; //We get the size of the particular array we're considering
		for(int j = 0; j<values_length; j++) { //We iterate over the values in that array
			initial_array[initial_array_index] = values[i][j]; //We place the value in our initial array and increment the index
			initial_array_index = initial_array_index + 1;
		}
	}
}

// This destructively overwrites an array with all its unique values, and the length of the resulting array.
void get_uniques(int* sorted_values, int initial_size) {
	int unique_index = 1;
	for (int i = 1; i < initial_size; i++) { //We start at index 1 to leave space for our count of unique values
		if (sorted_values[i] != sorted_values[i-1] || i == 1) { //If our value is the first value we're considering, or if it's not the same as the previous value...
			sorted_values[unique_index] = sorted_values[i]; //Then we move that value to the appropriate place in our array and increment the count
			unique_index = unique_index + 1; 
		}
	}
	sorted_values[0] = unique_index-1;
}