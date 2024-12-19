#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int burstTime[n], priority[n], process[n], waitingTime[n], turnaroundTime[n];
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Input burst time and priority
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        cout << "Enter burst time for process " << process[i] << ": ";
        cin >> burstTime[i];
        cout << "Enter priority for process " << process[i] << ": ";
        cin >> priority[i];
    }

    // Sort processes by priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] < priority[j]) { // Higher priority first
                swap(priority[i], priority[j]);
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
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Calculate averages
    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    // Print results
    cout << "\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << process[i] << "\t" << burstTime[i] << "\t\t" << priority[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";
    }

    // Print averages
    cout << "\nAverage Waiting Time: " << avgWaitingTime;
    cout << "\nAverage Turnaround Time: " << avgTurnaroundTime << "\n";

    return 0;
}
