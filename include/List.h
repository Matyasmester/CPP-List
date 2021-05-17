#include <vector>
#include <algorithm>
#include <set>
#ifndef LIST_H
#define LIST_H
#define EMPTY 0

using namespace std;

template <typename T>
class List
{
    /*An attempt at making the C# class List<T> in C++.*/
    private:
        const unsigned char _defaultSize = 10;
        unsigned short Size = _defaultSize;
        vector<T> _items;

        void UpdateSize(){Size = _items.size();};

    public:
        List(){
            //ctor
        }

        /** Loops through the items of the List, finds the first item that matches the param,
        and returns its index. If it doesn't find any, returns -1. **/
        int IndexOf(T value){
            int index = 0;
            for(T item : _items){
                if(value == item) return index;
                index++;
            }
            return -1;
        }

        int LastIndexOf(T item){
            int LastIndex = -1;
            unsigned short index = 0;
            for(T val : _items){
                if(val == item) LastIndex = index;
                index++;
            }
            return LastIndex;
        }

        int FirstEmptyIndex(){
            int index = 0;
            for(T item : _items){
                if(item == EMPTY) return index;
                index++;
            }
            return -1;
        }

        /** Counts all occurences of the given item. **/
        int Count(T item){
            int nItems = 0;
            for(T val : _items){
                if(item == val) nItems++;
            }
            return nItems;
        }

        int GetSize(){
            return Size;
        }

        /** Adds a single item to the end of the List, then updates the Size property.
            If the item would not fit, it reserves memory for the item, plus two more items.**/
        void Add(T item){
            unsigned short maxitems = _items.capacity();
            if(Size + 1 >= maxitems){
                _items.reserve(maxitems + 3);
            }
            _items.push_back(item);
            UpdateSize();
        }

        /** Loops through the given vector<t>'s elements, and adds them each to the end of the List.
            First checks if the vector fits, and if it doesn't, reserves 1.25x enough space for it. **/
        void Add(vector<T> toAdd){
            unsigned short ArraySize = toAdd.size();
            unsigned short ItemCount = Size;

            unsigned short maxitems = _items.capacity();
            unsigned short totalsize = ItemCount + ArraySize;

            if(totalsize > maxitems){
                _items.reserve(totalsize * 1.25);
            }

            for(T item : toAdd){
                _items.push_back(item);
            }
            UpdateSize();
        }

        /** Removes the first element of the List. **/
        void Remove(){
            _items.erase(_items.begin());
            UpdateSize();
        }

        /** Removes the element at the given index from the List. **/
        void Remove(int index){
            _items.erase(_items.begin() + index);
            UpdateSize();
        }

        /** Searches for the index of the given item, and removes it from the List.
            If it doesn't find it, the function returns. **/
        void Remove(T item){
            int itemIndex = IndexOf(item);
            if(itemIndex == -1) return;
            _items.erase(_items.begin() + itemIndex);
            UpdateSize();
        }

        /** Removes all occurences of the specified item. **/
        void RemoveAll(T item){
            for(T val : _items){
                if(val == item) Remove(val);
            }
        }

        /** Removes all items from the list, then updates the size. **/
        void Clear(){
            _items.clear();
            UpdateSize();
        }

        /** Takes a function that returns void and has one parameter T, and runs the function with every item in the List. **/
        void ForEach(void (*func)(T)){
            for(T item : _items){
                func(item);
            }
        }

        /** Dumps all elements of the List into a std::set<T>, then puts them back. **/
        void RemoveDuplicates(){
            set<T> Set;
            unsigned short SetSize = Size;
            for(int i = 0; i < SetSize; i++) Set.insert( _items[i] );
            _items.assign(Set.begin(), Set.end());
            UpdateSize();
        }

        /** Returns the first element of the sequence. **/
        T First(){
            return _items[0];
        }

        bool IsEmpty(){
            return _items.empty();
        }

        /** Checks if the List contains the given item. **/
        bool Contains(T item){
            return find(_items.begin(), _items.end(), item) != _items.end();
        }

        /** Determines if all the items are equal in the List. **/
        bool All(){
            return adjacent_find(_items.begin(), _items.end(), not_equal_to<T>()) == _items.end();
        }

        /** Determines if all the items in the List are the same as the given item. **/
        bool All(T item){
            for(T val : _items){
                if(val != item) return false;
            }
            return true;
        }

        /** Takes a function that returns a bool, runs it on all items and determines if all returns true. **/
        bool All(bool (*func)(T)){
            for(T val : _items){
                if(!func(val)) return false;
            }
            return true;
        }

        /** Takes a List and returns a List of elements that exist in both of them. **/
        List<T> UNION(List<T> second){
            List<T> Union;
            for(int i = 0; i < Size; i++){
                T current = _items[i];
                for(int j = 0; j < second.GetSize(); j++){
                    if(current == second[j]) Union.Add(current);
                }
            }
            Union.RemoveDuplicates();
            return Union;
        }

        /** Returns the element at the specified index.
            Returns EMPTY (0) if the index is out of bounds. **/
        T operator[](int i){
            if(i > _items.capacity() || i < 0) return EMPTY;
            return _items[i];
        }

};
#endif // LIST_H
