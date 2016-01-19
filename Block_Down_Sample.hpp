/* 
BLOCK_DOWN_SAMPLE.hpp
Author: Albert Yu Chen
Date: Jan 20 2015
NOTE: 
*/

#ifndef BLOCK_DOWN_SAMPLE_H
#define BLOCK_DOWN_SAMPLE_H

#include "boost/multi_array.hpp"

#include <cassert>

using namespace std;

template <class T, int N>
class Block_Down_Sample
{
private:

	boost::multi_array<T, N> A;
	typedef typename boost::multi_array<T, 4>::index b_index;
	typedef std::vector<T> v;

public:
	
	Block_Down_Sample(boost::multi_array<T, N> input_array) : A(input_array) {};

	void test();

};


#endif





























