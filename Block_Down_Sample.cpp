/* 
BLOCK_DOWN_SAMPLE.cpp

Author: Albert Yu Chen
Date: Jan 20 2015

NOTE: need to be included in the main function with header file because of the template function.

*/

#include "Block_Down_Sample.hpp"

template<class T, long unsigned int dimension>
void Block_Down_Sample<T, dimension>::Create_Image(){

	// typedef boost::multi_array<double, 3> array_type;
	// typedef array_type::index index;
	// boost::array<array_type::index, 3> shape = {{ 3, 4, 2 }};



	A.resize(boost::extents[3][4][2]);


	// Assign values to the elements
    int values = 0;
    for(index i = 0; i != 3; ++i) 
    	for(index j = 0; j != 4; ++j)
    		for(index k = 0; k != 2; ++k)
    			A[i][j][k] = values++;

	// Verify values
	int verify = 0;
	for(index i = 0; i != 3; ++i) 
		for(index j = 0; j != 4; ++j)
			for(index k = 0; k != 2; ++k)
				assert(A[i][j][k] == verify++);
};


template<class T, long unsigned int dimension>
void Block_Down_Sample<T, dimension>::test(){

	// typedef boost::multi_array<double, 3> array_type;
	// typedef array_type::index index;
	// boost::array<array_type::index, 3> shape = {{ 3, 4, 2 }};

	// Verify values
	int verify = 0;
	for(index i = 0; i != 3; ++i) 
		for(index j = 0; j != 4; ++j)
			for(index k = 0; k != 2; ++k)
				assert(A[i][j][k] == verify++);
};
