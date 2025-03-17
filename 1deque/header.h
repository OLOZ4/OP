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
#include <deque>

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
using std::deque;

struct Student {
    string name{};
    string surname{};
    int exam{};
    deque <int> mark{};
    double result;
    double median;
};

bool isValid ( string number );

bool isValid ( int number );

int randomNumber (int a, int b);

void readFile(vector <string>& name);

string get_name(vector <string> name);

int lineCount (string filename);

void count_marks (deque<Student>& stud);

void print_marks (deque<Student> stud);

void write_marks (deque<Student> stud, string name);

vector<string> listTxtFiles();

void import_file (deque<Student>& stud, string filename);

void generate_file (int number);

void sort_file (deque<Student>& stud, string name);

void divide_file (deque<Student>& stud,deque<Student>& kietiakai,deque<Student>& nuskriaustukai, string filename);

void sort_students (deque<Student>& stud);

void print_metrics (string filename, float data, int num);

string extractNumbers(const std::string& str);