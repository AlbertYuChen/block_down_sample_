/* 
BLOCK_DOWN_SAMPLE.hpp
Author: Albert Yu Chen
Date: Jan 20 2015
NOTE: 
*/

#ifndef BLOCK_DOWN_SAMPLE_H
#define BLOCK_DOWN_SAMPLE_H


/*
the documentation is available through:
http://www.boost.org/doc/libs/master/libs/multi_array/doc/user.html
I download the library from:

*/
#include "boost/multi_array.hpp"

#include <cassert>

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

/*	multi_array is a general purpose container class that models MultiArray.*/
	typedef typename boost::multi_array<T, N> boost_array_type;

/*	The Boost.MultiArray components provide two ways of accessing specific 
	elements within a container. 
	The first uses the traditional C array notation, provided by operator[]. 
	example:
	for(op_index k = 0; k != 2; ++k) 
		for(op_index l = 0; l != 2; ++l) {
			cout << A[k][l] << ' ';
		}*/
	typedef typename boost::multi_array<T, N>::index op_index;

/*	The second method involves passing a Collection of indices to operator(). 
	N indices will be retrieved from the Collection for the N  dimensions of the 
	container.
	This can be useful for writing dimension-independent code, and under some 
	compilers may yield higher performance than operator[]. 
	example:
	co_index idx = {{i,j,k,l}};
	cout << A(idx) << ' '; */
	typedef typename boost::array<op_index,N> co_index;

/*	Boost.MultiArray provides the facilities for creating a sub-view of an 
	already existing array component. It allows you to create a sub-view that 
	retains the same number of dimensions as the original array or one that has 
	less dimensions than the original as well. */
	typedef typename boost::multi_array_types::index_range b_range;

	// typedef typename boost::multi_array<int, N>::array_view<N>::type b_view;
	typedef typename boost::multi_array<int, 4>::array_view<N>::type b_view;


/*	image variable*/
	boost_array_type A;

public:
	
	Block_Down_Sample(boost::multi_array<T, N> input_array) : A(input_array) {};

	void test();

};


#endif





























