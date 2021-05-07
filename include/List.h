#include <vector>
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
            First checks if the vector fits, and if it doesn't, it doubles the capacity of the List. **/
        void Add(vector<T> toAdd){
            unsigned short ArraySize = toAdd.size();
            unsigned short ItemCount = Size;

            unsigned short maxitems = _items.capacity();
            unsigned short totalsize = ItemCount + ArraySize;

            if(totalsize > maxitems){
                _items.reserve(maxitems * 2);
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

        /** Returns the first element of the sequence. **/
        T First(){
            return _items[0];
        }

        /** Returns the element at the specified index.
            Returns EMPTY (0) if the index is out of bounds. **/
        T ElementAt(int i){
            if(i > _items.capacity() || i < 0) return EMPTY;
            return _items[i];
        }

        bool IsEmpty(){
            return _items.empty();
        }

        /** Checks if the given item's index is -1. If so, it returns false, otherwise true. **/
        bool Contains(T item){
            if(IndexOf(item) == -1) return false;
            return true;
        }

        /** Determines if all the items in the List are the same as the given item. **/
        bool All(T item){
            for(T val : _items){
                if(val != item) return false;
            }
            return true;
        }

};
#endif // LIST_H
