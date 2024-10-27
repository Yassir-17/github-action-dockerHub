#include <stdio.h>
#include <string.h>
#include <assert.h>

// Function to return the "Hello World" message
const char* getHelloMessage() {
    return "He1lo World";
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
    return 0;
}
