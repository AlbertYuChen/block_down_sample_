/* 
BLOCK_DOWN_SAMPLE.cpp
Author: Albert Yu Chen
Date: Jan 20 2015
*/

#include "Block_Down_Sample.hpp"

/*	I know introducing boost_m_array_t::index_gen would accelarate the calculation,
but the boost_m_array_t::index_gen and boost::indices only works with fixed 
dimension, but in dimension varying cases, this is not the option, even it can 
make code faster*/
template <class T, int N>
pair<T, int> Block_Down_Sample<T, N>::most_com_from_sub_img(){

	co_index img_index;
	std::fill( img_index.begin(), img_index.end(), 0);

	std::map<T, int> M_counter;

	int counter[N] = {0};
	for (int i = 0; i < B_size; ++i) {
		cout << img_index[0] << "," << img_index[1]<< " > " << IN(img_index) << "\n";
		M_counter[IN(img_index)]++;

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

	for(typename map<T, int>::const_iterator it = M_counter.begin(); it != M_counter.end(); ++it) {
	    std::cout << it->first << " " << it->second << "\n";
	}

	auto x = std::max_element(M_counter.begin(), M_counter.end(),
    [](const pair<T, int> p1, const pair<T, int> p2) {
        return p1.second < p2.second; });
	std::cout << x->first << " " << x->second << "\n";
	
	return {x->first, x->second};
};

/*	this function will print the image in a list, with correspond coordinate.*/
template <class T, int N>
void Block_Down_Sample<T, N>::print_img(){

	co_index img_index;
	std::fill( img_index.begin(), img_index.end(), 0);

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

/*	check whether the input data is valid for calculation*/
template <class T, int N>
void Block_Down_Sample<T, N>::check_initialization(){
	/*	judge whether each dimension and block size is valid*/
	for(int i = 0; i < N; i++) {
		if (D[i] < B) {
			cout << "block size is not smaller than image size\n"; 
			exit (EXIT_FAILURE);
		} else if (B < 0 || D[i] < 0 || (B & (B - 1)) || (D[i] & (D[i] - 1))) {
			cout << "block size or img size is not power of 2\n"; 
			exit (EXIT_FAILURE);} 
	} 

	IN_size = 1; B_size = 1;
	for(int i = 0; i < N; i++) {
		IN_size *= D[i];
		B_size *= B;
	}
};
