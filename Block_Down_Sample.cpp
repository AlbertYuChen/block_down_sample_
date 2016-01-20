/* 
BLOCK_DOWN_SAMPLE.cpp
Author: Albert Yu Chen
Date: Jan 20 2015
*/

#include "Block_Down_Sample.hpp"


template <class T, int N>
void Block_Down_Sample<T, N>::print_img(){

	int A_size = 1;
	co_index img_index;
	for(int i = 0; i < N; i++) {
		A_size *= D[i];
		img_index[i] = 0;
	} 

	/*	the algorithm to walk through every image point is the same as digital counter, 
	which it will always increase the lowest bit, and will yield a counter bit if 
	necessary to higher bit.*/
	int counter[N] = {0};
	for (int i = 0; i < A_size; ++i) {
		cout << img_index[1] << "," << img_index[0]<< ": " << IN(img_index) << "\n";
		img_index[0]++;
		for (int j = 0; j < N; ++j) {
			img_index[j] += counter[j];
			counter[j] = 0;
			if (img_index[j] >= D[j]) {
				img_index[j] = 0;
				counter[j + 1] = 1;
			}
		}
	}
	

	// dim_array_t img_index;
	// for (i = 0; i < count; ++i) {
	// 	cout << IN(idx) << ' ';

	// }
	

	
	// for(op_index i = 0; i != 4; ++i) 
	// 		for(op_index j = 0; j != 4; ++j)
	// 			for(op_index k = 0; k != 2; ++k) 
	// 				for(op_index l = 0; l != 2; ++l) {
	// 					co_index idx = {{i,j,k,l}};
	// 					cout << IN(idx) << ' ';
	// 				}


	// b_view myview = 
	// IN[ boost::indices[b_range(0,2)][b_range(1,3)][b_range(0,1)][b_range(0,2)] ];

	// for (op_index i = 0; i != 1; ++i)
	// 	for (op_index j = 0; j != 2; ++j)
	// 		for (op_index k = 0; k != 1; ++k) 
	// 			for(op_index l = 0; l != 2; ++l) {
	// 					co_index idx = {{i,j,k,l}};
	// 					cout << "="<< myview(idx) << "=";
	// 			}

	// for(op_index i = 0; i != 4; ++i) 
	// 	for(op_index j = 0; j != 8; ++j) {
	// 		co_index idx = {{i,j}};
	// 		cout << IN(idx) << ' ';
	// 	}


	// b_view myview = 
	// IN[ boost::indices[b_range(0,2)][b_range(1,3)][b_range(0,1)][b_range(0,2)] ];

	// for (op_index i = 0; i != 1; ++i)
	// 	for (op_index j = 0; j != 2; ++j)
	// 		for (op_index k = 0; k != 1; ++k) 
	// 			for(op_index l = 0; l != 2; ++l) {
	// 					co_index idx = {{i,j,k,l}};
	// 					cout << "="<< myview(idx) << "=";
	// 			}

};












