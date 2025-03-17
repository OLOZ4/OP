#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <filesystem>
#include <ios>
#include <stdexcept>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::vector;
using std::ifstream;
using std::cerr;
using std::left;
using std::right;
using std::list;
using std::sort;

struct Student {
    string name{};
    string surname{};
    int exam{};
    list <int> mark{};
    double result;
    double median;
};

bool isValid ( string number );

bool isValid ( int number );

int randomNumber (int a, int b);

void readFile(vector<string>& name);

string get_name(vector <string> name);

int lineCount (string filename);

void count_marks (list<Student>& stud);

void print_marks (list<Student> stud);

void write_marks (list<Student> stud, string name);

vector<string> listTxtFiles();

void import_file (list<Student>& stud, string filename);

void generate_file (int number);

void sort_file (list<Student>& stud, string name);

void divide_file (list<Student>& stud,list<Student>& kietiakai,list<Student>& nuskriaustukai, string filename);

void sort_students (list<Student>& stud);

void print_metrics (string filename, float data, int num);

string extractNumbers(const std::string& str);

Student get(list<Student> _list, int _i);