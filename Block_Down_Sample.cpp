/* 
BLOCK_DOWN_SAMPLE.cpp
Author: Albert Yu Chen
Date: Jan 20 2015
*/

#include "Block_Down_Sample.hpp"


template <class T, int N>
void Block_Down_Sample<T, N>::test(){

	for(op_index i = 0; i != 4; ++i) 
			for(op_index j = 0; j != 4; ++j)
				for(op_index k = 0; k != 2; ++k) 
					for(op_index l = 0; l != 2; ++l) {
						co_index idx = {{i,j,k,l}};
						cout << IN(idx) << ' ';
					}


	b_view myview = 
	IN[ boost::indices[b_range(0,2)][b_range(1,3)][b_range(0,1)][b_range(0,2)] ];

	for (op_index i = 0; i != 1; ++i)
		for (op_index j = 0; j != 2; ++j)
			for (op_index k = 0; k != 1; ++k) 
				for(op_index l = 0; l != 2; ++l) {
						co_index idx = {{i,j,k,l}};
						cout << "="<< myview(idx) << "=";
				}

};












