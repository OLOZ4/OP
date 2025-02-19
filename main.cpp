#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include  <iostream>
#include  <climits>
#include <random>
#include  <string>
#include  <fstream>

using namespace std;

struct Student {
    string name;
    string surname;
    int exam;
    int mark[1000];
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
    std::uniform_int_distribution<std::mt19937::result_type> num(a,b); // distribution in range [1, 6]

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
    Student stud[1000];
    string names[2400];
    char choice;
    int counter = 0;
    
    readFile(names);

    //cout << name(names)<<endl;

    while (true) {
        cout << "\nSelect:\n1) to add a new student\n2) to process and print all students\n3) to quit\n--> ";
        cin >> choice;
        switch (choice) {
            case '1': {
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
                            
                            stud[counter].mark[stud[counter].mark_count] = stoi(input);
                            stud[counter].mark_count ++;
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
                /*for (int i = 0; i < counter; i++) {
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
                cout << endl << setw(g) << "Vardas: "<< setw(g) << "Pavardė: "<< setw(g) << "Pažymys(vid.): "<< setw(g+5) << "Pažymys(med.): " << setw(g+5)<< endl;
                cout<<"__________________________________________________________________________________"<<endl;
                for (int i = 0; i < counter; i++) {
                    cout << setw(g) << stud[i].name << setw(g) << stud[i].surname << setw(g);
                    double sum = 0;
                    for (int j = 0; j < stud[i].mark_count; j++) {
                        sum += stud[i].mark[j];
                    }

                    double med{};
                    std::sort(stud[i].mark,stud[i].mark + stud[i].mark_count);

                    if (stud[i].mark_count % 2 != 0) {
                        med = stud[i].mark[stud[i].mark_count/2];
                    }
                    else {
                        med = (stud[i].mark[(stud[i].mark_count)-1/2] + stud[i].mark[stud[i].mark_count/2]) / 2.0;
                    }
                    cout << std::setprecision(3)<< (0.4*(sum/stud[i].mark_count)+0.6*stud[i].exam) << setw(g) << std::setprecision(3) << med << endl;

                }
                break;
            }
            case '3':{
                return 0;
            }       
            //break;
            default:
                cout << "\n\nInvalid choice. Please try again.\n";
        }
    }

    return 0;
}
