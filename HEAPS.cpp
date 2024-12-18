#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to maintain Max-Heap property after insertion
void heapifyUp(vector<int> &heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] > heap[parent]) {
        swap(heap[index], heap[parent]);
        heapifyUp(heap, parent);
    }
}

// Insert a new player into the Max-Heap
void insertPlayer(vector<int> &heap, int skillLevel) {
    heap.push_back(skillLevel);
    cout << "Player with skill level " << skillLevel << " has joined the tournament!\n";
    heapifyUp(heap, heap.size() - 1);
    cout << "Current Max-Heap (Top players): ";
    for (int val : heap) cout << val << " ";
    cout << endl;
}

// Function to maintain Min-Heap property
void heapifyDown(vector<int> &heap, int index, int size) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(heap, smallest, size);
    }
}

// Convert Max-Heap to Min-Heap
void convertToMinHeap(vector<int> &heap) {
    for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
        heapifyDown(heap, i, heap.size());
    }
    cout << "Converted Max-Heap to Min-Heap (Weakest players first): ";
    for (int val : heap) cout << val << " ";
    cout << endl;
}

// Function to heapify a Max-Heap from an unordered array
void heapifyToMaxHeap(vector<int> &arr) {
    for (int i = (arr.size() / 2) - 1; i >= 0; i--) {
        heapifyDown(arr, i, arr.size());
    }
    cout << "Heapified Max-Heap (Rankings updated): ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> heap;
    int choice, skillLevel;

    cout << "=== E-Sports Tournament Ranking System ===\n";
    while (true) {
        cout << "\n1. Add Player\n2. Show Weakest Players (Convert to Min-Heap)\n";
        cout << "3. Update Rankings from New Players\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter player's skill level (1-100): ";
                cin >> skillLevel;
                insertPlayer(heap, skillLevel);
                break;

            case 2:
                convertToMinHeap(heap);
                break;

            case 3: {
                vector<int> newPlayers;
                int numPlayers;
                cout << "Enter the number of new players: ";
                cin >> numPlayers;
                cout << "Enter the skill levels of the new players:\n";
                for (int i = 0; i < numPlayers; i++) {
                    cin >> skillLevel;
                    newPlayers.push_back(skillLevel);
                }
                heapifyToMaxHeap(newPlayers);
                break;
            }

            case 4:
                cout << "Exiting Tournament Ranking System. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}