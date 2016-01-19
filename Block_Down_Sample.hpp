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
with template class, so I have to use the define.
*/ 

using namespace std;

template<class T, long unsigned int dimension>
class Block_Down_Sample
{
	vector<int> dimension_array;

	// typedef boost::multi_array<T, dimension> array_type;
	// typedef array_type::index index;
	// boost::array<array_type::index, 3> shape = {{ 3, 4, 2 }};
	// array_type A(shape);


public:

	Block_Down_Sample(vector<int> dimension_array){
		this->dimension_array = dimension_array;
		// dimension = dimension_array.size();


	};

	
	void Create_Image();



	vector<int> get_dimension_array() {return dimension_array;};

};

#endif





























