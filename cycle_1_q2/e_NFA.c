#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STATES 100

// Function to find epsilon closure of a state using DFS
void epsilonClosure(int nfa[MAX_STATES][MAX_STATES], int n, bool closure[], int state) {
    closure[state] = true;
    
    for (int i = 0; i < n; i++) {
        // Check for epsilon transitions
        if (nfa[state][i] == 1 && !closure[i]) {
            epsilonClosure(nfa, n, closure, i);
        }
    }
}

// Function to calculate epsilon closure for all states
void calculateEpsilonClosure(int nfa[MAX_STATES][MAX_STATES], int n) {
    for (int i = 0; i < n; i++) {
        bool closure[MAX_STATES] = {false};
        printf("ε-closure of state %d: { ", i);
        epsilonClosure(nfa, n, closure, i);
        for (int j = 0; j < n; j++) {
            if (closure[j]) {
                printf("%d ", j);
            }
        }
        printf("}\n");
    }
}

int main() {
    int nfa[MAX_STATES][MAX_STATES];
    int n, transitions, from, to;
    
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &n);
    
    // Initialize the NFA transition table to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nfa[i][j] = 0;
        }
    }
    
    printf("Enter the number of epsilon transitions: ");
    scanf("%d", &transitions);
    
    printf("Enter the epsilon transitions (from state to state):\n");
    for (int i = 0; i < transitions; i++) {
        scanf("%d %d", &from, &to);
        nfa[from][to] = 1;
    }
    
    calculateEpsilonClosure(nfa, n);
    
    return 0;
}

