#include<stdio.h>
#include"derective.h"
#ifdef x
#undef x
#endif // x
int main()
{
     int i=1;
    {
        i=2;
        {
            i=3;
            printf("%d",i);
        }
        printf("%d",i);
    }
    printf("%d",i);

    if(sizeof(int)>-1)
    {
        printf("\nYEs");
    }
    else
    {
        printf("\nNo");
    }
    return 0;
}
