#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Enter the number of astronauts (N): ";
    cin >> N;

    cout << "Enter the value of K: ";
    cin >> K;

    // K cannot be less than 2
    if (K < 2) {
        K = 2;
    }

    // Create an array to store the status of each astronaut
    bool* status_alive = new bool[N + 1];

    // Array to store the elimination order
    int* elimination_order = new int[N];

    // All astronauts are initially alive
    for (int i = 1; i <= N; i++) {
        status_alive[i] = true;
    }

    int eliminated_count = 0;
    int current_index = 1;

    // The elimination process continues until only 1 astronaut remains
    while (eliminated_count < N - 1) {

        int counted_steps = 0;

        // Count K astronauts who are still alive
        while (counted_steps < K) {

            if (status_alive[current_index] == true) {

                // The astronaut is alive, so count them
                counted_steps++;

                // If the count has not reached K,
                // move to the next astronaut
                if (counted_steps < K) {
                    current_index++;

                    // If the index passes astronaut N,
                    // return to astronaut 1
                    if (current_index > N) {
                        current_index = 1;
                    }
                }

            } else {

                // The astronaut has already been eliminated,
                // so do not count them
                current_index++;

                // Return to astronaut 1 if the index passes N
                if (current_index > N) {
                    current_index = 1;
                }
            }
        }

        // Eliminate the astronaut at the current index
        status_alive[current_index] = false;

        eliminated_count++;

        // Store the elimination order
        elimination_order[eliminated_count] = current_index;

        cout << "Eliminated astronaut: "
             << current_index << endl;

        // Change the value of K based on the astronaut's number
        if (current_index % 2 == 0) {
            // If the astronaut's number is even
            K = K + 2;
        } else {
            // If the astronaut's number is odd
            K = K - 1;
        }

        // K cannot be less than 2
        if (K < 2) {
            K = 2;
        }

        // Start the next calculation from the astronaut
        // immediately after the eliminated astronaut
        while (status_alive[current_index] == false) {

            current_index++;

            if (current_index > N) {
                current_index = 1;
            }
        }
    }

    // Find the last astronaut who is still alive
    int last_astronaut = 0;

    for (int i = 1; i <= N; i++) {
        if (status_alive[i] == true) {
            last_astronaut = i;
        }
    }

    // Display the complete elimination order
    cout << endl;
    cout << "Elimination order: ";

    for (int i = 1; i <= N - 1; i++) {
        cout << elimination_order[i];

        if (i < N - 1) {
            cout << " -> ";
        }
    }

    cout << endl;

    // Display the last astronaut
    cout << "Last astronaut: "
         << last_astronaut << endl;

    // Delete the arrays from memory
    delete[] status_alive;
    delete[] elimination_order;

    return 0;
}