#pragma once


#define NIFTY_TOOLS_VERSION_MAJOR 0
#define NIFTY_TOOLS_VERSION_MINOR 3
#define NIFTY_TOOLS_VERSION_PATCH 5

// DETECT 3.6 <= clang < 3.8 for compiler bug workaround.
//  from  https://github.com/QuantStack/xtensor/blob/master/include/xtensor/xtensor_config.hpp
#ifdef __clang__
    #if __clang_major__ == 3 && __clang_minor__ < 8
        #define NIFTY_META_OLD_CLANG
    #endif
#endif

