#include <minunit.h>
#include <minirt.h>
#include "tuples/tuple.c"
#include "tuples/point.c"
#include "tuples/vector.c"

int	main()
{
	MU_RUN_SUITE(test_tuples);
	MU_RUN_SUITE(test_point);
	MU_RUN_SUITE(test_vectors);
	MU_REPORT();
	return MU_EXIT_CODE;
}
