// #include "boost/multi_array.hpp"
// #include <cassert>
#include <zi/concurrency/concurrency.hpp>
#include <zi/zunit/zunit.hpp>

// void boost_test(){
//     // Create a 3D array that is 3 x 4 x 2
//     typedef boost::multi_array<double, 3> array_type;
//     typedef array_type::index index;
//     array_type A(boost::extents[3][4][2]);

//     // Assign values to the elements
//     int values = 0;
//     for(index i = 0; i != 3; ++i) 
//         for(index j = 0; j != 4; ++j)
//             for(index k = 0; k != 2; ++k)
//                 A[i][j][k] = values++;

//     // Verify values
//     int verify = 0;
//     for(index i = 0; i != 3; ++i) 
//         for(index j = 0; j != 4; ++j)
//             for(index k = 0; k != 2; ++k)
//                 assert(A[i][j][k] == 1 + verify++);

// }




ZiSUITE( ZiLib_Concurrency_Tests );

namespace concurrency_tests {

struct barrier_tester: zi::runnable
{
    barrier_tester( int &v, int count = 1 ):
        v_( v ), b_( count ), m_()
    {
    }

    void run()
    {
        if ( b_.wait() )
        {
            zi::guard g( m_ );
            ++v_;
        }
    }

    int         &v_;
    zi::barrier  b_;
    zi::mutex    m_;
};


} // namespace concurrency_tests

ZiTEST( Test_Barrier )
{
    using concurrency_tests::barrier_tester;

    for ( int i = 1; i < 10; ++i )
    {
        int v = 0;
        zi::shared_ptr< barrier_tester > bt( new barrier_tester( v, i ) );

        for ( int j = 0; j < i * ( i + 1 ); ++j )
        {
            zi::thread th( bt );
            th.start();
        }

        zi::all_threads::join();

        EXPECT_EQ( v, i + 1 );
    }

}
