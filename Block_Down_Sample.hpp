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

/*
define the data type of the image, since the boost array is not compatable 
with template class, it can't pass template parameters to boost array,
so I have to use the define.
*/ 
#define T int
#define D 4

using namespace std;

class Block_Down_Sample
{
	vector<int> dimension_array;
	typedef boost::multi_array<T, D> array_type;
	typedef array_type::index index;

public:
	std::vector<T> v = {5, 4, 6};
	int M[D] = {5, 4, 6, 2};

	array_type A = array_type(boost::extents[0][0][0][0]);

	Block_Down_Sample(vector<int> dimension_array){
		this->dimension_array = dimension_array;


	};

	void Create_Image();

	void test();


	vector<int> get_dimension_array() {return dimension_array;};

};

#endif





























