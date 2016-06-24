#include <stdlib.h>
#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Tarek S. Hafez";

void scope_demo(int count)
{
    log_info("count is: %d", count);

    if (count > 10) {
        int numbers = 100;

        log_info("count in this scope is %d", numbers);
    }

    log_info("count after exit is: %d", count);

    count = 3000;

    log_info("count after assignment: %d", count);
}

int main(int argc, char *argv[])
{
    struct State *state = malloc(sizeof(struct State));

    set_age(state, 27);

    log_info("My name: %s, age: %d", MY_NAME, get_age(state));

    set_age(state, 100);

    log_info("My age is now: %d", get_age(state));

    set_size(state, 1000);
    
    log_info("Size is: %d", get_size(state));
    print_size(state);

    set_size(state, 9);

    log_info("Size is now: %d", get_size(state));
    print_size(state);

    // test the ratio function static
    log_info("Ratio at first: %f", update_ratio(2.0));
    log_info("Ratio again: %f", update_ratio(10.0));
    log_info("Ratio once more: %f", update_ratio(100.0));

    // test the scope demo
    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);

    log_info("count after calling scope_demo: %d", count);

    return 0;
}