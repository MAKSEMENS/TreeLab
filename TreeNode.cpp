//
// Created by zinka on 23.11.2023.
//
#include "TreeNode.h"
#include <random>
#include "iostream"
#include "string.h"
#include "ctime"
using namespace std;

Tree::~Tree() {
    for (int i = 0; i < maxrow; ++i) {
        delete []SCREEN[i];
        delete []SCREEN;
        delete root;
    }
}

Tree :: Tree(char nm, char mnm, int mxr):
        num (nm), maxnum(mnm), maxrow(mxr), offset(40), root(nullptr), SCREEN(new char* [maxrow])
{
    for (int i = 0; i < maxrow; ++i) {SCREEN[i] = new char[80];}

}

Node * Tree ::MakeNode(int depth)
{

    srand ( time(0) );
            Node * v = nullptr;
            int Y = (depth < rand()%6+2) && (num <= 'z');
           // cout << "Node ("<<num<<','<<depth<<")1/0";cin >> Y;
            if (Y)
            {
                v = new Node;
                v->depth = depth;
                //v->d = num++;
                v->lft = MakeNode(depth+1);
                v->d = num++;
                v->rgt = MakeNode(depth+1);
            }
            return v;
}

void Tree :: OutTree()
{

    clrscr();
    OutNodes(root,1,offset);
    for (int i = 0; i < maxrow; i++)
    {
        SCREEN[i][79] = 0;
        cout << '\n'<<SCREEN[i];
    }
    cout <<'\n';
}
void Tree :: clrscr()
{
    for (int i = 0; i < maxrow; i++) memset(SCREEN[i],'.',80);
}

void Tree ::OutNodes(Node *v, int r, int c)
{

    if (r && c && (c<80)) SCREEN[r-1][c-1] = v->d;
    if (r < maxrow){
        if (v->lft) OutNodes(v->lft, r+1, c - (offset >>r));
        if (v->rgt) OutNodes(v->rgt, r+1, c + (offset >>r));
    }
}

int Tree::IFS_C(Node* root) {
        if (root != nullptr) {
            if (root->depth>1) cnt++;
            IFS_C(root->lft);
            IFS_C(root->rgt);
        }
        return cnt;
}

int Tree :: IFS(){
    return IFS_C(root);
}