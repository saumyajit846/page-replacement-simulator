#include <bits/stdc++.h>
using namespace std;

// Function to print frames
void printFrames(vector<int> &frames) {
    for (int f : frames) {
        if (f == -1) cout << "- ";
        else cout << f << " ";
    }
}

// FIFO Algorithm
void FIFO(vector<int> pages, int capacity) {
    vector<int> frames(capacity, -1);
    queue<int> q;
    int faults = 0;

    cout << "\nStep\tPage\tFrames\t\tFault\n";

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
        bool hit = false;

        for (int f : frames) {
            if (f == page) {
                hit = true;
                break;
            }
        }

        if (!hit) {
            faults++;
            if (q.size() < capacity) {
                frames[q.size()] = page;
                q.push(page);
            } else {
                int old = q.front(); q.pop();

                for (int j = 0; j < capacity; j++) {
                    if (frames[j] == old) {
                        frames[j] = page;
                        break;
                    }
                }
                q.push(page);
            }
        }

        cout << i+1 << "\t" << page << "\t";
        printFrames(frames);
        cout << "\t\t" << (hit ? "No" : "Yes") << "\n";
    }

    cout << "Total Page Faults: " << faults << "\n";
}

// LRU Algorithm
void LRU(vector<int> pages, int capacity) {
    vector<int> frames;
    unordered_map<int, int> lastUsed;
    int faults = 0;

    cout << "\nStep\tPage\tFrames\t\tFault\n";

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
        bool hit = false;

        for (int f : frames) {
            if (f == page) {
                hit = true;
                break;
            }
        }

        if (!hit) {
            faults++;
            if (frames.size() < capacity) {
                frames.push_back(page);
            } else {
                int lru = INT_MAX, val;

                for (int f : frames) {
                    if (lastUsed[f] < lru) {
                        lru = lastUsed[f];
                        val = f;
                    }
                }

                for (int j = 0; j < frames.size(); j++) {
                    if (frames[j] == val) {
                        frames[j] = page;
                        break;
                    }
                }
            }
        }

        lastUsed[page] = i;

        cout << i+1 << "\t" << page << "\t";
        printFrames(frames);
        cout << "\t\t" << (hit ? "No" : "Yes") << "\n";
    }

    cout << "Total Page Faults: " << faults << "\n";
}

// Optimal Algorithm
void Optimal(vector<int> pages, int capacity) {
    vector<int> frames;
    int faults = 0;

    cout << "\nStep\tPage\tFrames\t\tFault\n";

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
        bool hit = false;

        for (int f : frames) {
            if (f == page) {
                hit = true;
                break;
            }
        }

        if (!hit) {
            faults++;
            if (frames.size() < capacity) {
                frames.push_back(page);
            } else {
                int farthest = -1, idx = -1;

                for (int j = 0; j < frames.size(); j++) {
                    int k;
                    for (k = i + 1; k < pages.size(); k++) {
                        if (frames[j] == pages[k]) break;
                    }

                    if (k > farthest) {
                        farthest = k;
                        idx = j;
                    }
                }

                frames[idx] = page;
            }
        }

        cout << i+1 << "\t" << page << "\t";
        printFrames(frames);
        cout << "\t\t" << (hit ? "No" : "Yes") << "\n";
    }

    cout << "Total Page Faults: " << faults << "\n";
}

// MAIN
int main() {
    int n, capacity, choice;

    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> capacity;

    cout << "\nChoose Algorithm:\n";
    cout << "1. FIFO\n2. LRU\n3. Optimal\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: FIFO(pages, capacity); break;
        case 2: LRU(pages, capacity); break;
        case 3: Optimal(pages, capacity); break;
        default: cout << "Invalid choice\n";
    }

    return 0;
}