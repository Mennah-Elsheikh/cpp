#include <iostream>
#include <algorithm> // For using the max function

struct Node {
    long Key;
    Node* Left;
    Node* Right;

    Node(int data) : Key(data), Left(nullptr), Right(nullptr) {}
};

struct BST {
    Node* Temp = nullptr; // To Iterate at Tree
    Node* Root = nullptr; // To refer First Node
    Node* Previous = nullptr; // Holds Previous Node

    // Function to add a new node to the tree
    void Add(int key) {
        Node* node = new Node(key);
        node->Left = nullptr;
        node->Right = nullptr;

        if (Root == nullptr) {
            Root = node;
            Temp = Root;
            return;
        }

        Temp = Root;
        while (Temp != nullptr) {
            Previous = Temp;
            if (Temp->Key < key) {
                Temp = Temp->Right;
            }
            else {
                Temp = Temp->Left;
            }
        }

        if (Previous->Key < key) {
            Previous->Right = node;
        }
        else {
            Previous->Left = node;
        }
    }

    // Function to find the maximum value in the tree iteratively
    long GetMax() {
        Temp = Root;
        if (Temp == nullptr) {
            std::cout << "Tree is Empty." << std::endl;
        }
        while (Temp != nullptr) {
            Previous = Temp;
            Temp = Temp->Right;
        }
        return Previous->Key;
    }

    // Recursive helper function to find the maximum value in the tree
    void GetMaxHelper(Node* Temp) {
        if (Temp->Right == nullptr) {
            std::cout << "Max: " << Previous->Key << std::endl;
        }
        else {
            Previous = Temp->Right;
            GetMaxHelper(Temp->Right);
        }
    }

    // Function to find the minimum value in the tree iteratively
    long GetMin() {
        Temp = Root;
        if (Temp == nullptr) {
            std::cout << "Empty" << std::endl;
        }
        else {
            while (Temp != nullptr) {
                Previous = Temp;
                Temp = Temp->Left;
            }
        }
        return Previous->Key;
    }

    // Recursive helper function to find the minimum value in the tree
    void GetMinHelper(Node* Temp) {
        if (Temp == nullptr) {
            std::cout << Previous->Key << std::endl;
        }
        else {
            Previous = Temp;
            GetMinHelper(Temp->Left);
        }
    }

    // Recursive function to calculate the height of the tree
    long GetHelperHeight(Node* temp) {
        if (temp == nullptr) {
            return -1;
        }
        long Left_Sub = GetHelperHeight(temp->Left);
        long Right_Sub = GetHelperHeight(temp->Right);
        return 1 + std::max(Left_Sub, Right_Sub);
    }

    // Function to calculate the height of the tree
    long GetHeight() {
        Temp = Root;
        if (Temp == nullptr) {
            return -1;
        }
        return GetHelperHeight(Temp);
    }
};

int main() {
    BST bST;

    for (int i = 0; i < 4; i++) {
        bST.Add(i);
    }

    std::cout << "Max by iteration: " << bST.GetMax() << std::endl;
    std::cout << "Recursion: ";
    bST.GetMaxHelper(bST.Root);

    for (int i = -3; i <= 0; i++) {
        bST.Add(i);
    }

    std::cout << "Min by iteration: " << bST.GetMin() << std::endl;
    std::cout << "Recursion: ";
    bST.GetMinHelper(bST.Root);

    std::cout << "Height: " << bST.GetHeight() << std::endl;

    return 0;
}
