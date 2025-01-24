#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int responseTime;
};

void fcfs(vector<Process>& processes) {
    int currentTime = 0;

    for (auto& process : processes) {
        if (currentTime < process.arrivalTime) {
            currentTime = process.arrivalTime;
        }

        process.responseTime = currentTime - process.arrivalTime;
        process.waitingTime = process.responseTime;
        currentTime += process.burstTime;
        process.turnaroundTime = currentTime - process.arrivalTime;
    }
}

void sjn(vector<Process>& processes) {
    int currentTime = 0;
    vector<bool> completed(processes.size(), false);

    for (size_t completedCount = 0; completedCount < processes.size();) {
        int shortestJobIndex = -1;

        for (size_t i = 0; i < processes.size(); ++i) {
            if (!completed[i] && processes[i].arrivalTime <= currentTime) {
                if (shortestJobIndex == -1 || processes[i].burstTime < processes[shortestJobIndex].burstTime) {
                    shortestJobIndex = i;
                }
            }
        }

        if (shortestJobIndex == -1) {
            currentTime++;
            continue;
        }

        Process& process = processes[shortestJobIndex];
        process.responseTime = currentTime - process.arrivalTime;
        process.waitingTime = process.responseTime;
        currentTime += process.burstTime;
        process.turnaroundTime = currentTime - process.arrivalTime;
        completed[shortestJobIndex] = true;
        completedCount++;
    }
}

// Function to calculate and display average metrics
void calculateAndDisplayMetrics(const vector<Process>& processes, const string& algorithmName) {
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;
    double totalResponseTime = 0;

    for (const auto& process : processes) {
        totalWaitingTime += process.waitingTime;
        totalTurnaroundTime += process.turnaroundTime;
        totalResponseTime += process.responseTime;
    }

    double avgWaitingTime = totalWaitingTime / processes.size();
    double avgTurnaroundTime = totalTurnaroundTime / processes.size();
    double avgResponseTime = totalResponseTime / processes.size();

    cout << "Algorithm: " << algorithmName << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Response Time: " << avgResponseTime << endl << endl;
}

int main() {
    vector<Process> processes = {
        {1, 0, 5, 0, 0, 0},
        {2, 1, 3, 0, 0, 0},
        {3, 2, 2, 0, 0, 0},
        {4, 3, 1, 0, 0, 0}
    };

    // Copy of processes for SJN
    vector<Process> processesForSjn = processes;

    fcfs(processes);
    calculateAndDisplayMetrics(processes, "FCFS");

    sjn(processesForSjn);
    calculateAndDisplayMetrics(processesForSjn, "SJN");

    return 0;
}
