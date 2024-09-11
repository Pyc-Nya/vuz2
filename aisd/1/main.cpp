#include <iostream>
#include <cstring>
#include <cstdlib>

bool existsInArray(const char arr[], int size, char value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

void outputArray(const char name, const char arr[], int size) {
    std::cout << "Array " << name << ": [";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int cmp(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

void inputArray(char name, char arr[], int& size) {
    char A[80] = {0};  
    std::cout << "Input array " << name << " of decimal digits: ";
    std::cin >> A;

    int j = 0;
    for (int i = 0; i < 80 && A[i] != '\0'; ++i) {
        if ('0' <= A[i] && A[i] <= '9') {
            arr[j++] = A[i];
        }
    }

    std::qsort(arr, j, sizeof(char), cmp);

    int k = 0;
    for (int i = 0; i < j; ++i) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[k++] = arr[i];
        }
    }

    size = k; 
}

struct Node {
    char data;
    Node* next;
};

void append(Node*& head, char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* createListFromArray(const char arr[], int size) {
    Node* head = nullptr;
    for (int i = 0; i < size; ++i) {
        append(head, arr[i]);
    }
    return head;
}

void outputList(const char name, Node* head) {
    std::cout << "List " << name << ": [";
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
            std::cout << ", ";
        }
        temp = temp->next;
    }
    std::cout << "]" << std::endl;
}

bool existsInList(Node* head, char value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    char a[10], b[10], c[10], d[10], e[10];
    int sizeA = 0, sizeB = 0, sizeC = 0, sizeD = 0, eSize = 0;

    inputArray('A', a, sizeA);
    inputArray('B', b, sizeB);
    inputArray('C', c, sizeC);
    inputArray('D', d, sizeD);

    for (int i = 0; i < sizeA; ++i) {
        if (existsInArray(b, sizeB, a[i]) && !existsInArray(c, sizeC, a[i]) && !existsInArray(d, sizeD, a[i])) {
            e[eSize++] = a[i];
        }
    }

    outputArray('A', a, sizeA);
    outputArray('B', b, sizeB);
    outputArray('C', c, sizeC);
    outputArray('D', d, sizeD);
    std::cout << "Result is array E: E = (A && B) \\ (C || D)" << std::endl;
    outputArray('E', e, eSize);

    Node* listA = createListFromArray(a, sizeA);
    Node* listB = createListFromArray(b, sizeB);
    Node* listC = createListFromArray(c, sizeC);
    Node* listD = createListFromArray(d, sizeD);
    Node* listE = nullptr;

    std::cout << "Now the same for lists" << std::endl;

    for (Node* tempA = listA; tempA != nullptr; tempA = tempA->next) {
        if (existsInList(listB, tempA->data) && !existsInList(listC, tempA->data) && !existsInList(listD, tempA->data)) {
            append(listE, tempA->data);
        }
    }

    outputList('A', listA);
    outputList('B', listB);
    outputList('C', listC);
    outputList('D', listD);
    std::cout << "Result is list E: E = (A && B) \\ (C || D)" << std::endl;
    outputList('E', listE);

    freeList(listA);
    freeList(listB);
    freeList(listC);
    freeList(listD);
    freeList(listE);

    return 0;
}
