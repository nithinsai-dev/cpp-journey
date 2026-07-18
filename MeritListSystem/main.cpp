#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;
    double cgpa;
    int appTime;
};

struct Node {
    Student data;
    Node* next;
    Node(Student s) : data(s), next(nullptr) {}
};

Student applications[1000];
int count = 0;

Node* head = nullptr;
Node* tail = nullptr;

void addApplication(int id, string name, double cgpa);
int searchApplication(int id);
void deleteApplication(int id);
void displayApplications();
void bubbleSort(Student arr[], int n);
void selectionSort(Student arr[], int n);
void insertionSort(Student arr[], int n);
void mergeSort(Student arr[], int left, int right);
void quickSort(Student arr[], int low, int high);
void insertAtEnd(Node*& head, Node*& tail, Student s);
void deleteFromFront(Node*& head, Node*& tail);


int main() {
    int choice;
    do {
        cout << "\n--- Course Registration System ---\n";
        cout << "1. Add Application\n";
        cout << "2. Search Application\n";
        cout << "3. Delete Application\n";
        cout << "4. Display All Applications\n";
        cout << "5. Add to Waiting List\n";
        cout << "6. Remove from Waiting List (seat available)\n";
        cout << "7. Generate Merit List\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id;
        string name;
        float cgpa;

        switch (choice) {
            case 1:
                cout << "Enter ID, Name, CGPA: ";
                cin >> id >> name >> cgpa;
                addApplication(id, name, cgpa);
                break;
            case 2: {
                cout << "Enter ID to search: ";
                cin >> id;
                int index = searchApplication(id);
                if (index != -1)
                    cout << "Found: " << applications[index].name << " CGPA: " << applications[index].cgpa << "\n";
                else
                    cout << "Not found\n";
                break;
            }
            case 3:
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteApplication(id);
                break;
            case 4:
                displayApplications();
                break;
            case 5: {
                cout << "Enter ID";
                cin >> id;
                int index = searchApplication(id);
                if (index == -1) {
                    cout << "Student not found\n";
                    break;
                }
                insertAtEnd(head,tail,applications[index]);
                break;
            }
            case 6:
                if (head == nullptr) {
                    cout << "The list is empty\n";
                }
                else {
                    deleteFromFront(head,tail);
                }
                break;
            case 7: {
                if (count == 0) {
                    cout << "No applications to sort\n";
                    break;
                }

                // making a copy so original list is not changed
                Student merit[1000];
                for (int i = 0; i < count; i++) merit[i] = applications[i];

                cout << "Choose sorting algorithm:\n";
                cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n";
                int sortChoice;
                cin >> sortChoice;

                switch (sortChoice) {
                    case 1: bubbleSort(merit, count); break;
                    case 2: selectionSort(merit, count); break;
                    case 3: insertionSort(merit, count); break;
                    case 4: mergeSort(merit, 0, count - 1); break;
                    case 5: quickSort(merit, 0, count - 1); break;
                    default: cout << "Invalid choice\n"; break;
                }

                cout << "\n--- Merit List ---\n";
                for (int i = 0; i < count; i++) {
                    cout << merit[i].id << " - " << merit[i].name << " - CGPA: " << merit[i].cgpa << "\n";
                }
                break;
            }
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 8);

    return 0;
}

void addApplication(int id, string name, double cgpa) {
    if (count >= 1000) {
        cout << "Array full, cannot add more applications\n";
        return;
    }
    applications[count].id = id;
    applications[count].name = name;
    applications[count].cgpa = cgpa;
    applications[count].appTime = count;
    count++;

    cout << "Application added";
}

int searchApplication(int id) {
    for (int i = 0; i < count; i++) {
        if (applications[i].id == id) return i;
    }
    return -1;
}

void deleteApplication(int id) {
    int idx = searchApplication(id);
    if (idx == -1) {
        cout << "Student not found\n";
        return;
    }
    for (int i = idx; i < count - 1; i++) {
        applications[i] = applications[i + 1];
    }
    count--;
}

void displayApplications() {
    for (int i = 0; i < count; i++) {
        cout << "Application ID : "  << applications[i].id << " \nApplication Name : " << applications[i].name
             << "\n CGPA: " << applications[i].cgpa << "\n";
    }
}

void mergeSort(Student arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // merge
    int left = low, right = mid + 1;
    vector<Student> v;
    while (left <= mid && right <= high) {
        if (arr[left].cgpa > arr[right].cgpa) {
            v.push_back(arr[left]);
            left++;
        } else if (arr[left].cgpa < arr[right].cgpa) {
            v.push_back(arr[right]);
            right++;
        } else {
            if (arr[left].appTime < arr[right].appTime) {
                v.push_back(arr[left]);
                left++;
            } else {
                v.push_back(arr[right]);
                right++;
            }
        }
    }
    while (left <= mid) {
        v.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        v.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = v[i - low];
    }
}

void insertAtEnd(Node*& head, Node*& tail, Student s) {
    Node* newNode = new Node(s);

    if (head == nullptr ){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void deleteFromFront(Node *&head, Node *&tail) {
    Node* temp = head;
    cout << "Seat allotted to : " << temp -> data.id << " - "  << temp -> data.name << "\n";
    head = temp -> next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
}

void bubbleSort(Student arr[], int n){
    //yet to implement
}

void selectionSort(Student arr[], int n) {
    //yet to implement
}

void insertionSort(Student arr[], int n){
    //yet to implement
}

void quickSort(Student arr[], int low, int high) {
    //yet to implement
}