#include "header.h"
#include <string>
#include <vector>


int main() {
    vector<string> name;
    vector<string> txtFiles;
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
6) to generate files
7) to quit
--> )";
        cin >> choice;
        switch (choice) {
            case '1': {                
                string mark;
                int exam_mark;
                Student temp_student;
                cout << "Enter name: ";
                cin >> temp_student.name;
                cout << "Enter surname: ";
                cin >> temp_student.surname;
                while (true) {
                    cout << "Enter exam mark (0-10): ";
                    cin >> mark;
                    if (isValid(mark)) {
                       temp_student.exam = std::stoi(mark) ;
                       break;
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
                    if (isValid(mark)) {
                       temp_student.mark.push_back(std::stoi(mark)) ;
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
                txtFiles.clear();
                vector<string> txtFiles = listTxtFiles();
                string filename;
                
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

                try {
                    ifstream in(filename);
                    in.exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );
                }catch(std::exception const& e){
                cout << "Klaida atidarant faila: " << e.what() << std::endl;
                break;
                }

                import_file(stud, filename);

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
                //count_marks(stud);
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
            
            case '6': {
                // kokios funkcijos turetu buti igyvendintos:
                // failu sukurimas
                // nuskaityti faila 
                // isrusiuoti faila
                // padalainti faila i dvi kategorijas
                // israsyti i du atskirus failus
                // islcearinti stud vectoriu

                const vector<int> file_size = {1000, 10000, 100000, 1000000, 10000000};
                vector<Student> nuskriaustukai, kietiakai;
                for (int i = 0; i < file_size.size(); i++) {
                    string namefile = "studentai" + std::to_string(file_size[i])+ ".txt";
                    //generate_file(file_size[i]);
                    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
                    import_file(stud,namefile);
                    sort_file(stud, namefile);
                    divide_file(stud,kietiakai,nuskriaustukai);
                    write_marks(kietiakai, "studentai_kietiakai"+std::to_string(file_size[i])+".txt");
                    write_marks(nuskriaustukai, "studentai_nuskriaustukai"+std::to_string(file_size[i])+".txt");
                    stud.clear();
                    nuskriaustukai.clear();
                    kietiakai.clear();
                    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
                    std::chrono::duration<double> diff = end-start;
                    cout << "Processing file " <<namefile<<" was successful. Took: "<< diff.count() << " s\n"<<endl;
                    cout <<"-------------------------------------------------------------------"<<endl;

                }
                
                
                
                break;
            }

            case '7': {
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