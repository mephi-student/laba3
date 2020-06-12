#pragma once
#include <iostream>

using namespace std;

template <typename T>
class heap {
private:
    struct branch {
        T data;
        int us = 0;
    };
    int maxelem = 1000;
    branch *el;
    int size = 0;

public:
    explicit heap() {
        el = new branch[maxelem];
    }

public:
    void delete_el(T item) {
        int target_index = 0, flag = 0;

        for (int i = 0; i < size; i++) {
            if (item == el[i].data && el[i].us == 1) {
                target_index = i;
                flag = 1;
            }
        }

        int i = target_index;

        if (flag == 1) {
            while (i < size && (el[2*i + 1].us != 0 || el[2*i + 2].us != 0 || el[i].us != 0)) {

                if (el[2*i + 2].us != 0 && el[2*i + 2].data > el[2*i + 1].data) {
                    el[i].data = el[2*i + 2].data; el[i].us = 1; el[2*i + 2].us = 0;i = 2*i + 2;
                }
                else if (el[2*i + 1].us != 0 && el[2*i + 2].data < el[2*i + 1].data) {
                    el[i].data = el[2*i + 1].data; el[i].us = 1; el[2*i + 1].us = 0; i = 2*i + 1;
                } else
                    el[i].us = 0;
            }
        }
    }

    void add(T item) {
        int i = size, p;
        T tmp;
        el[i].data = item;
        el[i].us = 1;
        p = (i-1)/2;

        while(p >= 0 && i > 0)  {
            if(el[i].data > el[p].data) {
                tmp = el[i].data;
                el[i].data = el[p].data;
                el[p].data = tmp;
                if (el[p].us == 0) {
                    el[p].us = 1;
                    el[i].us = 0;
                }
            }

            i = p;
            p = (i-1)/2;
        }

        size += 1;
    }



    void print_heap() {
        int i = 0;
        int j = 1;
        while(i < size) {
            while((i < j) && (i < size)) {
                if (el[i].us != 0)
                    cout << el[i].data << " ";
                i++;
            }
            cout << endl;
            j = j * 2 + 1;
        }
    }

    string search(T item) {
        for (int i = 0; i < size; i++) {
            if(el[i].data == item && el[i].us == 1)
                return "element found\n";
        }
        return "not found\n";
    }

    ~heap() {
        delete[] el;
    }
};
