#define BDK_NO_PREFIX
#define BDK_IMPLEMENTATION
#include <bdk/bdk.h>

int main(void)
{
    {
        u32 a = 10;
        u32 b = 12;
        
        assert(a != b);
        
        (void)a;
        (void)b;
    }

    {
        i32 arr[] = { 1, 2, 3, 4, 5 };
        u32 arr_count = array_count(arr);
        
        assert(arr_count == 5);
        
        (void)arr_count;
    }
    
    {
        Arena *arena = arena_init((void *)0, KB(32));
        (void)arena;
    }
    
    return 0;
}
