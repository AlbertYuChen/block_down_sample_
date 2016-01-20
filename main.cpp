/* 
Author: Albert Yu Chen
Date: Jan 20 2015

NOTE: sample main function to test the block down sample code.

*/


/*
my block down sample code implementation.
*/

#include "Block_Down_Sample.hpp"
#include "Block_Down_Sample.cpp"

using namespace std;

#define NN 5

void *worker_thread(void *arg)
{
        printf("This is worker_thread #%ld\n", (long)arg);
        pthread_exit(NULL);
}

int main() {
	// typedef boost::multi_array<int, 4> array_type;
	// typedef array_type::index index;
	// boost::array<long int, 4> D = {{4, 4, 2, 2}};
	// boost::array<array_type::index, 4> shape = D;
	// array_type A(shape);
	// // Assign values to the elements
	// int values = 0;
	// for(index i = 0; i != 4; ++i) 
	//     for(index j = 0; j != 4; ++j)
	//         for(index k = 0; k != 2; ++k)
	//             for(index l = 0; l != 2; ++l) {
	//                 A[i][j][k][l] = values++;
	//             }

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
	B.print_img();
	B.cal_masked_img();

	// pthread_t my_thread[NN];

	// long id;
	// for(id = 1; id <= NN; id++) {
	//         int ret =  pthread_create(&my_thread[id], NULL, &Block_Down_Sample<int, 2>::thread_worker, (void*)id);
	//         if(ret != 0) {
	//                 printf("Error: pthread_create() failed\n");
	//                 exit(EXIT_FAILURE);
	//         }
	// }

	// pthread_exit(NULL);


	return 0;
}




