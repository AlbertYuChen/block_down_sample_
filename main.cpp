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

    boost::array<long int, 4> D = {{4, 4, 2, 2}};

    boost::array<array_type::index, 4> shape = D;
    array_type A(shape);

	// Assign values to the elements
	int values = 0;
	for(index i = 0; i != 4; ++i) 
		for(index j = 0; j != 4; ++j)
			for(index k = 0; k != 2; ++k)
				for(index l = 0; l != 2; ++l) {
					A[i][j][k][l] = values++;
				}

    boost::array<long int, 4> B_d = {{2, 2, 1, 1}};

	Block_Down_Sample<int, 4> B(A, D, B_d);
	B.test();


	return 0;
}


















