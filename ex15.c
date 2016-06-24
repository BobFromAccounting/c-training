#include <stdio.h>

void printArrays(int count, int ages[], char *names[]) {
    // first way using indexing
    for (int i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }
}

void printInReverse(int count, int ages[], char *names[]) {
    // Test reverse filtering init = count - 1 to set initial view to one before the end of the pointer arrays
    // allowing me to iterate through the array backwards starting before the null byte terminator.
    for (int i = (count - 1); i >= 0; i--) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }
}

void printPointers(int count, int *cur_age, char **cur_name) {
    // second way using pointers
    for (int i = 0; i < count; i++) {
        printf("%s is %d years old.\n", 
            *(cur_name + i), *(cur_age + i));
    }
}

void printPointersAsArrays(int count, int *cur_age, char **cur_name) {
    // third way, pointers are just arrays
    for (int i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }
}

void printPointersObfuscation(int count, int *cur_age, char **cur_name, int ages[], char *names[]) {
    // fourth way with pointers in a stupid complex way
    for (cur_name = names, cur_age = ages;
        (cur_age - ages) < count;
        cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }
}

void printMemoryAddresses(int count, int ages[], char *names[]) {
    for (int i = 0; i < count; i++) {
        printf("%s's age lives at %p memory address.\n", names[i], &ages[i]);
    }
}

void printNewLine() {
    printf("---\n");
}

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = { 23, 43, 12, 89, 2 };
    char *names[] =  {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);

    printArrays(count, ages, names);

    printNewLine();

    printInReverse(count, ages, names);

    printNewLine();
    // set up the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    printPointers(count, cur_age, cur_name);

    printNewLine();

    printPointersAsArrays(count, cur_age, cur_name);

    printNewLine();
    
    printPointersObfuscation(count, cur_age, cur_name, ages, names);

    printNewLine();

    printMemoryAddresses(count, ages, names);

    return 0;
}