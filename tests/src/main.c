#include <bdk/base.h>

int main(void)
{
    u32 a = 10;
    u32 b = 12;

    ASSERT(a != b);

    i32 arr[] = { 1, 2, 3, 4, 5 };
    ASSERT(ARRAY_COUNT(arr) == 5);

    return 0;
}
