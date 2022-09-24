/**
 * @file main.cpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief LinearTable Practice
 * @version 0.1
 * @date 2022-09-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

class ArraySolution {
private:
    int* data     = nullptr;
    int numOfNums = 0;

    void getNumOfNums(const char* fileToOpen) {
        int tmp = 0; // store the input num temporarily
        ifstream srcFile(fileToOpen, ios::in);
        if (!srcFile.is_open()) {
            throw std::runtime_error("error opening source file.");
        }
        while (srcFile >> tmp) {
            ++numOfNums;
        }
        srcFile.close();
        if (numOfNums == 0) {
            throw std::logic_error("the opened file does not contain any data!");
        }
    }

    void toStoreData(const char* fileToOpen) {
        int tmp = 0; // store the input num temporarily
        ifstream srcFile(fileToOpen, ios::in);
        if (!srcFile.is_open()) {
            throw std::runtime_error("error opening source file.");
        }
        data    = new int(numOfNums);
        int POS = 0;
        while (srcFile >> tmp) {
            data[POS] = tmp;
            ++POS;
        }
    }

public:
    ArraySolution(const char* fileToOpen) {
        getNumOfNums(fileToOpen);
        toStoreData(fileToOpen);
    }

    void normalOrderEcho() {
        cout << endl;
        cout << "original order => ";
        cout << "[ ";
        for (int i = 0; i < numOfNums; ++i) {
            cout << data[i] << ", ";
        }
        cout << "\b\b  \b\b";
        cout << " ]";
        cout << endl;
    }

    void reverseOrderEcho() {
        cout << endl;
        cout << "reversed order => ";
        cout << "[ ";
        for (int i = numOfNums - 1; i >= 0; --i) {
            cout << data[i] << ", ";
        }
        cout << "\b\b  \b\b";
        cout << " ]";
        cout << endl;
    }

    ~ArraySolution() {
        delete[] data;
    }

    static void Solution(const char* filename = "./data.txt") {
        ArraySolution toOperateObj(filename);
        cout << "This is ArraySolution" << endl;
        cout << endl;
        toOperateObj.normalOrderEcho();
        toOperateObj.reverseOrderEcho();
    }
};

class LinkedListSolution {
private:
    class LinkedList {
    private:
        struct Node {
            int data   = 0;
            Node* next = nullptr;
            Node(int input) { data = input; }
        };
        Node* head = nullptr;
        Node* tail = nullptr;

        struct NodePtr {
            Node* ptr     = nullptr;
            NodePtr* next = nullptr;
            NodePtr* prev = nullptr;
            NodePtr(Node* ptr) { this->ptr = ptr; }
        };
        NodePtr* HEAD = nullptr;
        NodePtr* TAIL = nullptr;

        int numOfNodes = 0;

    public:
        void add(int input) {
            Node* tmp = new Node(input);
            if (head == nullptr) {
                head = tmp;
                tail = tmp;
            } else {
                tail->next = tmp;
                tail       = tmp;
            }

            NodePtr* TMP = new NodePtr(tmp);
            if (HEAD == nullptr) {
                HEAD = TMP;
                TAIL = TMP;
            } else {
                TAIL->next = TMP;
                TMP->prev  = TAIL;
                TAIL       = TMP;
            }

            ++numOfNodes;
        }

        void reverse() {
            NodePtr* TMP = TAIL;
            while (TMP != nullptr) {
                if (TMP == TAIL) {
                    head = TMP->ptr;
                    tail = TMP->ptr;
                } else {
                    tail->next = TMP->ptr;
                    tail       = TMP->ptr;
                }
                TMP = TMP->prev;
            }
        }

        void echo(bool ifReversed = false) {
            Node* tmp = head;
            cout << endl;
            if (!ifReversed) {
                cout << "original order => ";
            } else {
                cout << "reversed order => ";
            }
            while (tmp != nullptr) {
                cout << tmp->data << " -> ";
            }
            cout << "\b\b\b\b    \b\b\b\b";
            cout << endl;
        }

        ~LinkedList() {
            NodePtr* TMP = HEAD;
            while (TMP != nullptr) {
                NodePtr* nextToDelete = TMP->next;
                delete TMP->ptr;
                delete TMP;
                TMP = nextToDelete;
            }
        }
    };
    LinkedList* theList = nullptr;

public:
    void initLinkedList() {
        theList = new LinkedList();
    }

    void deleteLinkedList() {
        delete theList;
    }

    void makeSureFileIsNotEmpty(const char* filename) {
        int tmp           = 0; // store the input num temporarily
        int currNumOfNums = 0; // store how many nums have been inputted
        ifstream srcFile(filename, ios::in);
        if (!srcFile.is_open()) {
            throw std::runtime_error("error opening source file.");
        }
        while (srcFile >> tmp) {
            ++currNumOfNums;
        }
        srcFile.close();
        if (currNumOfNums == 0) {
            throw std::logic_error("the opened file does not contain any data!");
        }
    }

    void toStoreData(const char* filename) {
        int tmp = 0; // store the input num temporarily
        ifstream srcFile(filename, ios::in);
        if (!srcFile.is_open()) {
            throw std::runtime_error("error opening source file.");
        }
        while (srcFile >> tmp) {
            theList->add(tmp);
        }
        srcFile.close();
    }

    void originalOrderEcho() {
        theList->echo(false);
    }

    void reverseOrderEcho() {
        theList->reverse();
        theList->echo(true);
    }

    LinkedListSolution(const char* filename) {
        initLinkedList();
        makeSureFileIsNotEmpty(filename);
        toStoreData(filename);
    }

    static void Solution(const char* filename = "./data.txt") {
        LinkedListSolution toOperateObj(filename);
        toOperateObj.originalOrderEcho();
        toOperateObj.reverseOrderEcho();
    }
};

int main() {
    ArraySolution::Solution();
    LinkedListSolution::Solution();
}