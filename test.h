#pragma once
#include <iostream>
#include "BinaryTree.h"
#pragma once
#include <iostream>
#include "BinaryTree.h"
#include "Heap.h"
using namespace std;



void tests() {
    int test_data[5] = {10, 20, 40, 30, 50};

    binary_tree<int> test_binary_tree;
    for (int i : test_data)
        test_binary_tree.add_(i);

    heap<int> test_heap;
    for (int i : test_data)
        test_heap.add(i);



    if(test_binary_tree.forward_pass_() == "10 20 40 30 50 ")
        cout << "Test 1 passed!" << endl;
    else
        cout << "Test 1 failed" << endl;

    test_binary_tree.del_elem_(6);
    if(test_binary_tree.forward_pass_() == "10 20 40 30 50 ")
        cout << "Test 2 passed!" << endl;
    else
        cout << "Test 2 failed" << endl;

    test_binary_tree.del_elem_(4);
    if(test_binary_tree.forward_pass_() == "10 20 50 30 ")
        cout << "Test 3 passed!" << endl;
    else
        cout << "Test 3 failed" << endl;

    test_binary_tree.add_elem_(16);
    if(test_binary_tree.forward_pass_() == "10 20 16 50 30 ")
        cout << "Test 4 passed!" << endl;
    else
        cout << "Test 4 failed" << endl;

    if(test_binary_tree.search_(30) == 30)
        cout << "Test 5 passed!" << endl;
    else
        cout << "Test 5 failed" << endl;

    auto ext_tree = test_binary_tree.subtree_extraction(20);
    if(ext_tree->forward_pass_() == "20 16 50 30 ")
        cout << "Test 6 passed!" << endl;
    else
        cout << "Test 6 failed" << endl;

    if(test_heap.search(87) == "not found\n")
        cout << "Test 7 passed!" << endl;
    else
        cout << "Test 7 failed" << endl;

    if(test_heap.search(30) == "element found\n")
        cout << "Test 8 passed!" << endl;
    else
        cout << "Test 8 failed" << endl;

    test_binary_tree.free_tree_();
    ext_tree->free_tree_();
    delete ext_tree;

}
