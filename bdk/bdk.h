// Copyright (c) 2025 Brady David Kirkpatrick

#ifndef BDK_H
#define BDK_H

//
// This is intended to only be used internally.
//
// Determines whether or not a prefix should be added to type/function names to 
// avoid name collisions. By default a prefix is added. Define 'BDK_NO_PREFIX' to
// turn this off.
//
// NOTE: This is experimental. I would prefer to never have any prefix be used but
// that is because I don't use the C standard library or any other library for that 
// matter so its never an issue. I may or may not keep this and may or may not 
// keep any type of prefix. This is very subject to change and may just opt for
// no prefix at all and assume complete incompatibility with the C standard library.
// We'll see..
//                                                                          ~ Brady
//
#ifdef BDK_NO_PREFIX
    #define BDK__TYPE(name) name
    #define BDK__FUNC(name) name
#else
    #define BDK__TYPE(name) BDK_##name
    #define BDK__FUNC(name) bdk_##name
#endif

//
//> Library Headers
//

#include "base.h"
#include "arena.h"

#endif // BDK_H

//
//> Library Source
//

#ifdef BDK_IMPLEMENTATION
    #include "arena.c"
#endif // BDK_IMPLEMENTATION
