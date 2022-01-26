#include <iostream> 
#include "sort.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include <time.h>

bool comp(const int &a,const int &b){
    return a < b;
}

int main(){
    srand(time(nullptr));

    std::cout << "Hello in my 1st lab" << std::endl;
    std::cout << "Choose type of struct: Array(0) or List(1)" << std::endl;
    bool flag;
    std::cin >> flag;

    Bubblesort<int> bubb;
    Heapsort<int> heap;
    Quicksort<int> quick;

    if(flag){
        ArraySequence<int> data;
        std::cout << "Enter data amount" << std::endl;
        int n = 0;
        std::cin >> n;
        std::cout << "Enter data:" << std::endl;
        for(int i = 0; i < n; i++){
            int p = 0;
            std:: cin >> p;
            data.Append(p);
        }
        ArraySequence<int> data1(data);
        ArraySequence<int> data2 = data;

        bubb.sort(data, comp);
        heap.sort(data1, comp);
        quick.sort(data2, comp);
        std::cout  << "Bubble" << '\t' << "Heap" << '\t' << "Quick" << std::endl;
        for(int i = 0; i < n; i++){
            std::cout  << data.Get(i) << '\t' << data1.Get(i) << '\t' << data2.Get(i) << std::endl;
        }        

    } else {
        LinkedListSequence<int> data;
        std::cout << "Enter data amount" << std::endl;
        int n = 0;
        std::cin >> n;
        std::cout << "Enter data:" << std::endl;
        for(int i = 0; i < n; i++){
            int p = 0;
            std:: cin >> p;
            data.Append(p);
        }
        LinkedListSequence<int> data1(data);
        LinkedListSequence<int> data2 = data;

        bubb.sort(data, comp);
        heap.sort(data1, comp);
        quick.sort(data2, comp);
        std::cout  << "Bubble" << '\t' << "Heap" << '\t' << "Quick" << std::endl;
        for(int i = 0; i < n; i++){
            std::cout  << data.Get(i) << '\t' << data1.Get(i) << '\t' << data2.Get(i) << std::endl;
        }   
    }
    
    return 0;
}