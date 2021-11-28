//
// Created by VladR on 11/21/2021.
//

#ifndef ASSIGNMENT10_BST_H
#define ASSIGNMENT10_BST_H

#endif //ASSIGNMENT10_BST_H
using namespace std;

class treenode
{
public:
    string county_name;
    double population_size;
    treenode *lchild, *rchild;
};

class bst
{
public:
    bst(); //{ root = 0; }
    ~bst();
    bool empty();
    void insert(const string& item, const double& population);
    void insert(treenode*& loc_ptr, const string& item, const double& population);
    void del_name(string item);
    void del_name(treenode *& loc_ptr, string item);
    treenode * search_tree(treenode *, string item);
    treenode * search_tree(string item);
    treenode * inorder_succ(treenode *);
    void county_ranges(const string& min_name, const string& max_name); //auxiliary function.
    void county_ranges(treenode*&, const string& min_name, const string& max_name); //prints all
    //the county names to the screen that lie between min_name and max_name,
    //inclusive.

    void print_tree();
    void print_tree(treenode *);
    void sorted_info();//auxiliary function.
    void sorted_info(ostream&, treenode*&);//prints each county record to a file called
    //“county_info.txt” sorted by county name”.
    void empty_tree();//de-allocate all nodes that were allocated to the bst
private:


private:
    treenode *root;

};