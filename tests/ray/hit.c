MU_TEST(test_should_return_lowest_intersection) {
    t_list      **intersections = ft_newlist();
    t_sphere    *sphere = new_sphere();
    ft_lstadd_back(
        intersections,
        ft_lstnew(new_intersection(4, sphere))
    );
    ft_lstadd_back(
        intersections,
        ft_lstnew(new_intersection(6, sphere))
    );
    t_intersection *result = hit(intersections);

    mu_assert_double_eq(4, result->t);
}

MU_TEST(test_should_return_lowest_positive_intersection) {
    t_sphere    *sphere = new_sphere();
    t_list      **intersections = ft_newlist();
    ft_lstadd_back(
        intersections,
        ft_lstnew(new_intersection(-1, sphere))
    );
    ft_lstadd_back(
        intersections,
        ft_lstnew(new_intersection(1, sphere))
    );
    t_intersection  *result = hit(intersections);

    mu_assert_double_eq(result->t, 1);
}

MU_TEST(test_should_return_null_when_has_no_positive_intersections) {
    t_sphere    *sphere = new_sphere();
    t_list      **intersections = ft_newlist();
    ft_lstadd_back(
        intersections,
        ft_lstnew(new_intersection(-4, sphere))
    );
    ft_lstadd_back(
        intersections,
        ft_lstnew(new_intersection(-6, sphere))
    );
    t_intersection  *result = hit(intersections);

    mu_assert(
        result == NULL,
        "hit should not return any intersection when all distances are negative"
    );
}

MU_TEST(test_should_return_lowest_intersection_when_unorded_list) {
    t_sphere    *sphere = new_sphere();
    t_list      **intersections = ft_newlist();
    ft_lstadd_back(
        intersections,
        ft_lstnew(new_intersection(-7, sphere))
    );
    ft_lstadd_back(
        intersections,
        ft_lstnew(new_intersection(5, sphere))
    );
    ft_lstadd_back(
        intersections,
        ft_lstnew(new_intersection(-1, sphere))
    );
    ft_lstadd_back(
        intersections,
        ft_lstnew(new_intersection(2, sphere))
    );
    t_intersection  *result = hit(intersections);

    mu_assert_double_eq(2, result->t);
}

MU_TEST_SUITE(test_hit) {
    MU_RUN_TEST(test_should_return_lowest_intersection);
    MU_RUN_TEST(test_should_return_lowest_positive_intersection);
    MU_RUN_TEST(test_should_return_null_when_has_no_positive_intersections);
    MU_RUN_TEST(test_should_return_lowest_intersection_when_unorded_list);
}