/*
This is a simple program to give the student experience writing code
for binary trees.  This is a CLASS implementation of the bst ADT.
The student should study, comment, correct errors, compile,
implement/un-implemented/undeveloped functions, and modify code to make
it more efficient when ever necessary. The student should be able to
discuss the advantages and disadvantages of using such an
implementation.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "bst.h"

using namespace std;


bst::bst() : root(0) {
    string line;
    string name;
    string number;

    ifstream inFile;
    cout.setf(ios::fixed);
    cout.precision(0);

    inFile.open("county_data-6.txt");

    if (inFile.is_open()) {
        cout << " file is open" << endl;
    } else if (!inFile.is_open()) {
        cout << "could not open file" << endl;
    }
    while (getline(inFile, line)) {

          name = line.substr(0, line.find_last_of(' ')); //
        number = line.substr(line.find_last_of(' ') + 1, line.length());
        double pop = stod(number);

        insert( name, pop);


    }


}

bool bst::empty() {

    return (root == 0);
}

void bst::insert(const string &item, const double &population) {

    insert(root, item, population);
}

void bst::insert(treenode *&loc_ptr, const string &item, const double &population) {
    if (loc_ptr == 0) {
        loc_ptr = new treenode;
        loc_ptr->lchild = loc_ptr->rchild = 0;
        loc_ptr->county_name = item;
        loc_ptr->population_size = population;
    } else if (loc_ptr->county_name > item)
        insert(loc_ptr->lchild, item, population);
    else if (loc_ptr->county_name < item)
        insert(loc_ptr->rchild, item, population);
    else
        cout << "the item is already in the tree\n";
}


treenode *bst::search_tree(string item) {
    return search_tree(root, item);
}

treenode *bst::search_tree(treenode *loc_ptr, string item) {
    if (loc_ptr != 0) {
        if (loc_ptr->county_name == item)
            return loc_ptr;
        else if (loc_ptr->county_name > item)
            return search_tree(loc_ptr->lchild, item);
        else
            return search_tree(loc_ptr->rchild, item);
    } else
        return loc_ptr;
}


void bst::del_name(string item) {
    del_name(root, item);
}

void bst::del_name(treenode*& loc_ptr, string item) {
  //  search_tree(item);
    if (loc_ptr == 0) {
       // cout << loc_ptr<< endl;
        cout << "item not in tree\n";

    }
    else if
        (loc_ptr->county_name > item){
        del_name(loc_ptr->lchild, item);
    }
    else if
        (loc_ptr->county_name < item){
        del_name(loc_ptr->rchild, item);
    }
    else {
        treenode *ptr;

        if (loc_ptr->lchild == 0) {
            ptr = loc_ptr->rchild;
            delete loc_ptr;
            loc_ptr = ptr;
        } else if (loc_ptr->rchild == 0) {
            ptr = loc_ptr->lchild;
            delete loc_ptr;
            loc_ptr = ptr;
        } else {
            ptr = inorder_succ(loc_ptr);
            loc_ptr->county_name = ptr->county_name;
            del_name(loc_ptr->rchild, ptr->county_name);
        }
    }

}

treenode *bst::inorder_succ(treenode *loc_ptr) {

    treenode *ptr = loc_ptr->rchild;

    while (ptr->lchild != 0) {
        ptr = ptr->lchild;
    }
    return ptr;
}

void bst::print_tree() {
    print_tree(root);
}

void bst::print_tree(treenode *loc_ptr) {
    if (loc_ptr != 0) {
        print_tree(loc_ptr->lchild);
        cout << loc_ptr->county_name << endl;
        print_tree(loc_ptr->rchild);
    }
}


bst::~bst() {
    while (root != 0) {
        del_name(root->county_name);
    }
}

void bst::county_ranges(treenode *&loc_ptr, const string &min_name, const string &max_name) {
//cout << "printing ranges" << endl;
//clean up
    if(loc_ptr != 0){
       county_ranges(loc_ptr->lchild, min_name, max_name);

        if( loc_ptr->county_name <= max_name && loc_ptr->county_name >= min_name)
            cout << loc_ptr->county_name << endl;
        county_ranges(loc_ptr->rchild, min_name, max_name);
    }
}

void bst::county_ranges(const string &min_name, const string &max_name) {
    cout << "printing ranges" << endl;

    county_ranges(root,min_name,max_name);
}

void bst::sorted_info(ostream  & out, treenode *& loc_ptr) {
   /* ofstream outfile;
    outfile.open("county_info.txt");
    outfile.setf(ios::fixed);
    outfile.precision(0);*/
    out.setf(ios::fixed);
    out.precision(0);
    if (loc_ptr != 0) {
        sorted_info(out,loc_ptr->lchild);

        out << left << setw(20) <<   loc_ptr->county_name << right << setw(5) << loc_ptr->population_size << endl;
        sorted_info(out,loc_ptr->rchild);
    }


}

void bst::sorted_info() {
    ofstream outfile("county_info.txt");
   // outfile.open("county_info.txt");
 sorted_info(outfile,root);
}

void bst::empty_tree() {
    this->~bst();
}


/*
int main()
{
    bst B;
    //treenode *root1=0, *root2=0;
    string s;
    char ch;
    string key3;
    string key4;
    string response;
    string r1, r2;
    cout << "enter command, c=count, i=insert item,s=search tree,d=delete item,p=print tree, r = range, e=exit: ";
    cin >> ch;
    cout << endl;

    while (ch != 'e')
    {
        switch (ch)
        {
            case 'i':cout << "enter string: ";
                cin >> s;
               // B.insert(s);
                break;

            case 's':cout << "enter word to search for: ";
                cin >> s;
                if (!B.search_tree(s))
                    cout << s << "not in tree\n";
                else
                    cout << s << " was found in the tree\n";
                break;
            case 'd':cout << "enter word to delete: ";
                cin >> s;
                B.del_name(s);
                break;
            case 'p':cout << "...printing tree...\n";
                B.print_tree();
                break;

            default:break;
        }
        cout << "enter command, i=insert item,s=search tree,d=delete item,p=print tree, e=exit: ";
        cin >> ch;
        cout << endl;
    }

    cout << endl << "no more binary tree.....\n";
    return 0;
}
*/
