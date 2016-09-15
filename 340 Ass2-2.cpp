#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;
/*function to merge two files, takes in two arguments of reference to to file
streams. if one file is empty, writes entierty of other file to new file*/
void merge(ifstream &file1, ifstream &file2){
	string str3 = "NewFile.txt";//creates new file name
	ofstream file3 (str3.c_str());//new file output stream
	int x;//initialize comparison variables
	int y;
	file1 >> x;
	file2 >> y;
	while(!file1.eof() && !file2.eof()){//while file is not finished
		if(x < y){//if x = y, it will write y to new file, then x if x
		//is ess than next number in second file
			file3 << x << '\n';
			file1 >> x;
		}else{
			file3 << y << '\n';
			file2 >> y;
		}
	//used for when one file is shorter than the other
	}while(!file1.eof()){//if file two is done, and file one isnt, write all of 
						//file one to new file
		file3 << x << '\n';
		file1 >> x;
	}while(!file2.eof()){//same as above but for file2
		file3 << y << '\n';
		file2 >> y;
	}cout << "Your file is now called " << str3 << "." << endl;
}

int main(){
	string str1;//strings initialized for user input of file names
	string str2;
	bool foo1 = true;
	while(foo1){//check for correct file name in working directory
		cout << "Please enter the name of your first file: " << endl;
		cin >> str1;
		ifstream file1 (str1.c_str());
		cout << "Please enter the name of your second file: " << endl;
		cin >> str2;
		ifstream file2 (str2.c_str());
		if(file1.is_open() && file2.is_open()){
			merge(file1, file2);
			foo1 = false;
			break;
		}else if (!file1.is_open()){
			cout << "Unable to open first file. please try again" << endl;
			file1.close();
			file2.close();
		}else{
			cout << "Unable to open second file. please try again" << endl;
			file1.close();
			file2.close();
		}
		}
		return 0;
	}

