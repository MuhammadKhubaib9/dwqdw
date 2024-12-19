#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int burstTime[n], process[n], waitingTime[n], turnaroundTime[n];
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    // Input burst times
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        cout << "Enter burst time for process " << process[i] << ": ";
        cin >> burstTime[i]; }
    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burstTime[i] > burstTime[j]) {
                swap(burstTime[i], burstTime[j]);
                swap(process[i], process[j]);}}}
    // Calculate waiting time and turnaround time
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1]; }
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];}
    // Calculate average times
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;
    // Print results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << process[i] << "\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";}
	// Print average times
    cout << "\nAverage Waiting Time: " << avgWaitingTime;
    cout << "\nAverage Turnaround Time: " << avgTurnaroundTime << "\n";
    return 0;
}
