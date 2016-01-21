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
        sleep(1);
        printf("This is worker_thread #%ld\n", (long)arg);
        
        pthread_exit(NULL);
}

int main() {

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
	// B.print_original_img();
	B.cal_masked_img();
	// B.print_output_img();


	// pthread_t my_thread[NN];

	// long id;
	// for(id = 1; id <= NN; id++) {
	//         int ret =  pthread_create(&my_thread[id], NULL, &worker_thread, (void*)id);
	//         if(ret != 0) {
	//                 printf("Error: pthread_create() failed\n");
	//                 exit(EXIT_FAILURE);
	//         }
	// }

	// sleep(4);

	return 0;
}




