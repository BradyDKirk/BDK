// Copyright (c) 2025 Brady David Kirkpatrick

#ifndef BDK_BASE_H
#define BDK_BASE_H

//
//> Contextualize 'static'
//

#define internal      static
#define global        static
#define local_persist static

//
//> Foreign
//

#include <stdbool.h>
#include <stdint.h>

//
//> Basic Types
//

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
 
typedef i8       b8;
typedef i16      b16;
typedef i32      b32;
typedef i64      b64;

typedef float    f32;
typedef double   f64;

//
//> Units
//

#define KB(n) ((u64)(n) << 10)
#define MB(n) ((u64)(n) << 20)
#define GB(n) ((u64)(n) << 30)
#define TB(n) ((u64)(n) << 40)

//
//> Utilities
//

#ifdef _DEBUG
    // @TODO(Brady): Incomplete!
    #define ASSERT(expression) if (!(expression)) { *(int *)0 = 0; }
#else
    #define ASSERT(expression)
#endif

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#endif // BDK_BASE_H
