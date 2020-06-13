#pragma once
#include <iostream>
#include "BinaryTree.h"
#include "Tests.h"

using namespace std;


int main() {

    cout << "for tests input 1" << endl;
    scanf ("%i", &k);
    if (k == 1)
        tests();

    cout << "Working with: (1)binary tree, (2)heap " << endl;
    scanf ("%i", &k);
    
    if (k==1) {
    binary_tree<int> binary_tree;
    for (int i = 0; i < 5; i++)
    binary_tree.add_(rand() % 100);
    cout << "tree created" << endl;
    binary_tree.print_tree_(); 
            
     cout << "Working with: (1)insert element, (2)find a specific element, (3)delete element, "
            "(4)see tree, (5)make forward pass " << endl;
     scanf ("%i", &k);
     int input;
            if (k == 1) {
                cout << "Enter new element: ";
                cin >> input;
                binary_tree.add_elem_(input);
            }

            if (k == 2) {
                cout << "Which element you want to check: ";
                cin >> input;
                binary_tree.search_(input);
                cout << "Element found" << endl;
            }

            if (k == 3) {
                cout << "Which element you want to delete: ";
                cin >> input;
                binary_tree.del_elem_(input);
            }

            if (k == 4) {
                binary_tree.print_tree_();
                cout << endl;
            }

            if (answer == 5) {
                cout << "Forward pass: ";
                cout << binary_tree.forward_pass_() << endl;
            }
            if ((k != 1) || (k != 2) || (k != 3) || (k != 4)|| (k != 5)) {
                cout<<"Incorrect answer";
            }
            
    }
        binary_tree.free_tree_();
        
    else if (k == 2) {
        heap<int> heap;
        for (int i = 0; i < 5; i++)
        heap.add(rand() % 1000);
        cout << "created heap" << endl;
        heap.print_heap(); 
        cout << "What do you want to do with heap: (1)insert element, (2)delete element, (3)find a specific element, "
            "(4)see heap" << endl;
        scanf("%i", &k);
            if (k == 1) {
                cout << "Enter new element: ";
                cin >> input_;
                heap.add(input_);
            }

            if (k == 2) {
                cout << "Which element you want to delete: ";
                cin >> input_;
                heap.delete_element(input_);
            }

            if (k == 3) {
                cout << "Which element you want to check: ";
                cin >> input_;
                cout << heap.search(input_);
            }

            if (k == 4) {
                heap.print_heap();
                cout << endl;
            }
            if ((k != 1) || (k != 2) || (k != 3) || (k != 4)) {
                cout<<"Incorrect answer";
            }
        
    }
    else 
        cout<<"Incorrect answer";
    }
    return 0;
}
