#include <algorithm>
//#include <cstdlib>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include  <iostream>
//#include  <climits>
#include <random>
#include  <string>
#include  <fstream>
#include <vector>

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
    string name;
    string surname{};
    int exam{};
    vector<int> mark;
    int mark_count = 0;
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

string get_name(vector<string> name) { 
    return name[randomNumber(1, name.size())];
}

int returnNumberOfHomework (string filename) {
    string s;
    int count = 0;
    ifstream in (filename);
    while (true) {
        in >> s;
        if (s == "Egz.") {
        count = count -2;
        return count;
        break;
        }
        count++;
   }
}

int main() {
    vector<Student> stud;
    //Student stud[1000];
    vector <string> name;
    //string names[2400];
    char choice;
    int counter = 0;
    //string name, username {};
    readFile(name);
    //cout <<endl<< "name: "<<  get_name(name)<<endl;
    //cout<< endl<<" size: "<<name.size();
    //for (const auto& name : name) {
        //std::cout << name << std::endl;
    //}

    //cout << name(names)<<endl;
    
    while (true) {
        //system("dir ");
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
                stud.push_back(Student());
                
                //bool examm = false;
                string exam_mark;
                cout << "Enter name: ";
                cin >> stud[counter].name; 
                cout << "Enter surname: ";
                cin >> stud[counter].surname;

                while (true) {
                    cout << "Enter exam mark (0-10): ";
                    cin >> exam_mark;
                    if (isValid(exam_mark)) {
                        stud[counter].exam = stoi(exam_mark);
                        break;
                    }
                    else {
                        cout << "Invalid input. Please enter a valid mark." << endl;
                        continue;   
                    }
                }
                while (true) {
                    int mark;
                    stud[counter].mark.push_back(0);
                    string input;
                    cout << "Enter a mark (or 'q' to quit): ";
                    cin >> input;

                    if (input == "q") {
                        counter++;
                        cout << counter << endl;
                        break;

                    }
                    try {
                        if (isValid(input)) {
                            //int* newArr = new int[stud[counter].mark_count + 1];
                            //if (stud[counter].mark != NULL) {
                                //for (int i = 0; i < stud[counter].mark_count; i++) {
                                    //newArr[i] = stud[counter].mark[i];
                                //}
                            //}
                            //delete stud[counter].mark;
                            //stud[counter].mark = newArr;

                            stud[counter].mark[stud[counter].mark_count] = stoi(input);
                            stud[counter].mark_count ++;
                            //stud[counter].mark[stud[counter].mark_count-1] = stoi(input);
                            
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
                stud.push_back(Student());
                bool examm = false;
                string exam_mark;
                cout << "Enter name: ";
                cin >> stud[counter].name;
                cout << "Enter surname: ";
                cin >> stud[counter].surname;
                stud[counter].exam = randomNumber(0, 10);
                cout << "Generated exam mark was: "<< stud[counter].exam<<endl;
                stud[counter].mark.push_back(0);
                for (int i = 0; i < randomNumber(3, 10); i++) {
                    stud[counter].mark[stud[counter].mark_count] = randomNumber(0, 10);
                    cout << "Generated mark was: "<< stud[counter].mark[stud[counter].mark_count]<<endl;
                    stud[counter].mark_count ++;
                }
                cout<<endl;
                counter++;
                /*
                while (true) {
                    cout << "Press 'a' to generate exam mark: ";
                    cin >> exam_mark;
                    if (exam_mark == "a") {
                        stud[counter].exam = randomNumber(0, 10);
                        cout << "Generated exam mark was: "<< stud[counter].exam<<endl;
                        break;
                    }
                    else {
                        cout << "Invalid input. Press 'a' to generate exam mark." << endl;
                        continue;   
                    }
                }
                while (true) {
                    stud[counter].mark.push_back(0);
                    int mark;
                    string input;
                    cout << "Press 'a' to generate a mark or 'q' to quit: ";
                    cin >> input;

                    if (input == "q") {
                        counter++;
                        //cout << counter << endl;
                        break;

                    }
                    else if (input == "a") {

                        //int* newArr = new int[stud[counter].mark_count + 1];
                        //if (stud[counter].mark != NULL) {
                            //for (int i = 0; i < stud[counter].mark_count; i++) {
                                //newArr[i] = stud[counter].mark[i];
                                //}
                        //}

                        //delete stud[counter].mark;
                        //stud[counter].mark = newArr;    
                
                        stud[counter].mark_count ++;

                        //stud[counter].mark[stud[counter].mark_count-1] = randomNumber(0, 10);
                        stud[counter].mark[stud[counter].mark_count-1] = randomNumber(0, 10);
                        cout << "Generated mark was: "<< stud[counter].mark[stud[counter].mark_count-1]<<endl;
                    }  
                    else {
                        cout << "Invalid input. Please enter 'a' or 'q'." << endl;
                        continue;
                    }   
                }
                */
                break;
            }

            case '3': {
                stud.push_back(Student());
                string exam_mark;
                string in;
                stud[counter].name = get_name(name);
                cout << "Generated name is: "<< stud[counter].name<<endl;
                stud[counter].surname = get_name(name);
                cout << "Generated surame name is: "<< stud[counter].surname<<endl;
                stud[counter].exam = randomNumber(0, 10);
                cout << "Generated exam mark was: "<< stud[counter].exam<<endl;
                stud[counter].mark.push_back(0);
                for (int i = 0; i < randomNumber(3, 10); i++) {
                    stud[counter].mark[stud[counter].mark_count] = randomNumber(0, 10);
                    cout << "Generated mark was: "<< stud[counter].mark[stud[counter].mark_count]<<endl;
                    stud[counter].mark_count ++;
                }
                cout<<endl;
                counter++;
                /*
                while (true) {
                    cout << "Press 'a' to generate a name: ";
                    cin >> in;
                    if (in == "a") {
                        stud[counter].name = get_name(name);
                        cout << "Generated name is: "<< stud[counter].name<<endl;
                        break;
                    }
                    else continue;
                }
                while (true)
                {
                    cout << "Press 'a' to generate a surname: ";
                    cin >> in;
                    if (in == "a") {
                        stud[counter].surname = get_name(name);
                        cout << "Generated surame name is: "<< stud[counter].surname<<endl;
                        break;
                    }
                    else continue;
                }
                while (true) {
                    cout << "Press 'a' to generate exam mark: ";
                    cin >> exam_mark;
                    if (exam_mark == "a") {
                        stud[counter].exam = randomNumber(0, 10);
                        cout << "Generated exam mark was: "<< stud[counter].exam<<endl;
                        break;
                    }
                    else {
                        cout << "Invalid input. Press 'a' to generate exam mark." << endl;
                        continue;   
                    }
                }
                while (true) {
                    int mark;
                    string input;
                    cout << "Pres 'a' to generate a mark or 'q' to quit: ";
                    cin >> input;
                    stud[counter].mark.push_back(0);


                    if (input == "q") {
                        counter++;
                        //cout << counter << endl;
                        break;

                    }
                    else if (input == "a") {
                        stud[counter].mark[stud[counter].mark_count] = randomNumber(0, 10);
                        cout << "Generated mark was: "<< stud[counter].mark[stud[counter].mark_count]<<endl;
                        stud[counter].mark_count ++;
                    }  
                    else {
                        cout << "Invalid input. Please enter 'a' or 'q'." << endl;
                        continue;
                    }   
                }
                */
                break;
            }
            case '4': {
                cout<< "reading from file"<<endl;
                
                cout<< "nmuber of homework: "<<returnNumberOfHomework("kursiokai.txt")<<endl;
                cout<< "nmuber of homework: "<<returnNumberOfHomework("studentai10000.txt")<<endl;
                cout<< "nmuber of homework: "<<returnNumberOfHomework("studentai100000.txt")<<endl;
                cout<< "nmuber of homework: "<<returnNumberOfHomework("studentai1000000.txt")<<endl;
                cout<<endl;
                break;
            }
            case '5': {
                /*
                for (int i = 0; i < counter; i++) {
                    cout <<"Name: "<< stud[i].name << endl;
                    cout <<"Surname: "<< stud[i].surname << endl;
                    cout <<"Exam mark: "<< stud[i].exam << endl;
                    for (int j = 0; j < stud[i].mark_count; j++) {
                        cout << stud[i].mark[j] << " ";
                    }
                    cout << endl;
                    
                }
                */

                int g = 15;
                cout << endl << setw(g) << left<< "Vardas: "<< setw(g) << left<< "Pavardė: "<< setw(g) << left<< "Pažymys(vid.): "<< setw(g) << left<< "Pažymys(med.): "<< endl;
                cout<<"__________________________________________________________________________________"<<endl;
                for (int i = 0; i < counter; i++) {
                    cout <<setw(g)<< left<< stud[i].name << setw(g)<< left<< stud[i].surname; 
                    double sum = 0;
                    for (int j = 0; j < stud[i].mark_count; j++) {
                        sum += stud[i].mark[j];
                    }

                    double med{};
                    std::sort(stud[i].mark.begin(), stud[i].mark.end());
                    //cout <<endl<<"Student mark size: "<<stud[i].mark.size()<<endl;
                    if ((stud[i].mark.size()-1) % 2 != 0) {
                        med = stud[i].mark[stud[i].mark_count/2.0];
                    }
                    else {
                        med = (stud[i].mark[(stud[i].mark_count-1)/2.0] + stud[i].mark[stud[i].mark_count/2.0]) / 2.0;
                    }
                    cout << setw(g) <<left<<std::setprecision(3)<< (0.4*(sum/stud[i].mark_count)+0.6*stud[i].exam) << setw(g)<< left << std::setprecision(3) <<  (0.4*med+0.6*stud[i].exam) << endl; // kur mediana vietoj vidurkio imti mediana
                }
                cout<<endl;             
                break;
            }
            
            case '6':{
                cout <<endl<< "quitting... bye" << endl;
                return 0;
            }
            

            //break;
            
            
            
            //break;
            default:
                cout << "\n\nInvalid choice. Please try again.\n";
        }
    }
    
    return 0;
}
