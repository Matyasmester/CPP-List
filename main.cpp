#include <iostream>
#include "List.h"

using namespace std;

void Print(char val){
    cout << val << endl;
}

int main()
{
    vector<char> arr = {'a', 'b', 'c', 'f', 'g', 'h', 'i', 'j', 'k', 'a', 'b', 'c', 'f', 'g', 'h', 'i', 'j', 'k', '4', '8', '9'};
    List<char>* MyList = new List<char>();
    MyList->Add('d');
    MyList->Add('e');
    MyList->Add(arr);
    MyList->Add('2');

    int Size = MyList->GetSize();
    char First = MyList->First();
    int At = 6;
    char Elem = MyList->ElementAt(At);

    cout << "First element: " << First << endl;
    cout << "Removing element at: " << At << ", which is: " << Elem << endl;
    MyList->Remove(At);
    cout << "New element at " << At << ": " << MyList->ElementAt(At) << endl;
    cout << "Contains e: " << MyList->Contains('e') << endl;
    cout << "Last index of j: " << MyList->LastIndexOf('j') << endl;
    MyList->RemoveAll('a');
    cout << "Contains a: " << MyList->Contains('a') << endl;
    cout << "Are all the items c? : " << MyList->All('c')<< endl;
    cout << "Count of j: " << MyList->Count('j')<< endl;
    cout << "Size: " << Size << endl;
    MyList->ForEach(Print);

    delete MyList;

    return 0;
}
