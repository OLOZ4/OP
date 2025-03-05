/*
#include <algorithm>
//#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include  <iostream>
//#include  <climits>
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

bool isValid ( string number ) {
    try {
        int mark = stoi(number);
        if (mark >= 0 && mark <= 10) return true;
        else return false;
    }
    catch (const std::invalid_argument&) {
        return false;
    }    
}

bool isValid ( int number ) {
    int mark = number;
    if (mark >= 0 && mark <= 10) return true;
    else return false;
}

int randomNumber (int a, int b) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> num(a,b);
    return num(rng);
}

void readFile(vector<string>& name) {
    std::ifstream in("vardai.txt");
    if (!in.is_open()) {
        cerr << "Failed to open file." << std::endl;
        return;
    }

    while (!in.eof()) {
        string line;
        in >> line;
        name.push_back(line);
    }
}
vector <string> name;
string get_name() { 
    return name[randomNumber(1, name.size())];
}

int lineCount (string filename) {
    ifstream in (filename);
    string temp;
    int count = 0;
    while (getline(in, temp)) {
        count++;
    }
    return count;

}

void count_marks (vector<Student>& stud) {
    for (int i = 0; i < stud.size(); i++) {
        double sum = 0;
        for (int j = 0; j < stud[i].mark.size(); j++) {
        sum += stud[i].mark[j];
        }
        double med{};
        std::sort(stud[i].mark.begin(), stud[i].mark.end());
        if ((stud[i].mark.size()-1) % 2 != 0) {
            med = stud[i].mark[stud[i].mark.size()/2.0];
        }
        else {
        med = (stud[i].mark[(stud[i].mark.size()-1)/2.0] + stud[i].mark[stud[i].mark.size()/2.0]) / 2.0;
        }
        stud[i].median = 0.4*med+0.6*stud[i].exam;
        stud[i].result = 0.4*(sum/stud[i].mark.size())+0.6*stud[i].exam;
    }
}

void print_marks (vector<Student> stud) {
    int g = 15;
    cout << endl << setw(g) << left<< "Vardas: "<< setw(g) << left<< "Pavardė: "<< setw(g) << left<< "Pažymys(vid.): "<< setw(g) << left<< "Pažymys(med.): "<< endl;
     cout<<"__________________________________________________________________________________"<<endl;
    for (int i = 0; i < stud.size(); i++) {
        cout <<setw(g)<< left<< stud[i].name << setw(g)<< left<< stud[i].surname; 
        cout << setw(g) <<left<<std::setprecision(3)<< stud[i].result << setw(g)<< left << std::setprecision(3) <<  stud[i].median << endl; // kur mediana vietoj vidurkio imti mediana
    }
    cout<<endl; 
}

vector<string> listTxtFiles() {
  std::vector<std::string> txtFiles;
  for (const auto& entry : std::filesystem::directory_iterator(".")) {
    if (entry.is_regular_file() && entry.path().extension() == ".txt") {
      txtFiles.push_back(entry.path().filename().string());
    }
  }
  return txtFiles;
}
*/
#include "header.h"

int main() {
    vector <string> name;
    vector<string> txtFiles = listTxtFiles();
    vector<Student> stud;
    char choice;
    readFile(name);

    while (true) {
        cout << R"(Select:
1) to add a new student
2) to add a new student (generated marks)
3) to add a new student (generated marks and names)
4) to read from file
5) to process and print all students
6) to quit
--> )";
        cin >> choice;
        switch (choice) {
            case '1': {                
                string exam_mark, mark;
                Student temp_student;
                cout << "Enter name: ";
                cin >> temp_student.name;
                cout << "Enter surname: ";
                cin >> temp_student.surname;
                while (true) {
                    cout << "Enter exam mark (0-10): ";
                    cin >> exam_mark;
                    if (isValid(exam_mark)) {
                        temp_student.exam = std::stoi(exam_mark);
                        break;
                    }
                    else {
                        cout << "Invalid input. Please enter a valid mark." << endl;
                        continue;
                    }
                }
                while (true) {
                    cout << "Enter a mark (or 'q' to quit): ";
                    cin >> mark;

                    if (mark == "q") {
                        stud.push_back(temp_student);
                        temp_student.mark.clear();
                        break;
                    }
                    try {
                        if (isValid(mark)) {
                            temp_student.mark.push_back(std::stoi(mark));
                        }
                        else {
                            cout << "Invalid input. Please enter a valid mark." << endl;
                            continue;
                        }
                    } 
                    catch (const std::invalid_argument&) {
                        cout << "Invalid input. Please enter a valid mark." << endl;
                        continue;    
                    }
                    
                } 
                break;
            }
            
            case '2': {
                Student temp_student{};
                cout << "Enter name: ";
                cin >> temp_student.name;
                cout << "Enter surname: ";
                cin >> temp_student.surname;
                temp_student.exam = randomNumber(0, 10);
                cout << "Generated exam mark was: "<< temp_student.exam<<endl;
                for (int i = 0; i < randomNumber(3, 10); i++) {
                    temp_student.mark.push_back(randomNumber(0, 10));
                    cout << "Generated mark was: "<< temp_student.mark.back() << endl;
                }
                stud.push_back(temp_student);
                temp_student.mark.clear();
                break;
            }

            case '3': {
                Student temp_student{};
                temp_student.name = get_name(name);
                cout << "Generated name is: "<< temp_student.name <<endl;
                temp_student.surname = get_name(name);
                cout << "Generated surame name is: "<< temp_student.surname<<endl;
                temp_student.exam = randomNumber(0, 10);
                cout << "Generated exam mark was: "<< temp_student.exam<<endl;
                for (int i = 0; i < randomNumber(3, 10); i++) {
                    temp_student.mark.push_back(randomNumber(0, 10));
                    cout << "Generated mark was: "<< temp_student.mark.back() << endl;
                }
                stud.push_back(temp_student);
                temp_student.mark.clear();
                break;
            }
            case '4': {
                string filename;
                string temp;
                if (!txtFiles.empty()) {
                    system("clear");
                    cout << "Choose a .txt file to open:\n";
                    for (size_t i = 0; i < txtFiles.size(); ++i) {
                    cout << i << ") " << txtFiles[i] << "\n";
                    }
                    cout <<"--> ";
                    int choice;
                    while (true) {
                        cin >> choice;
                        if (choice >= 1 && choice <= txtFiles.size()) {
                            filename = txtFiles[choice];
                            break; 
                        } else {
                            cout << "Invalid choice, try again:\n";
                        }
                    }
                } 
                else {
                    std::cout << "No .txt files found in this directory.\n";
                }

                auto start = std::chrono::high_resolution_clock::now(); // Paleisti
                ifstream in (filename);
                int lineNum = lineCount(filename);
                getline(in, temp);
                stud.reserve(lineNum);                    
                string word;
                Student temp_student{};
                while (getline(in, temp)) {   
                    std::istringstream stream (temp);
                    while (stream) {
                        stream >> temp_student.name >> temp_student.surname;
                        while (stream) {
                            stream >> word;
                            temp_student.mark.push_back(std::stoi(word));
                        }
                        temp_student.exam = temp_student.mark.back();
                        temp_student.mark.pop_back();
                        //stud.push_back(std::move(temp_student));
                        
                        stud.push_back(temp_student);
                        temp_student.mark.clear();
                    }
                }
                    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
                    std::chrono::duration<double> diff = end-start;
                    cout << "Reading successful. Took: "<< diff.count() << " s\n"<<endl;
                    in.close();
                break;
            }
            case '5': {
                system("clear");
                /*
                for (int i = 0; i < stud.size(); i++) {
                    cout <<"Name: "<< stud[i].name << endl;
                    cout <<"Surname: "<< stud[i].surname << endl;
                    cout <<"Exam mark: "<< stud[i].exam << endl;
                    for (int j = 0; j < stud[i].mark.size(); j++) {
                        cout << stud[i].mark[j] << " ";
                    }
                    cout << endl;
                    
                }
                */
                count_marks(stud);
                cout <<"there are: "<<stud.size()<<" students"<<endl;
                 cout << R"(Sort by:
1) student name
2) student surname
3) student mark (average)
4) student mark (median)
--> )";
                char choice1;
                cin >> choice1;
                switch (choice1) {
                    case '1': {
                        std::sort(stud.begin(), stud.end(), [](const Student& a, const Student& b) {
                        
                        return (a.name) < (b.name);});
                        print_marks(stud);            
                        break;
                    }
                    case '2': {
                        std::sort(stud.begin(), stud.end(), [](const Student& a, const Student& b) {

                        return a.surname < b.surname;});
                        print_marks(stud);            
                        break;
                    }
                    case '3': {
                        std::sort(stud.begin(), stud.end(), [](const Student& a, const Student& b) {

                        return a.result < b.result;});
                        print_marks(stud);            
                        break;
                    }
                    case '4': {
                        std::sort(stud.begin(), stud.end(), [](const Student& a, const Student& b) {

                        return a.median < b.median;
                        });
                        print_marks(stud);            
                        break;
                    }
                    default: {
                        cout << "\n\nInvalid choice. Please try again.\n";
                        continue;
                    }
                }
                break;
            }

            case '6':{
                cout <<endl<< "quitting... bye" << endl;
                return 0;
            }

            default: {
                cout << "\n\nInvalid choice. Please try again.\n";
            }   
        }
    }
    return 0;
}