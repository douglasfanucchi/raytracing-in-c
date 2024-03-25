#include <minunit.h>
#include <minirt.h>
#include "tuples/tuple.c"
#include "tuples/point.c"
#include "tuples/vector.c"
#include "tuples/scalar.c"
#include "tuples/magnitude.c"
#include "tuples/normalize.c"
#include "tuples/dot.c"
#include "tuples/cross.c"
#include "tuples/color.c"
#include "matrix/matrix.c"
#include "matrix/determinant.c"
#include "matrix/submatrix.c"
#include "matrix/minor.c"

int	main()
{
	MU_RUN_SUITE(test_tuples);
	MU_RUN_SUITE(test_point);
	MU_RUN_SUITE(test_vectors);
	MU_RUN_SUITE(test_scalar);
	MU_RUN_SUITE(test_magnitude);
	MU_RUN_SUITE(test_normalize);
	MU_RUN_SUITE(test_dot_product);
	MU_RUN_SUITE(test_cross_product);
	MU_RUN_SUITE(test_colors);
	MU_RUN_SUITE(test_matrix);
	MU_RUN_SUITE(test_determinant);
	MU_RUN_SUITE(test_submatrix);
	MU_RUN_SUITE(test_minor);
	MU_REPORT();
	return MU_EXIT_CODE;
}
