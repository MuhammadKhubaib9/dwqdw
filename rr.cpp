#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

void roundRobin(vector<Process> &processes, int timeQuantum) {
    int n = processes.size();
    int currentTime = 0;
    queue<int> readyQueue;
    vector<bool> completed(n, false);

    // Initialize processes
    for (int i = 0; i < n; i++) {
        readyQueue.push(i);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
    }

    // Process the queue
    while (!readyQueue.empty()) {
        int index = readyQueue.front();
        readyQueue.pop();

        if (processes[index].remainingTime > 0) {
            int timeSpent = min(timeQuantum, processes[index].remainingTime);
            currentTime += timeSpent;
            processes[index].remainingTime -= timeSpent;

            // Update waiting time for all other processes in the queue
            for (int i = 0; i < n; i++) {
                if (i != index && !completed[i] && processes[i].remainingTime > 0) {
                    processes[i].waitingTime += timeSpent;
                }
            }

            // If the process is completed, calculate turnaround time
            if (processes[index].remainingTime == 0) {
                completed[index] = true;
                processes[index].turnaroundTime = currentTime;
            } else {
                readyQueue.push(index); // Re-add process to the queue
            }
        }
    }

    // Display results
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t" << processes[i].burstTime << "\t\t"
             << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << "\n";
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    // Calculate and display averages
    cout << "\nAverage Waiting Time: " << totalWaitingTime / n;
    cout << "\nAverage Turnaround Time: " << totalTurnaroundTime / n << "\n";
}

int main() {
    int n, timeQuantum;

    // Input number of processes and time quantum
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    vector<Process> processes(n);

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter burst time for process " << processes[i].id << ": ";
        cin >> processes[i].burstTime;
    }

    // Run Round Robin scheduling
    roundRobin(processes, timeQuantum);

    return 0;
}
