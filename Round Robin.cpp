#include <iostream>
using namespace std;

int main() {
    int n, quantum;

    // Input: Number of processes and time quantum
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> quantum;

    // Arrays for process data
    int burstTime[n], remainingTime[n], waitingTime[n] = {0}, turnaroundTime[n] = {0};

    // Input burst times
    for (int i = 0; i < n; i++) {
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burstTime[i];
        remainingTime[i] = burstTime[i];
    }

    int currentTime = 0, completed = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Round Robin Scheduling
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] > quantum) {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    currentTime += remainingTime[i];
                    waitingTime[i] = currentTime - burstTime[i];
                    turnaroundTime[i] = currentTime;
                    remainingTime[i] = 0;
                    completed++;
                }
            }
        }
    }

    // Calculate total waiting and turnaround times
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Calculate averages
    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    // Display results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";
    }

    // Display averages
    cout << "\nAverage Waiting Time: " << avgWaitingTime;
    cout << "\nAverage Turnaround Time: " << avgTurnaroundTime << "\n";

    return 0;
}
