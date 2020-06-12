#pragma once
#include <exception>
#include <random>
#include <iostream>
using namespace std;

struct my_exception_ : public exception {
    [[nod]] const char * what () const noexcept override {return "Element doesn't exist";}
};
struct my_exception_2 : public exception {[[nod]] const char * what () const noexcept override {
        return "You can't delete root-element";
    }
};


template <typename T>
class binary_tree {
protected:
    struct branch {
        T data;
        branch* left_branch;
        branch* right_branch;

    };
    branch* root = nullptr;
    int size = 0;
    string forward_pass_s = "";
    int indent = 0;
    T for_extraction[100];
    int f_e = 0;
public:
    explicit binary_tree<T>() = default;
private:
    void add(T data_, branch*& branch_) {
        if (!branch_) {branch_ = new branch; branch_->data = data_; branch_->left_branch = nullptr;
        branch_->right_branch = nullptr; return;
        }
        else {
            if (branch_->data > data_) {add(data_, branch_->left_branch);}
            else {add(data_, branch_->right_branch);}
        }
    }

    void print_tree(branch* branch_) {if (this->is_empty_() == "yes")
            return; if (!branch_)
            return;
        indent += 4; print_tree(branch_->left_branch);
        for (int i = 0; i < indent; i++)
            cout << " ";
        cout << branch_->data << endl;
        print_tree(branch_->right_branch);
        indent -= 4;
    }

    void forward_pass(branch*& branch_) {
        if (nullptr == branch_)
            return;
        forward_pass_s += to_string(branch_->data);
        forward_pass_s += " ";
        forward_pass(branch_->left_branch);
        forward_pass(branch_->right_branch);
    }

    void add_elem(T data_, branch*& branch_) {if (!branch_) {branch_ = new branch;branch_->data = data_;
    branch_->left_branch = nullptr;branch_->right_branch = nullptr;return;}
        else {
            if (data_ < branch_->data) {add_elem(data_, branch_->left_branch);}
            else if (data_ > branch_->data) {add_elem(data_, branch_->right_branch);}
        }
    }

    void free_tree(branch* branch_) {
        if (this->is_empty_() == "yes") return;
        if (!branch_) return;
        free_tree(branch_->left_branch);
        free_tree(branch_->right_branch);
        delete branch_;
    }

    branch* del_elem(branch*& branch_, T data_) {
        if (data_ == root->data)
            throw my_exception_2();
        if (branch_ == nullptr)
            return branch_;
        if (data_ == branch_->data) {
            branch* tmp;
            if (branch_->right_branch == nullptr)
                tmp = branch_->left_branch;
            else {
                branch* ptr = branch_->right_branch;
                if (ptr->left_branch == nullptr) {ptr->left_branch = branch_->left_branch;tmp = ptr;}
                else {
                    branch* min_p = ptr->left_branch;
                    while (min_p->left_branch != nullptr) {ptr = min_p;min_p = ptr->left_branch;}
                    ptr->left_branch = min_p->right_branch;min_p->left_branch = branch_->left_branch;
                    min_p->right_branch = branch_->right_branch;tmp = min_p;
                }
            }

            delete branch_;
            return tmp;
        }

        else if (data_ < branch_->data)branch_->left_branch = del_elem(branch_->left_branch, data_);

        else branch_->right_branch = del_elem(branch_->right_branch, data_);

        return branch_;
    }

    branch* search(branch *branch_, T data_) {
        if (branch_ == nullptr)
            throw my_exception_();
        if (data_ == branch_->data)
            return branch_;

        else if (data_ < branch_->data)
            return search(branch_->left_branch, data_);
        else
            return search(branch_->right_branch, data_);
    }

    void forward_pass_val(branch* branch_) {if (nullptr == branch_)return;
        for_extraction[f_e] = branch_->data;f_e += 1;forward_pass_val(branch_->left_branch);forward_pass_val(branch_->right_branch);
    }

public:
    void add_(T data_) {add(data_, root);this->size += 1;}

    void print_tree_() {print_tree(root);}

    string forward_pass_() {forward_pass(root);string tmp = forward_pass_s;forward_pass_s = "";return tmp;}

    void add_elem_(T data_) {add_elem(data_, root);this->size += 1;}

    string is_empty_() {if (!root) {return "yes";}
        else {return "no";}
    }

    void free_tree_() {free_tree(root);}

    void del_elem_(T data_) {del_elem(root, data_);this->size -= 1;}

    T search_(T data_) {auto output = search(root, data_);return output->data;}

    binary_tree<T>* subtree_extraction(T item) {auto first = this->search(root, item);auto subtree = new binary_tree<T>;
        forward_pass_val(first);for (int i = 0; i < f_e; i++)
        subtree->add_elem_(for_extraction[i]);
        return subtree;
    }
};
