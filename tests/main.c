#include <minunit.h>
#include <minirt.h>
#include "tuples/tuple.c"

int	main()
{
	MU_RUN_SUITE(test_tuples);
	MU_REPORT();
	return MU_EXIT_CODE;
}
