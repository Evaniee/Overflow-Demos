#include <stdio.h>
#include <string.h>

// NOTE: Compiler optimisations may make demonstrates not properly function
// NOTE: Some unreachable code is reachable. This is due to the exploits

int GetsOverflow();

int main(void) {
    StrcpyOverflow();
    return 0;
}


int GetsOverflow() {

    // Variables
    char username[8];
    int allow = 0;

    // Use gets (UNSAFE) to get the user's username
    printf("Please enter your username: ");
    gets(username);

    // Compare username to the string "Admin". If the result is 0 they are the same. If the same set allow to 1 to give admin access
    if (strcmp(username,"Admin") == 0) {
        allow = 65;
    }

    // Check if allow is 65. This is the safest option with gets but is not safe. The attacker now has to make it exactly 1
    if (allow == 65) {
        printf("Welcome Administrator (\"Safer\")");
    }
    // Check if allow is not 0. A less safe option to use. Assumes that allow being anything else will let the user be an admin
    else if (allow != 0) {
        printf("Welcome Administrator (Non-Safe)");
    }
    // Assumes anything else is just a normal user
    else {
        printf("Welcome User");
    }
}

int StrcpyOverflow() {

    // Variables
    char myString1[] = "Hello";
    char myString2[] = "HelloWorld";
    int myNumber = 123;

    strcpy(myString1, myString2);
    if (myNumber == 123) {
        printf("myNumber has not been changed");
    }
    else {
        printf("myNumber is %i", myNumber);
    }

    return 0;
}