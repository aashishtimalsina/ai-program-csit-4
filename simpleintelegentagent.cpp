#include <stdio.h>

// Define constants to represent the two possible states of a square in the environment
#define DIRTY 0
#define CLEAN 1

// Define the function that the agent uses to determine its action based on the current state of the environment
int decideAction(int locationState) {
    if (locationState == DIRTY) {
        return 1; // Clean the current square
    } else {
        return 0; // Move to the other square
    }
}

int main() {
    // Define variables to represent the state of the two squares in the environment
    int location1 = DIRTY;
    int location2 = CLEAN;
    
    // Define a variable to keep track of the current location of the agent
    int currentLocation = 2;
    
    // Loop until both squares are clean
    while (location1 == DIRTY || location2 == DIRTY) {
        // Determine the action the agent should take based on the current state of the environment
        int action = decideAction(currentLocation == 1 ? location1 : location2);
        
        // Perform the action
        if (action == 1) {
            printf("Cleaning location %d\n", currentLocation);
            if (currentLocation == 1) {
                location1 = CLEAN;
            } else {
                location2 = CLEAN;
            }
        } else {
            printf("Moving to location %d\n", currentLocation == 1 ? 2 : 1);
            currentLocation = currentLocation == 1 ? 2 : 1;
        }
    }
    
    printf("Both locations are clean\n");
    
    return 0;
}
