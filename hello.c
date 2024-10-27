#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>  // For sleep()

// Function to return the "Hello World" message
const char* getHelloMessage() {
    return "Hello World";
}

// Function to test that the output is "Hello World"
void testHelloMessage() {
    assert(strcmp(getHelloMessage(), "Hello World") == 0);
    printf("Test passed: getHelloMessage() returns 'Hello World'\n");
}

int main() {
    // Run the test
    testHelloMessage();

    // Print the message
    printf("%s\n", getHelloMessage());

    // Keep the program running
    while (1) {
        sleep(10);  // Sleep to prevent tight loop
    }

    return 0;
}


