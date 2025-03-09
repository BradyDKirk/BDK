// Copyright (c) 2025 Brady David Kirkpatrick

#ifndef BDK_ARENA_H
#define BDK_ARENA_H

// @TODO(Brady):
//  - Allocation probably should happen on arena creation instead of requiring allocated memory to
//    be passed in; especially for arena chaining but not sure how I want to structure this yet.
//  - Alignment
//  - Chaining arenas
//  - ASan Memory poisoning

#define BDK_ARENA_HEADER_SIZE sizeof(BDK__TYPE(Arena)) // @TODO(Brady): Should this be aligned?

//
//> Types
//

typedef struct BDK__TYPE(Arena) BDK__TYPE(Arena);
struct BDK__TYPE(Arena)
{
    u64 pos;
    u64 capacity;
};

//
//> Functions
//

internal BDK__TYPE(Arena) *BDK__FUNC(arena_init)(void *base, u64 capacity);

internal void *BDK__FUNC(arena_push)(BDK__TYPE(Arena) *arena, u64 size);
internal void *BDK__FUNC(arena_push_zero)(BDK__TYPE(Arena) *arena, u64 size);

#define bdk_push_struct(arena, type)            BDK__FUNC(arena_push)((arena), sizeof(type))
#define bdk_push_struct_zero(arena, type)       BDK__FUNC(arena_push_zero)((arena), sizeof(type))
#define bdk_push_array(arena, type, count)      BDK__FUNC(arena_push)((arena), sizeof(type) * (count))
#define bdk_push_array_zero(arena, type, count) BDK__FUNC(arena_push_zero)((arena), sizeof(type) * (count))
#define bdk_push_size(arena, size)              BDK__FUNC(arena_push)((arena), (size))
#define bdk_push_size_zero(arena, size)         BDK__FUNC(arena_push_zero)((arena), (size))

internal void BDK__FUNC(arena_pop_to)(BDK__TYPE(Arena) *arena, u64 pos);
internal void BDK__FUNC(arena_pop)(BDK__TYPE(Arena) *arena, u64 size);
internal void BDK__FUNC(arena_clear)(BDK__TYPE(Arena) *arena);

#endif // BDK_ARENA_H
