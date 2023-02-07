#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include"showdata.h"
#include"catagorical.h"
#include"iris_logistic.h"

using namespace std;

void display()
{
	cout<<"HELLO! WELCOME TO SPL_01\n"<<endl;
}

int main()
{

display();

 int pre1=1;
 int pre2=2;

 int button ;

 cout<<"1.SIMPLE LINEAR REGRESSION"<<endl;
 cout<<"2.LOGISTIC LINEAR REGRESSION\n"<<endl;

 cout<<"which type of regression do you want to handle?\n"<<endl;

cout<<"please enter your button"<<endl;
 cin>>button;


    if(button ==1)
    {

        cout<<"welcome to simple linear regression task"<<endl;
        cout<<"Do you want to test any dataset containing numerical value given by user?"<<endl;
        cout<<"Press 1 to continue :"<<endl;
        cout<<"Press 0 to exit program:"<<endl;

        int press2;
        cin>>press2;


        if (press2==1)
        {
 func1();
        }
        else if(press2==0)
            exit(0);
    }


     if(button==3)
    {
cout<<"ok then lets go for logistic regression "<<endl;
int press4;
cin>>press4;

if(press4==1)
{
    func3();
    test();
}
else if(press4==0)
    exit(0);
    }
}
