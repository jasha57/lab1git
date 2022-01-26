#ifndef SORT_HPP
#define SORT_HPP
#include "sequence.hpp"

template<typename T>
class Sorting{
    public:
    virtual void sort(Sequence<T> & data, bool (*cmp)(const T&, const T&));
};

template<typename T>
class Heapsort : public Sorting<T>{
    public:
        void sort(Sequence<T> & data, bool (*cmp)(const T&,const T&)){
            HeapSortrev(data, 0, data.GetLenght() - 1, cmp);
        }
    private:
        void HeapSortrev(Sequence<T> & data,unsigned int start,unsigned int end ,bool (*cmp)( const T&, const T&)){
            int l = end - start + 1;
            if(l  == 1){
                return;
            }
            if (l % 2 == 0){
                for(int k = l/2 - 1; k >= 0; --k){
                    if((2*k + 1 < l) && cmp(data.Get(k + start), data.Get(2*k + 1 + start))){
                        T temp = data.Get(k + start);
                        data.Set(k + start, data.Get(2*k + 1 + start));
                        data.Set(2*k + 1 + start, temp);
                    }

                    if((2*k + 2 < l) && cmp(data.Get(k + start), data.Get(2*k + 2 + start))){
                        T temp = data.Get(k + start);
                        data.Set(k + start, data.Get(2*k + 2 + start));
                        data.Set(2*k + 2 + start, temp);
                    }
                }

            } else {
                for(int k = (l - 1)/ 2 + 1; k >= 0; --k){
                    if((2*k + 1 < l) && cmp(data.Get(k + start), data.Get(2*k + 1 + start))){
                        T temp = data.Get(k + start);
                        data.Set(k + start, data.Get(2*k + 1 + start));
                        data.Set(2*k + 1 + start, temp);
                    }

                    if((2* k + 2 < l) && cmp(data.Get(k + start), data.Get(2*k + 2 + start))){
                        T temp = data.Get(k + start);
                        data.Set(k + start, data.Get(2*k + 2 + start));
                        data.Set(2*k + 2 + start, temp);
                    }
                }
            }

            HeapSortrev(data, start + 1, end, cmp);
        }
};


template<typename T>
class Quicksort : public Sorting<T>{
public:
    void sort(Sequence<T> & data, bool (*comp)(const T&, const T&)){
        QuickSortGeneral(data, 0, data.GetLenght() - 1, comp);
    }
private:
    void QuickSortGeneral(Sequence<T> & data, int start, int end, bool (*comp)(const T&, const T&)){
        if((end - start) == 1){
            if(comp(data.Get(start), data.Get(end)) ){
                T tmp = data.Get(start);
                data.Set(start, data.Get(end));
                data.Set(end, tmp);
            }
            return;
        }
        int right = end;
        int left = start;
        T key = data.Get((start + end) / 2);

        while(right > left){
            while(comp(data.Get(right), key) ) {
                right--;
            }
            while(comp(key, data.Get(left)) ) {
                left++;
            }
            if(right >= left){
                T tmp = data.Get(left);
                data.Set(left, data.Get(right));
                data.Set(right, tmp);
                right--;
                left++;
            }
        }
        if(left < end){
            QuickSortGeneral(data, left, end, comp);
        }
        if(start < right){
            QuickSortGeneral(data, start, right, comp);
        }
    }

};

template<typename T>
class Bubblesort : public Sorting<T>{
public:
    void sort(Sequence<T> & data,bool (*cmp)(const T&, const T&)){
        for(int i = 0; i < data.GetLenght(); i++){
            for(int j = data.GetLenght() - 1; j > i; j--){
                if(cmp(data.Get(j - 1), data.Get(j)) ){
                    T tmp = data.Get(j);
                    data.Set(j, data.Get(j - 1) );
                    data.Set(j - 1, tmp);
                }
            }
        }
    }
};

#endif 