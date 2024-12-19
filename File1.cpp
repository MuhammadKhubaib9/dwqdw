#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int burstTime[n], process[n], waitingTime[n], turnaroundTime[n];

    // Input burst times
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        cout << "Enter burst time for process " << process[i] << ": ";
        cin >> burstTime[i];
    }

    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burstTime[i] > burstTime[j]) {
                swap(burstTime[i], burstTime[j]);
                swap(process[i], process[j]);
            }
        }
    }

    // Calculate waiting time and turnaround time
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }

    // Print results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << process[i] << "\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";
    }

    return 0;
}

