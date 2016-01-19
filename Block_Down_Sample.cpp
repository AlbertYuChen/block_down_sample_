/* 
BLOCK_DOWN_SAMPLE.cpp
Author: Albert Yu Chen
Date: Jan 20 2015
*/

#include "Block_Down_Sample.hpp"

template <class T, int N>
void Block_Down_Sample<T, N>::test(){


	for(op_index i = 0; i != 3; ++i) 
			for(op_index j = 0; j != 4; ++j)
				for(op_index k = 0; k != 2; ++k) 
					for(op_index l = 0; l != 2; ++l) {
						co_index idx = {{i,j,k,l}};
						cout << A(idx) << ' ';
					}

	typedef typename boost::multi_array<T, N>::index_range b_range;
	typedef typename boost::multi_array<T, N>::array_view<N>::type b_view;
	
	b_view myview =
	A[boost::indices[b_range(1,2)][b_range(1,3)][b_range(0,1)][b_range(0,1)]];

	for (op_index i = 0; i != 1; ++i)
		for (op_index j = 0; j != 2; ++j)
			for (op_index k = 0; k != 2; ++k) 
				for(op_index l = 0; l != 2; ++l) {
						co_index idx = {{i,j,k,l}};
						cout << myview(idx) << ' ';
				}

};












