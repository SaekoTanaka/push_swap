#include "push_swap.h"

//how to devide the given number 

int    power(int time)
{
    int n;

    n = 1;
    while (time > 0)
    {
        n *= 2;
        time--;
    }
    return (n);
}


int main()
{
    int num; //ac - 1 > 2 * 2 - 1
    int time;
    int tmp;

    num = 35;
    tmp = num;
    while (num > 3
   // && tmp > 4 //?!?!? if wanna get (2,3) or (2,2), just delete it
    )
    {
        time = 0;
        while (power(time) <= num)
            time++;
        tmp = power(time - 2);
        printf("%d, %d\n", tmp,  //stack B (stack B should be power(~~~))
         num - tmp); //stack A (tekito-nahou)
        num -= tmp;
    }
}
