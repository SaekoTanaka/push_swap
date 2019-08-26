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

void    sort_a(int a, int sort_a)
{
    printf("a:%d\n", a);
    printf("sort:%d\n", sort_a);
}

void    sort_b(int b, int sort_b)
{
    printf("b:%d\n", b);
    printf("sort:%d\n", sort_b);
}

//void    move(int *a, int *sort_a, int *b, int *sort_b)
//{
//    *a +=
//}

//int main()
//{
//    int num; //ac - 1 > 2 * 2 - 1
//    int time;
//    int tmp;
//    int a;
//    int b;
//    int sort_a;
//    int sort_b;
//
//    num = 500;
//    tmp = num;
//    a = num;
//    b = 0;
//
//    while (a > 4
//   // && tmp > 4 //?!?!? if wanna get (2,3) or (2,2), just delete it
//    )
//    {
//        time = 0;
//        while (power(time) <= a)
//            time++;
//        tmp = power(time - 2);
//        //printf("%d, %d\n", tmp,  //stack B (stack B should be power(~~~))
//        // num - tmp); //stack A (tekito-nahou)
//        a -= tmp;
//        b = tmp;
//        printf("a:%d, b:%d\n", a, b);
//    }
//    /////sort_a = a;
//    /////sort_b = 2;
//    /////sort_a(a, sort_a);
//    /////sort_b(b, sort_b);
//    /////move(&a, &sort_a, &b, &sort_b);
//   // check_4(num);
//
//    //first a_to_b done
//}

//int main()
//{
//    int num; //ac - 1 > 2 * 2 - 1
//    int time;
//    int tmp;
//    int a;
//    int b;
//
//    num = 35;
//    tmp = num;
//    a = num;
//    b = 0;
//
//    while (num > 3
//   // && tmp > 4 //?!?!? if wanna get (2,3) or (2,2), just delete it
//    )
//    {
//        time = 0;
//        while (power(time) <= num)
//            time++;
//        tmp = power(time - 2);
//        printf("%d, %d\n", tmp,  //stack B (stack B should be power(~~~))
//         num - tmp); //stack A (tekito-nahou)
//        num -= tmp;
//    }
//}
