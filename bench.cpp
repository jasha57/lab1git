#include <fstream>
#include <iostream>
#include "sort.hpp"
#include "LinkedListSequence.hpp"
#include "ArraySequence.hpp"
#include <time.h>

bool comp(const int &a,const int &b){
    return a > b;
}

void timetestra(std::string filename, Sorting<int> & psort, int start, int end, int step){
    std::ofstream file(filename);
    int k = 0;
    for(int N = start; N < end; N += step){
        LinkedListSequence<int> massdl;
        for(int i = 0; i < N; i++){
            massdl.Append(i);
        }

        clock_t p = clock();
            psort.sort(massdl, comp);
        p = clock() - p;

        double timep = (double) p / CLOCKS_PER_SEC;
       // std::cout << N << " " << timep << "\n";
        file << N << " " << timep << std::endl;


        double percent = (double)(N-start) / (double)(end - start);
        //std::cout << percent << std::endl;
        if( percent > k*0.05){
            std::cout << 5*k << "%" << std::endl;
            k++;
        }
        
    }
}

int main(){
    srand(time(nullptr));
    
    
    Quicksort<int> qsort;
    Heapsort<int> hsort;
    Bubblesort<int> bsort;

    std::cout <<"QUICKSORTREVERS is start" << std::endl;
    timetestra("./timedata/QuickSortRandL.txt", qsort, 10,5000, 10);
    std::cout <<"BUBBLESORTREVERS is start" << std::endl;
    timetestra("./timedata/BubbleSortRandL.txt", bsort, 10,5000, 10);
    std::cout <<"HEAPSORT is start" << std::endl;
    timetestra("./timedata/HeapSortRandL.txt", hsort, 10,5000, 10);

    

    return 0;
}