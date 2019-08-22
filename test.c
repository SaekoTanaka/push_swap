#include "push_swap.h"


int main()
{
	t_stack *a;
	t_stack *b;

//	a = stack_init();
	a = stack_init();
    b = stack_init();
//	node_push(a, 2);
//	node_push(a, 3);
//	print_stack(a);
//printf("aaaaaaaaaa\n");
	node_push(a, 3);
	node_push(a, 2);
	node_push(a, 1);
	node_push(a, 0);
	//node_push(a, 4);
	//node_push(a, 5);
    //move_pb(a, b);
    //move_pb(a, b);
	////node_push(b, 4);
	//node_push(b, 5);
	//node_push(b, 6);
    move_rra(a, b);
	print_stack(a);
printf("aaaaaaaaaaaa\n");
	print_stack(b);
printf("bbbbbbb\n");

    move_pb(a, b);
	print_stack(a);
printf("aaaaaaaaaaaa\n");
	print_stack(b);
printf("bbbbbbb\n");

    move_sa(a, b);
	print_stack(a);
printf("aaaaaaaaaaaa\n");
	print_stack(b);
printf("bbbbbbb\n");

    move_rra(a, b);
	print_stack(a);
printf("aaaaaaaaaaaa\n");
	print_stack(b);
printf("bbbbbbb\n");

    move_pa(a, b);
	print_stack(a);
printf("aaaaaaaaaaaa\n");
	print_stack(b);
printf("bbbbbbb\n");


//	move_sa(a, b);
////	print_stack(a);
////printf("aaaaaaaaaa\n");
//	print_stack(a);
//printf("aaaaaaaaaa\n");
//    print_stack(b);
//printf("bbbbbbb\n");
//    move_ra(a, b);
//	print_stack(a);
//printf("aaaaaaaaaa\n");
//    print_stack(b);
//printf("bbbbbbb\n");
	return (0);
}


//int main()
//{
//	int ret;
//	int i;
//	char buff[7];
//
//	i = 0;
//	ret = read(0, buff, 6);
//	buff[ret] = '\0';
//	printf("ret:%d\n", ret);
//	while (i < 6)
//	{
//		printf("i:%d, buff[i]:%d\n",i, buff[i]);
//		i++;
//	}
//	return (0);
//}


//int main()
//{
//	int     ret;
//	char    buff[6];
//	int i = 0;
//
//	while ((ret = read(0, buff, 5)) > 0)
//	{
//		if (ret > 4)
//		{
//			//print_error();
//			break;
//		}
//		printf("i:%d, buff[i]:%d\n",i, buff[i]);
//		i++;
//	}
//	return(0);
//}

