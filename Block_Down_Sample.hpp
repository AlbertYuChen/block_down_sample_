/* 
BLOCK_DOWN_SAMPLE.hpp
Author: Albert Yu Chen
Date: Jan 20 2015
NOTE: 
*/

#ifndef BLOCK_DOWN_SAMPLE_H
#define BLOCK_DOWN_SAMPLE_H


/*
the boost multi array documentation is available through:
http://www.boost.org/doc/libs/master/libs/multi_array/doc/user.html
I download the library from:

*/
#include "boost/multi_array.hpp"

#include <cassert>
#include <typeinfo>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
template parameters describes the data type of the image and the dimension of 
the image 
T: data type of the image file
N: dimension of the image */
template <class T, int N>
class Block_Down_Sample
{
private:

	/*	define the type of the dimension array, need to be consistant with the 
	boost default array shape settings, which usually used in the following case.
    boost::array<array_type::index, 4> shape = LL;
    array_type A(shape); */
	typedef typename boost::array<long int, N> dim_array_t;

	/*	the iteration way to access boost array (not multi array)
	example:
	for(dim_iterator_t iter(a.begin()); iter != a.end(); ++iter) {
	    cout << *iter << "\n";
	}*/
	typedef typename boost::array<long int, N>::iterator dim_iterator_t;

	/*	multi_array is a general purpose container class that models MultiArray.*/
	typedef typename boost::multi_array<T, N> boost_m_array_t;

	/*	The Boost.MultiArray components provide two ways of accessing specific 
	elements within a container. 
	The first uses the traditional C array notation, provided by operator[]. 
	example:
	for(op_index k = 0; k != 2; ++k) 
		for(op_index l = 0; l != 2; ++l) {
			cout << A[k][l];
		}*/
	typedef typename boost::multi_array<T, N>::index op_index;

	/*	The second method involves passing a Collection of indices to operator(). 
	N indices will be retrieved from the Collection for the N  dimensions of the 
	container.
	This can be useful for writing dimension-independent code, and under some 
	compilers may yield higher performance than operator[]. 
	example:
	co_index idx = {{i,j,k,l}};
	cout << A(idx); */
	typedef typename boost::array<op_index,N> co_index;

	/*	Boost.MultiArray provides the facilities for creating a sub-view of an 
	already existing array component. It allows you to create a sub-view that 
	retains the same number of dimensions as the original array or one that has 
	less dimensions than the original as well. */
	typedef typename boost::multi_array_types::index_range b_range;

	typedef typename boost::multi_array<T, N>::template array_view<N>::type b_view;

	/*	image variable*/
	boost_m_array_t IN;

	/*	image dimension size list
	boost::array<long int, 2> D = {{4, 8}};
	Here, 4 is index 0, 8 is in index 1, but the right side is the lower bit, and
	the left side is the higher bit*/
	dim_array_t D;

	/*	mask block dimension size list*/
	int B;

	/*	How many pixels in the image*/
	int IN_size;

	/*	How many pixels in the mask block*/
	int B_size;

public:

	/*	this will print the image in a list, with correspond coordinate.*/
	void print_img();

	/*	this will view the sub-img using block*/
	void view_sub_img();

	/*	class constructor*/
	Block_Down_Sample(
		boost_m_array_t img, 
		dim_array_t img_dim, 
		int blk_dim) : 
			IN(img), 			// constructor need img input as boost multiple array
			D(img_dim),			// dimension array
			B(blk_dim) {		// block dimension size

		/*	judge whether each dimension and block size is valid*/
		for(int i = 0; i < N; i++) {
			if (D[i] < B) {
				cout << "block size is not smaller than image size\n"; exit (EXIT_FAILURE);
			} else if (B < 0 || D[i] < 0 || (B & (B - 1)) || (D[i] & (D[i] - 1))) {
				cout << "block size or img size is not power of 2\n"; exit (EXIT_FAILURE);} 
		} 

		IN_size = 1; B_size = 1;
		for(int i = 0; i < N; i++) {
			IN_size *= D[i];
			B_size *= B;
		}
	};

};


#endif





























