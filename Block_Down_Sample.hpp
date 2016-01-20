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

/*	define the type of the dimension array, need to be consistant with the boost
	default array shape settings, which usually used in the following case.
    boost::array<array_type::index, 4> shape = LL;
    array_type A(shape); */
	typedef typename boost::array<long int, N> dim_array_t;

/*	the iteration way to access boost array (not multi array)*/
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

/*	image dimension size list*/
	dim_array_t D_power;
	dim_array_t D;

/*	mask block dimension size list*/
	dim_array_t B_power;
	dim_array_t B;

public:
	
	Block_Down_Sample(
		boost_m_array_t img, 
		dim_array_t img_dim, 
		dim_array_t blk_dim) : 
			IN(img), 
			D_power(img_dim),
			B_power(blk_dim) {
				
		for(int i = 0; i < N; i++) {
			if (D_power[i] < B_power[i]) {
				cout << "block size is not smaller than image size"; exit (EXIT_FAILURE);
			}
			D[i] =  1 << D_power[i]; 
			B[i] =  1 << B_power[i];
			cout << D[i] << ':' << D_power[i] << " \n";
			cout << B[i] << ':' << B_power[i] << " \n";
		} 
	};

	void test();

};


#endif





























