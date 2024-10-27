#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h> // For sleep function

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

    // Keep the program running without re-running the test
    while (1) {
        // Optional: Print the message every 10 seconds to show it's still running
        printf("Still running...\n");
        sleep(10); // Sleep for 10 seconds
    }

    return 0;
}
