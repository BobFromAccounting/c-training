#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int get_size(struct State *state)
{
    return state->size;
}

void set_size(struct State *state, int size)
{
    state->size = size;
}

int get_age(struct State *state)
{
    return state->age;
}

void set_age(struct State *state, int age)
{
    state->age = age;
}

double update_ratio(double new_ratio)
{
    static double ratio = 1.0;

    double old_ratio = ratio;
    ratio = new_ratio;

    return old_ratio;
}

void print_size(struct State *state)
{
    log_info("I think size is: %d", state->size);
}