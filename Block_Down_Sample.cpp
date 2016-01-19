/* 
BLOCK_DOWN_SAMPLE.cpp

Author: Albert Yu Chen
Date: Jan 20 2015

NOTE: need to be included in the main function with header file because of the template function.

*/

#include "Block_Down_Sample.hpp"


void Block_Down_Sample::Create_Image(){
	// Create a 3D array that is 3 x 4 x 2
	// typedef boost::multi_array<int, 3> array_type;
	// boost::array<array_type::index, 3> shape = {{ 3, 4, 2 }};
	// array_type A(shape);

	// // Assign values to the elements
	// int values = 0;
	// for(index i = 0; i != 3; ++i) 
	// 	for(index j = 0; j != 4; ++j)
	// 		for(index k = 0; k != 2; ++k)
	// 	    	A[i][j][k] = values++;


    typedef boost::multi_array<double, 3> array_type;
    typedef array_type::index index;
    array_type A(boost::extents[3][4][2]);

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



