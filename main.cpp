/* 
Author: Albert Yu Chen
Date: Jan 20 2015
NOTE: sample main function to test the block down sample code.
*/

/*	my block down sample code implementation.*/
#include "Block_Down_Sample.hpp"
#include "Block_Down_Sample.cpp"

using namespace std;

#define  EXAMPLE 4 // <<<<<<======  choose numbers from 1 2 3 4 to run examples

int main() {

#if EXAMPLE == 1

	typedef boost::multi_array<int, 2> array_type;
	typedef array_type::index index;
	boost::array<long int, 2> D = {{4, 8}};
	boost::array<array_type::index, 2> shape = D;
	array_type A(shape);

	std::fill( A.origin(), A.origin() + 32, 2 );

	A[0][0] = 1;
	A[0][1] = 1;
	A[0][2] = 1;
	A[0][3] = 1;
	A[0][4] = 1;
	A[0][5] = 1;
	A[0][6] = 1;
	A[0][7] = 1;

	A[1][0] = 1;
	A[1][2] = 1;
	A[1][4] = 1;
	A[1][6] = 1;

	A[2][0] = 1;
	A[2][1] = 1;

	A[3][0] = 1;

	int B_d = 2;
	Block_Down_Sample<int, 2> B(A, D, B_d);



	B.print_original_img();
	// choose the number of threads you are going to use
	B.cal_masked_img(2);
	B.print_output_img();

#elif EXAMPLE == 2

	typedef boost::multi_array<int, 2> array_type;
	typedef array_type::index index;
	boost::array<long int, 2> D = {{8, 8}};
	boost::array<array_type::index, 2> shape = D;
	array_type A(shape);
	std::fill( A.origin(), A.origin() + 64, 1 );

	A[0][0] = 0;
	A[0][1] = 0;
	A[0][2] = 0;
	A[0][3] = 0;
	A[0][4] = 0;
	A[0][5] = 0;
	A[0][6] = 0;
	A[0][7] = 0;

	A[1][1] = 0;
	A[1][3] = 0;
	A[1][5] = 0;
	A[1][7] = 0;

	A[2][2] = 0;
	A[2][3] = 0;
	A[2][6] = 0;
	A[2][7] = 0;

	A[3][3] = 0;
	A[3][7] = 0;

	A[4][0] = 0;
	A[4][1] = 0;
	A[4][2] = 0;
	A[4][3] = 0;

	A[5][1] = 0;
	A[5][3] = 0;

	A[6][3] = 0;
	A[6][6] = 0;
	A[6][7] = 0;

	A[7][2] = 0;
	A[7][3] = 0;
	A[7][6] = 0;

	// here is the block size, you can select 1, 2, 4, 8
	int B_d = 4; 
	Block_Down_Sample<int, 2> B(A, D, B_d);
	B.print_original_img();
	B.cal_masked_img(3);
	B.print_output_img();

#elif EXAMPLE == 3

	typedef boost::multi_array<double, 2> array_type;
	typedef array_type::index index;
	boost::array<long int, 2> D = {{8, 8}};
	boost::array<array_type::index, 2> shape = D;
	array_type A(shape);
	std::fill( A.origin(), A.origin() + 64, 1.234 );

	A[0][0] = 0;
	A[0][1] = 0;
	A[0][2] = 0;
	A[0][3] = 0;
	A[0][4] = 0;
	A[0][5] = 0;
	A[0][6] = 0;
	A[0][7] = 0;

	A[1][1] = 0;
	A[1][3] = 0;
	A[1][5] = 0;
	A[1][7] = 0;

	A[2][2] = 0;
	A[2][3] = 0;
	A[2][6] = 0;
	A[2][7] = 0;

	A[3][3] = 0;
	A[3][7] = 0;

	A[4][0] = 0;
	A[4][1] = 0;
	A[4][2] = 0;
	A[4][3] = 0;

	A[5][1] = 0;
	A[5][3] = 0;

	A[6][3] = 0;
	A[6][6] = 0;
	A[6][7] = 0;

	A[7][2] = 0;
	A[7][3] = 0;
	A[7][6] = 0;

	// here is the block size, you can select 1, 2, 4, 8
	int B_d = 2; 
	Block_Down_Sample<double, 2> B(A, D, B_d);
	B.print_original_img();
	B.cal_masked_img(3);
	B.print_output_img();

#elif EXAMPLE == 4

	typedef boost::multi_array<int, 6> array_type;
	typedef array_type::index index;
	boost::array<long int, 6> D = {{4, 2, 4, 8, 2, 2}};
	boost::array<array_type::index, 6> shape = D;
	array_type A(shape);
	std::fill( A.origin(), A.origin() + 1024, 0);
	for (auto c = A.origin(); c < A.origin() + 1024; c ++) 
		*c = (int)(rand() % 3);

	// here is the block size, you can select 1, 2, 4, 8
	int B_d = 2; 
	Block_Down_Sample<int, 6> B(A, D, B_d);
	B.print_original_img();
	B.cal_masked_img(16);
	B.print_output_img();

#endif 

	return 0;
}
