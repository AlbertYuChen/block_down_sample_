/* 
Author: Albert Yu Chen
Date: Jan 20 2015

NOTE: sample main function to test the block down sample code.

*/


/*
my block down sample code implementation.
*/

#include "Block_Down_Sample.hpp"
#include "Block_Down_Sample.cpp"

using namespace std;

int main() {

	typedef boost::multi_array<int, 4> array_type;
	typedef array_type::index index;
	array_type A(boost::extents[3][4][2][2]);

	// Assign values to the elements
	int values = 0;
	for(index i = 0; i != 3; ++i) 
		for(index j = 0; j != 4; ++j)
			for(index k = 0; k != 2; ++k)
				for(index l = 0; l != 2; ++l) {
					A[i][j][k][l] = values++;
				}

	// // Verify values
	// int verify = 0;
	// for(index i = 0; i != 3; ++i) 
	// 	for(index j = 0; j != 4; ++j)
	// 		for(index k = 0; k != 2; ++k)
	// 			for(index l = 0; l != 2; ++l) {
	// 				assert(A[i][j][k][l] == verify++);
	// 			}

	Block_Down_Sample<int, 4> B(A);
	B.test();

  return 0;
}