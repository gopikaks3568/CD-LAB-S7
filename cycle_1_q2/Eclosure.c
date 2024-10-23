//The program to find the closure (working code)
#include <stdio.h>
#include <string.h>

char result[20][20], copy[20], states[20][20];

void add_state(char a[20], int i) {
    strcpy(result[i], a);
}

void display(int n) {
    int k = 0;
    printf("\n\n\nEpsilon closure of %s = { ", copy);
    while (k < n) {
        printf(" %s", result[k]);
        k++;
    }
    printf(" }\n\n\n");
}

int main() {
    FILE *INPUT;
    INPUT = fopen("input.dat", "r");
    
    if (INPUT == NULL) {
        printf("Error opening file.\n");
        return 1; // Exit if the file cannot be opened
    }

    char state[20];
    int end, i, n, k;
    char state1[20], input[20], state2[20];

    printf("Enter the number of states: ");
    scanf("%d", &n);
    printf("Enter the states:\n");

    for (k = 0; k < n; k++) {
        scanf("%s", states[k]);
    }

    for (k = 0; k < n; k++) {
        i = 0;
        strcpy(state, states[k]);
        strcpy(copy, state);
        add_state(state, i++); // Add the initial state to the result
        while (1) {
            end = fscanf(INPUT, "%s %s %s", state1, input, state2);
            if (end == EOF) {
                break;
            }
            if (strcmp(state, state1) == 0) {
                if (strcmp(input, "e") == 0) {
                    add_state(state2, i++);
                    strcpy(state, state2); // Transition to the new state
                }
            }
        }
        display(i);
        rewind(INPUT); // Reset file pointer to the beginning
    }

    fclose(INPUT); // Close the file before exiting
    return 0;
}

// input.dat
/*
q0 e q1
q1 e q2
q2 a q3
q1 b q4
*/

/*
output 
PS C:\Users\gopik\OneDrive\Desktop\New folder> cd "c:\Users\gopik\OneDrive\Desktop\New folder\" ; if ($?) { gcc closure.c -o closure } ; if ($?) { .\closure }
Enter the number of states: 3
Enter the states:
q0
q1
q3



Epsilon closure of q0 = {  q0 q1 q2 }





Epsilon closure of q1 = {  q1 q2 }





Epsilon closure of q3 = {  q3 }


*/

