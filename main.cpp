#include <iostream>
#include "TreeNode.h"
#include "ctime"
#include <windows.h>

using namespace std;


int main() {
    srand(time(0));
    SetConsoleCP(1251);
    Tree tree('a','j',10);
    tree.MakeTree();
    tree.OutTree();
    cout<<"Внутренний обход: ";
    int count = tree.IFS();
    cout<<endl<<"Количество узлов на глубине больше 2х:";

    cout<<count;
}
