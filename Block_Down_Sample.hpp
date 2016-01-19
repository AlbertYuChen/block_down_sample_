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
#define T int

using namespace std;

class Block_Down_Sample
{
	int dimension;
	vector<int> dimension_array;

public:
	Block_Down_Sample(vector<int> dimension_array){
		this->dimension_array = dimension_array;
		dimension = dimension_array.size();

	};


	void Create_Image();




	int get_dimension() {return dimension;};
	vector<int> get_dimension_array() {return dimension_array;};
};

#endif





























