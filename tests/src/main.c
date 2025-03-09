#include <bdk/base.h>

int main(void)
{
    {
        u32 a = 10;
        u32 b = 12;
        
        ASSERT(a != b);
        
        (void)a;
        (void)b;
    }

    {
        i32 arr[] = { 1, 2, 3, 4, 5 };
        u32 arr_count = ARRAY_COUNT(arr);
        
        ASSERT(arr_count == 5);
        
        (void)arr_count;
    }

    return 0;
}
