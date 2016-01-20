/* 
BLOCK_DOWN_SAMPLE.cpp
Author: Albert Yu Chen
Date: Jan 20 2015
*/

#include "Block_Down_Sample.hpp"

/*	The boost_m_array_t::index_gen and boost::indices only works with fixed 
dimension, but in dimension varying cases, this is not the option, even it can 
make code faster*/
template <class T, int N>
void Block_Down_Sample<T, N>::view_sub_img(){

	co_index img_index;
	for(int i = 0; i < N; i++) 
		img_index[i] = 0;

	int counter[N] = {0};
	for (int i = 0; i < B_size; ++i) {
		cout << img_index[0] << "," << img_index[1]<< " > " << IN(img_index) << "\n";
		img_index[N-1]++;
		for (int j = N - 1; j >= 0; --j) {
			img_index[j] += counter[j];
			counter[j] = 0;
			if (img_index[j] >= B) {
				img_index[j] = 0;
				counter[j - 1] = 1;
			}
		}
	}
};

template <class T, int N>
void Block_Down_Sample<T, N>::print_img(){

	co_index img_index;
	for(int i = 0; i < N; i++)
		img_index[i] = 0;

	/*	the algorithm to walk through every image point is the same as digital 
	counter, which it will always increase the lowest bit, and will yield a 
	counter bit if necessary to higher bit. The lowest bit is img_index[N-1], 
	because the multi_arry treats it as the lowest, so in this way, the scanning 
	would be cache friendly. I noticed this by using 
	std::fill( A.origin(), A.origin() + 16, 2 );
	It will fill the img_index[N-1] bit first and then go to img_index[1], which
	represents the higher bit of boost multi_array*/
	int counter[N] = {0};
	for (int i = 0; i < IN_size; ++i) {
		cout << img_index[0] << "," << img_index[1]<< " : " << IN(img_index) << "\n";
		img_index[N-1]++;
		for (int j = N-1; j >= 0; --j) {
			img_index[j] += counter[j];
			counter[j] = 0;
			if (img_index[j] >= D[j]) {
				img_index[j] = 0;
				counter[j - 1] = 1;
			}
		}
	}
};






