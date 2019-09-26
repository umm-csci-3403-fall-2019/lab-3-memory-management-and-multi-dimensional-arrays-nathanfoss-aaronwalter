#include "../mergesort/mergesort.h"
#include "array_merge.h"

int array_size(int num_arrays, int* sizes);

int* array_merge(int num_arrays, int* sizes, int** values) {
	const int initial_size = array_size(num_arrays, sizes);
	int* sorted_values = calloc(initial_size, sizeof(int));

	return sizes;
}

int array_size(int num_arrays, int* sizes) { //We use this function to determine how much space to initially allocate for our array.
	int array_size = 0
	for (i=0; i<num_arrays; i++) {
		array_size = array_size + sizes[i];
	}
	return array_size + 1;
}

void insert_values(int* initial_array, int num_arrays, int* sizes, int** values) {
	int initial_array_index = 1;
	for (int i = 0; i<num_arrays; i++) {
		int values_length = sizes[i];
		for(int j=0; i<values_length; j++) {
			
		}
	}
}