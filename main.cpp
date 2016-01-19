/* 
Author: Albert Yu Chen
Date: Jan 20 2015

NOTE: sample main function to test the block down sample code.

*/


/*
my block down sample code implementation.
*/

#include "Block_Down_Sample.hpp"

using namespace std;

int main () {

    vector<int> L= {3,2,4};
    Block_Down_Sample B(L);
    B.Create_Image();


    for (auto c : B.get_dimension_array())
        std::cout << c<< endl;
    cout << B.get_dimension() << endl;

    return 0;
}