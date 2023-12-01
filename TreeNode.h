//
// Created by zinka on 23.11.2023.
//
#include "iostream"
#ifndef TREELAB_TREENODE_H
#define TREELAB_TREENODE_H

class Node {
    char d;
    Node* lft;
    Node* rgt;
    int depth;
public:
    Node():lft(nullptr),rgt(nullptr){}
    ~Node(){ if(lft) delete lft; if (rgt) delete rgt;}
    friend class Tree;
};

class Tree{
    Node* root;
    int cnt=0;
    char num, maxnum;
    int maxrow,offset;
    char**SCREEN;
    void clrscr();
    Node* MakeNode(int depth);
    void OutNodes(Node* v, int r, int c);
    Tree (const Tree &);
    Tree (Tree &&);
    Tree operator = (const Tree &) const = delete;
    Tree operator = (Tree &&) const = delete;
public:
    Tree (char num,char maxnum, int maxrow);
    ~Tree();
    void MakeTree()
    {root = MakeNode(0);}
    bool exist(){return root != nullptr;}
    int DFS();
    int BFS();
    int IFS_C(Node *root);
    int IFS();
    void OutTree();
};

#endif //TREELAB_TREENODE_H
