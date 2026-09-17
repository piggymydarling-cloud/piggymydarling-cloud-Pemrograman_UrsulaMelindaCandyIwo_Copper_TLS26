#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Enter the number of astronauts (N): ";
    cin >> N;

    cout << "Enter the value of K: ";
    cin >> K;


    if (K < 2) {
        K = 2;
    }


    bool* status_alive = new bool[N + 1];

    int* elimination_order = new int[N];

    for (int i = 1; i <= N; i++) {
        status_alive[i] = true;
    }

    int eliminated_count = 0;
    int current_index = 1;


    while (eliminated_count < N - 1) {

        int counted_steps = 0;

  
        while (counted_steps < K) {

            if (status_alive[current_index] == true) {

                counted_steps++;

                if (counted_steps < K) {
                    current_index++;

                    if (current_index > N) {
                        current_index = 1;
                    }
                }

            } else {
                current_index++;

                if (current_index > N) {
                    current_index = 1;
                }
            }
        }


        status_alive[current_index] = false;

        eliminated_count++;

        elimination_order[eliminated_count] = current_index;

        cout << "Eliminated astronaut: "
             << current_index << endl;
       
        if (current_index % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }

        if (K < 2) {
            K = 2;
        }

        while (status_alive[current_index] == false) {

            current_index++;

            if (current_index > N) {
                current_index = 1;
            }
        }
    }

    int last_astronaut = 0;

    for (int i = 1; i <= N; i++) {
        if (status_alive[i] == true) {
            last_astronaut = i;
        }
    }


    cout << endl;
    cout << "Elimination order: ";

    for (int i = 1; i <= N - 1; i++) {
        cout << elimination_order[i];

        if (i < N - 1) {
            cout << " -> ";
        }
    }

    cout << endl;

    cout << "Last astronaut: "
         << last_astronaut << endl;


    delete[] status_alive;
    delete[] elimination_order;

    return 0;
}