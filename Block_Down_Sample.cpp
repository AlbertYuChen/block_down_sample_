/* 
BLOCK_DOWN_SAMPLE.cpp

Author: Albert Yu Chen
Date: Jan 20 2015

NOTE: need to be included in the main function with header file because of the template function.

*/

#include "Block_Down_Sample.hpp"

void Block_Down_Sample::Create_Image(){

	// typedef boost::multi_array<double, 3> array_type;
	// typedef array_type::index index;

	boost::array<array_type::index, D> shape =  {{*M}};//{{M[0], M[1], M[2]}}; //{{5, 4, 6}};
	// array_type A = array_type(boost::extents[0][0][0]);


	A.resize(shape);


	// Assign values to the elements
    int values = 0;
    for(index i = 0; i != 5; ++i) 
    	for(index j = 0; j != 4; ++j)
    		for(index k = 0; k != 6; ++k)
    			for(index l = 0; l != 2; ++l)
    				A[i][j][k][l] = values++;

	// Verify values
	int verify = 0;
	for(index i = 0; i != 5; ++i) 
		for(index j = 0; j != 4; ++j)
			for(index k = 0; k != 6; ++k) 
				for(index l = 0; l != 2; ++l){
					assert(A[i][j][k][l] == verify++);
					// cout << A[i][j][k] << endl;
				}
};


void Block_Down_Sample::test(){

	// typedef boost::multi_array<double, 3> array_type;
	// typedef array_type::index index;
	// boost::array<array_type::index, 3> shape = {{ 3, 4, 2 }};

	// Verify values
	int verify = 0;
	for(index i = 0; i != 5; ++i) 
		for(index j = 0; j != 4; ++j)
			for(index k = 0; k != 6; ++k) 
				for(index l = 0; l != 2; ++l){
					// assert(A[i][j][k] == verify++);
					cout << A[i][j][k][l] << ' ';
				}
};
