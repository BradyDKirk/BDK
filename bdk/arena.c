// Copyright (c) 2025 Brady David Kirkpatrick

internal BDK__TYPE(Arena) *BDK__FUNC(arena_init)(void *base, u64 capacity)
{
    BDK__TYPE(Arena) *arena = (BDK__TYPE(Arena) *)base;
    arena->pos = BDK_ARENA_HEADER_SIZE;
    arena->capacity = capacity;
    
    return arena;
}

internal void *BDK__FUNC(arena_push)(BDK__TYPE(Arena) *arena, u64 size)
{
    assert(arena->pos + size <= arena->capacity);
    
    void *memory = (u8 *)arena + arena->pos;
    arena->pos += size;
    
    return memory;
}

internal void *BDK__FUNC(arena_push_zero)(BDK__TYPE(Arena) *arena, u64 size)
{
    void *memory = BDK__FUNC(arena_push)(arena, size);
    
    // @TODO(Brady): Performance?
    u8 *byte = (u8 *)memory;
    while (size--)
    {
        *byte++ = 0;
    }
    
    return memory;
}

internal void BDK__FUNC(arena_pop_to)(BDK__TYPE(Arena) *arena, u64 pos)
{
    arena->pos = max(BDK_ARENA_HEADER_SIZE, pos);
}

internal void BDK__FUNC(arena_pop)(BDK__TYPE(Arena) *arena, u64 size)
{
    u64 currentPos = arena->pos;
    u64 newPos = currentPos;
    if (size <= currentPos)
    {
        newPos = currentPos - size;
    }
    BDK__FUNC(arena_pop_to)(arena, newPos);
}

internal void BDK__FUNC(arena_clear)(BDK__TYPE(Arena) *arena)
{
    BDK__FUNC(arena_pop_to)(arena, 0);
}
