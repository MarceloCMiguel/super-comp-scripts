#include <iostream>
#include <vector>
#include <random>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
using namespace std;


int main(){
    ofstream input_file;
    string filename;
    cout<<"Write the inputfile (with txt)"<<endl;
    cin>> filename;
    cout<<filename;
    input_file.open(filename);
    input_file.close();
    return 0;
}