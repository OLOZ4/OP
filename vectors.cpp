#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include  <iostream>
#include  <climits>
#include <random>
#include  <string>
#include  <fstream>
#include <vector>

using namespace std;

struct Student {
    string name{};
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

void readFile ( string names[]) {
    ifstream in ("vardai.txt");
    
    for (int i = 0; i < 2400; i++)
    {
        in >> names[i];
       //cout << names[i]<< endl;
    }

}

string name(string names[]) {
    
    return names[randomNumber(1, 2400)];
}

int main() {
    vector<Student> stud;
    //Student stud[1000];
    string names[2400];
    char choice;
    int counter = 0;
    //string name, username {};
    readFile(names);

    //cout << name(names)<<endl;
    
    while (true) {
        cout << "\nSelect:\n1) to add a new student\n2) to add a new student (generated marks)\n3) to add a new student (generated marks and names)\n4) to process and print all students\n5) to quit\n--> ";
        cin >> choice;
        switch (choice) {
            case '1': {
                stud.push_back(Student());
                
                bool examm = false;
                string exam_mark;
                cout << "Enter name: ";
                cin >> stud[counter].name; 
                cout << "Enter surname: ";
                cin >> stud[counter].surname;

                while (examm == false) {
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
            
            case '4': {
                
                for (int i = 0; i < counter; i++) {
                    cout <<"Name: "<< stud[i].name << endl;
                    cout <<"Surname: "<< stud[i].surname << endl;
                    cout <<"Exam mark: "<< stud[i].exam << endl;
                    for (int j = 0; j < stud[i].mark_count; j++) {
                        cout << stud[i].mark[j] << " ";
                    }
                    cout << endl;
                    
                }
                

                int g = 15;
                cout << endl << setw(g) << "Vardas: "<< setw(g) << "Pavardė: "<< setw(g) << "Pažymys(vid.): "<< setw(g+5) << "Pažymys(med.): " << setw(g+5)<< endl;
                cout<<"__________________________________________________________________________________"<<endl;
                for (int i = 0; i < counter; i++) {
                    cout << setw(g) << stud[i].name << setw(g) << stud[i].surname << setw(g);
                    double sum = 0;
                    for (int j = 0; j < stud[i].mark_count; j++) {
                        sum += stud[i].mark[j];
                    }

                    double med{};
                    std::sort(stud[i].mark.begin(), stud[i].mark.end());

                    if (stud[i].mark_count % 2 != 0) {
                        med = stud[i].mark[stud[i].mark_count/2];
                    }
                    else {
                        med = (stud[i].mark[(stud[i].mark_count-1)/2] + stud[i].mark[stud[i].mark_count/2]) / 2.0;
                    }
                    cout << std::setprecision(3)<< (0.4*(sum/stud[i].mark_count)+0.6*stud[i].exam) << setw(g) << std::setprecision(3) << med << endl;

                }
                break;
            }
            
            case '5':{
                
                return 0;
            }
            
            case '2': {
                stud.push_back(Student());
                bool examm = false;
                string exam_mark;
                cout << "Enter name: ";
                cin >> stud[counter].name;
                cout << "Enter surname: ";
                cin >> stud[counter].surname;

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
                break;
            }
            //break;
            
            case '3': {
                stud.push_back(Student());
                bool examm = false;
                string exam_mark;
                string in;
                while (true) {
                    cout << "Press 'a' to generate a name: ";
                    cin >> in;
                    if (in == "a") {
                        stud[counter].name = name(names);
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
                        stud[counter].surname = name(names);
                        cout << "Generated surame name is: "<< stud[counter].surname<<endl;
                        break;
                    }
                    else continue;
                }
                while (true) {
                    stud[counter].mark.push_back(0);
                    cout << "Press 'a' to generate exam mark: ";
                    cin >> exam_mark;
                    if (exam_mark == "a") {

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
                        
                        stud[counter].mark[stud[counter].mark_count] = randomNumber(0, 10);
                        cout << "Generated mark was: "<< stud[counter].mark[stud[counter].mark_count]<<endl;





                        //stud[counter].exam = randomNumber(0, 10);
                        //cout << "Generated exam mark was: "<< stud[counter].exam<<endl;
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

                    if (input == "q") {
                        counter++;
                        cout << counter << endl;
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
                break;
            }
            
            //break;
            default:
                cout << "\n\nInvalid choice. Please try again.\n";
        }
    }
    
    return 0;
}
