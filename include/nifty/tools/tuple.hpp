#pragma once

#include <tuple>

#include "nifty/meta/tuple.hpp"

namespace nifty{
namespace tools{


    ///\cond
    namespace detail_tools{


        template<std::size_t INDEX, std::size_t N>
        struct ForEachImpl{

            template<class TUPLE, class F>
            static void op(TUPLE && tuple, F && f){
                f(std::get<INDEX>(tuple));
                // recurse
                ForEachImpl<INDEX+1, N>::op(std::forward<TUPLE>(tuple), std::forward<F>(f));
            }
        };
        
        // terminate
        template< std::size_t N>
        struct ForEachImpl<N,N>{
            template<class TUPLE, class F>
            static void op(TUPLE && tuple, F && f){
                // terminate
            }
        };

    }
    ///\endcond



    template<class ... ARGS,  class F> 
    void for_each(const std::tuple<ARGS ...> & tuple, F && functor){
        typedef std::tuple<ARGS ...> Tuple;
        detail_tools::ForEachImpl<0, std::tuple_size<Tuple>::value>::op(tuple, std::forward<F>(functor));
    }

}
}