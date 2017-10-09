#include "doctest.h"

#include <iostream>
#include <string>
#include "nifty/tools/tuple.hpp"

TEST_SUITE_BEGIN("nifty_tools");



TEST_CASE( "test for each" ) {

    // struct FoBar{
    // };

    std::tuple<float,int,std::string> the_tuple(1.0f, 1,"hello");


    nifty::tools::for_each(the_tuple,[](auto && v){
        std::cout<<v<<"\n";
    }); 
}


TEST_SUITE_END();