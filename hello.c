#include <stdio.h>
#include <string.h>
#include <assert.h>

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

    // Infinite loop to keep the program running
    while (1) {
        printf("I'm still running\n");
        // Add a delay if needed (e.g., 1 second):
        // sleep(1); // Adjust the sleep time as required

        // You can add more code here to perform other tasks
    }

    return 0; // This line will never be reached due to the infinite loop
}