
//Sample driver.  Make correction and changes as necessary
#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
using namespace std;

/********************************************************************************************

Name:Vladimir Petit-Homme	                            Z#:Z15346795
Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Petrie
Due Date: 12/05/2021	Due Time: 11:59pm
Total Points: 100 Assignment 10: Binary search Tree

Description: This assignment test the function of binary search trees.



*********************************************************************************************/

int main( )
{

    cout << "**************************************************************" << endl;
    cout << "Test1: default constuctor" << endl;

    bst  myTree;

    cout << "Print contents of bst inorder to the screen" << endl << endl;
    myTree.print_tree();
    cout << "*************End Test1*****************************************" << endl;
    cout<<endl<<endl;

    cout << "**************************************************************" << endl;
    cout << "Test2: insert" << endl;

    myTree.insert("New County", 234658);
    cout <<endl<< "Print contents of bst inorder to the screen" << endl << endl;;
    myTree.print_tree();
    cout << "*************End Test2*****************************************" << endl;
    cout << endl << endl;

    cout << "**************************************************************" << endl;
    cout << "Test3: county_ranges" << endl;
    cout << "Print contents of bst range between B and K inorder to the screen" << endl << endl;;
    myTree.county_ranges("B","K");
    cout << "*************End Test3*****************************************" << endl;
    cout << endl << endl;

    cout << "**************************************************************" << endl;
    cout<<"Test4: del_name"<<endl;

    myTree.del_name("Miami-Dade");
    cout << endl << "Print contents of bst inorder, with Miami Dade removed, to the screen" << endl << endl;;
    myTree.print_tree();
    cout << "*************End Test4*****************************************" << endl;
    cout << endl << endl;

    cout << "**************************************************************" << endl;
  cout<<"Test5: sorted_info"<<endl<<endl;
    cout << "Print contents of bst inorder to the output file, county_info.txt, with name and associated population size shown" << endl << endl;
    myTree.sorted_info();
    cout << "*************End Test5*****************************************" << endl;
    cout << endl << endl;

       cout << "**************************************************************" << endl;
       cout << "Test6: empty_tree" << endl << endl;
       myTree.empty_tree();
       cout << endl << "Print contents of an empty bst to the screen" << endl << endl;;
       myTree.print_tree();
       cout << "*************End Test6*****************************************" << endl;
       cout << endl << endl;

    return 0;
}


