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

	for(typename boost::multi_array<T, 4>::index i = 0; i != 3; ++i) 
			for(boost::multi_array<int, 4>::index j = 0; j != 4; ++j)
				for(boost::multi_array<int, 4>::index k = 0; k != 2; ++k) 
					for(boost::multi_array<int, 4>::index l = 0; l != 2; ++l) {
						cout << A[i][j][k][l] << ' ';
					}
};
