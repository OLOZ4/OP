#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include  <iostream>
#include <random>
#include <sstream>
#include  <string>
#include  <fstream>
#include <vector>
#include <chrono>
#include <filesystem>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::vector;
using std::ifstream;
using std::cerr;
using std::left;

struct Student {
    string name{};
    string surname{};
    int exam{};
    vector<int> mark{};
    double result;
    double median;
};



bool isValid ( string number );

bool isValid ( int number );

int randomNumber (int a, int b);

void readFile(vector<string>& name);

string get_name(vector <string> name);

int lineCount (string filename);

void count_marks (vector<Student>& stud);

void print_marks (vector<Student> stud);

vector<string> listTxtFiles();