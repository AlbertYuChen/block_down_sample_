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
#include <algorithm>
#include <iterator>
#include <map>

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

	/*	original image */
	boost_m_array_t IN;

	/*	output masked image */
	boost_m_array_t OUT;

	/*	image dimension size list
	boost::array<long int, 2> D = {{4, 8}};
	Here, 4 is index 0, 8 is in index 1, but the right side is the lower bit, and
	the left side is the higher bit*/
	dim_array_t D;

	/*	the output image size*/
	dim_array_t d;

	/*	mask block edge length*/
	int B;

	/*	How many pixels in the image*/
	int IN_size;

	/*	How many pixels in the mask block*/
	int OUT_size;

	/*	number of threads will be used in the calculation */
	int M_thread = 2;

	/*	this is the input argument struct designed for pthread_create, the 
	first void * member is used to pass this class, so that other functions
	could be called without declaring static*/
	struct pthread_arg {
		void * call_class;
		co_index entr;
		int t_id;
	};

	/*	check whether the input data is valid for calculation*/
	void check_initialization();

	/*	this will view the sub-img using block, and find the most common value*/
	T most_com_from_sub_img(co_index entr);

	/*	worker functino for each thread*/
	static void * thread_worker(void *arg);

public:

	/*	calculate masked image by block down sampling*/
	void cal_masked_img();

	/*	this function will print the original image in a list.*/
	void print_original_img();

	/*	this function will print the output image in a list.*/
	void print_output_img();

	/*	class constructor*/
	Block_Down_Sample(
		boost_m_array_t img, 
		dim_array_t img_dim, 
		int blk_dim) : 
			IN(img), 			// constructor need img input as boost multiple array
			D(img_dim),			// dimension array
			B(blk_dim) {		// mask block edge length
		check_initialization();
	};

};

#endif
