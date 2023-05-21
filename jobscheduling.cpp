#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Job {
    int id;
    int deadline;
    int profit;
};

// Function to compare jobs based on their profits
bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

void scheduleJobs(const vector<Job>& jobs) {
    int n = jobs.size();
    vector<int> result(n, -1); // Array to store the scheduled jobs
    vector<bool> slot(n, false); // Array to track available slots

    for (int i = 0; i < n; i++) {
            // Iterate over the sorted jobs and assign them to the schedule
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter job details (id, deadline, profit):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    // Sort the jobs in descending order of profit
    sort(jobs.begin(), jobs.end(), compareJobs);
    scheduleJobs(jobs);

    return 0;
}




