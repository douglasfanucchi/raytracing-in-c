#include <minirt.h>

t_intersection *hit(t_list **intersections)
{
    t_list          *node;
    t_intersection  *intersection;
    t_intersection  *lowest;

    node = *intersections;
    lowest = node->content;
    while (node)
    {
        intersection = node->content;
        if (intersection->t < 0) {
            node = node->next;
            continue;
        }
        if (lowest->t < 0 || intersection->t < lowest->t) {
            lowest = intersection;
        }
        node = node->next;
    }
    if (lowest->t < 0)
        return (NULL);
    return (lowest);
}
