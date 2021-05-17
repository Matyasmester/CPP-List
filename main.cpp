#include <iostream>
#include "List.h"

using namespace std;

void Print(char val){
    cout << val << " ";
}

int main()
{
    vector<char> arr = {'a', 'b', 'c', 'f', 'g', 'h', 'i', 'j', 'k', 'a', 'b', 'c', 'f', 'g', 'h', 'i', 'j', 'k', '4', '8', '9'};
    List<char> MyList;
    MyList.Add('d');
    MyList.Add('e');
    MyList.Add(arr);
    MyList.Add('2');

    int Size = MyList.GetSize();
    char First = MyList.First();
    int At = 6;
    char Elem = MyList[At];

    cout << "First element: " << First << endl;
    cout << "Removing element at: " << At << ", which is: " << Elem << endl;
    MyList.Remove(At);
    cout << "New element at " << At << ": " << MyList[At] << endl;
    cout << "Contains e: " << MyList.Contains('e') << endl;
    cout << "Last index of j: " << MyList.LastIndexOf('j') << endl;
    MyList.RemoveAll('a');
    cout << "Contains a: " << MyList.Contains('a') << endl;
    cout << "Are all the items c? : " << MyList.All('c')<< endl;
    cout << "Are all items equal to each other? " << MyList.All()<< endl;
    cout << "Count of j: " << MyList.Count('j')<< endl;
    MyList.ForEach(Print);
    cout << endl;
    cout << "Size: " << Size << endl;
    cout << "Removing duplicates." << endl;
    MyList.RemoveDuplicates();
    cout << "Size: " << MyList.GetSize() << endl;

    List<char> AnotherList;
    AnotherList.Add(arr);
    List<char> UNION = MyList.UNION(AnotherList);
    cout << "Union of two lists:" << endl;
    UNION.ForEach(Print);

    delete &MyList;

    return 0;
}
