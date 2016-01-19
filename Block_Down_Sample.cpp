/* 
BLOCK_DOWN_SAMPLE.cpp
Author: Albert Yu Chen
Date: Jan 20 2015
NOTE: need to be included in the main function with header file because of the template function.
*/

#include "Block_Down_Sample.hpp"

template <class T, int N>
void Block_Down_Sample<T, N>::test(){

	// typedef boost::multi_array<T, 4>::index b_index;

	for(b_index i = 0; i != 3; ++i) 
			for(b_index j = 0; j != 4; ++j)
				for(b_index k = 0; k != 2; ++k) 
					for(b_index l = 0; l != 2; ++l) {
						cout << A[i][j][k][l] << ' ';
					}
};
