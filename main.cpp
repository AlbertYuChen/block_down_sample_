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


	// typedef boost::multi_array<double, 3> array_type;
	// typedef array_type::index index;
	// array_type myarray(boost::extents[3][4][2]);

	// // Assign values to the elements
	// int v = 0;
	// for(index i = 0; i != 3; ++i) 
	// for(index j = 0; j != 4; ++j)
	//   for(index k = 0; k != 2; ++k)
	//     myarray[i][j][k] = v++;


	// typedef boost::multi_array_types::index_range range;
	// array_type::array_view<3>::type myview =
	// myarray[ boost::indices[range(0,2)][range(1,3)][range(0,1)] ];

	// for (array_type::index i = 0; i != 2; ++i)
	// 	for (array_type::index j = 0; j != 2; ++j)
	// 		for (array_type::index k = 0; k != 1; ++k) {
	// 			cout << myview[i][j][k] << ' ';
	// 			// assert(myview[i][j][k] == myarray[i][j+1][k*2]);
	// 		}


	return 0;
}