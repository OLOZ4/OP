#include "header.h"

bool isValid ( string number ) {
    try {
        int mark = stoi(number);
        if (mark >= 0 && mark <= 10) return true;
        else {
            cout <<"Klaida, iveskite teisinga pazymi! "<<endl;       
            return false;
        } 
    }
    catch (const std::invalid_argument&) {
        cout <<"Klaida, iveskite teisinga pazymi! "<<endl;
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
    std::ifstream in("../vardai.txt");
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
string get_name(vector <string> name) { 
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

void count_marks (list<Student>& stud) {
    for (auto student_it = stud.begin(); student_it != stud.end(); ++student_it) {
        double sum = 0;
        for (auto mark_it = student_it->mark.begin(); mark_it != student_it->mark.end(); ++mark_it) {
            sum += *mark_it;
        }
        double med{};
        student_it->mark.sort();
        auto mark_size = student_it->mark.size();

        if ((mark_size - 1) % 2 != 0) {
            auto med_it = std::next(student_it->mark.begin(), mark_size / 2.0);
            med = *med_it;
        } else {
            auto med_it1 = std::next(student_it->mark.begin(), (mark_size - 1) / 2.0);
            auto med_it2 = std::next(student_it->mark.begin(), mark_size / 2.0);
            med = (*med_it1 + *med_it2) / 2.0;
        }

        student_it->median = 0.4 * med + 0.6 * student_it->exam;
        student_it->result = 0.4 * (sum / mark_size) + 0.6 * student_it->exam;
    }
}

void print_marks(const list<Student> stud) {
    int g = 15;
    std::cout << std::endl << std::setw(g) << std::left << "Vardas: " << std::setw(g) << std::left << "Pavardė: " << std::setw(g) << std::left << "Pažymys(vid.): " << std::setw(g) << std::left << "Pažymys(med.): " << std::endl;
    std::cout << "__________________________________________________________________________________" << std::endl;
    for (auto it = stud.begin(); it != stud.end(); ++it) {
        std::cout << std::setw(g) << std::left << it->name << std::setw(g) << std::left << it->surname;
        std::cout << std::setw(g) << std::left << std::setprecision(3) << it->result << std::setw(g) << std::left << std::setprecision(3) << it->median << std::endl;
    }
    std::cout << std::endl;
    //-----------------------Writing-to-file-----------------------
    write_marks(stud, "output.txt");
    //-------------------------------------------------------------
}

void write_marks (list<Student> stud, string name) {

    int g = 15;
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    std::ofstream out (name);
    out << setw(g) << left<< "Vardas: "<< setw(g) << left<< "Pavardė: "<< setw(g) << left<< "Pažymys(vid.): "<< setw(g) << left<< "Pažymys(med.): "<< endl;
    out<<"__________________________________________________________________________________"<<endl;
    for (auto it = stud.begin(); it != stud.end(); ++it) {
        out <<setw(g)<< left<< it->name << setw(g)<< left<< it->surname; 
        out << setw(g) <<left<<std::setprecision(3)<< it->result << setw(g)<< left << std::setprecision(3) <<  it->median << endl; // kur mediana vietoj vidurkio imti mediana
    }
    out.close();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    cout << "Writing file " <<name<<" was successful. Took: "<< diff.count() << " s"<<endl;
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

void import_file (list<Student>& stud, string filename) {

    string temp;
    ifstream in(filename);
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    int lineNum = lineCount(filename);
    getline(in, temp);
    //stud.reserve(lineNum);                    
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
        count_marks(stud);
        auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
        std::chrono::duration<double> diff = end-start;
        cout << "Importing file " <<filename<<" was successful. Took: "<< diff.count() << " s"<<endl;
        //print_metrics(filename, diff.count(), 0);
        in.close();
        
}

void generate_file (int number) {

    int g = 15;
    int counter = 0;
    int mark_count = randomNumber(2, 10);

    auto start = std::chrono::high_resolution_clock::now(); // Paleisti

    string namefile = "studentai" + std::to_string(number) + ".txt";
    std::ofstream out (namefile );
    out  << setw(g) << left<< "Vardas"<< setw(g) << right<< "Pavardė";
    for (int i = 1; i < mark_count+1; i++) {
        out << setw(g) << right<< "ND";
        out <<i;  
    }
    out << setw(g) << right<< "Egz."<<endl;

    for (int j = 0; j < number; j++) {
        out <<"Vardas";
        out <<  setw(g) <<left << j;
        out << "Pavarde";
        out  <<  setw(g) <<left << j;
        for (int z = 0; z < mark_count+1; z++) {
            out << setw(g) << left << randomNumber(0,10);
        }
        out << endl;
    }
    out.close();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    cout << "Generating file "<<namefile<<" was successful. Took: "<< diff.count() << " s"<<endl;
    std::ofstream outt;
    outt.open("data.txt", std::fstream::app);
    outt << namefile << " "<<diff.count()<<endl;
    outt.close();
}

void sort_file (list<Student>& stud, string name) {
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    stud.sort([](const Student& a, const Student& b) {return a.result > b.result;});
    
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    cout << "Sorting file "<<name<<" was successful. Took: "<< diff.count() << " s"<<endl;
    //print_metrics(name, diff.count(), 0);
}
/*
// tikrai galima geriau, bet kaip? kazakda reikes pasidometi.
void divide_file (list<Student>& stud,list<Student>& nuskriaustukai, string filename) {
    string name = "studentai" + std::to_string(stud.size()) + ".txt";
    auto start = std::chrono::high_resolution_clock::now(); // Paleisti
    //nuskriaustukai.reserve(stud.size());
    //kietiakai.reserve(stud.size());
    
    while (stud.back().result < 5.00) {
        nuskriaustukai.push_back(stud.back());
        stud.pop_back();
    }
    
    while (stud.size() != 0) {
        nuskriaustukai.push_back(stud.back());
        stud.pop_back();
    }
    
    //nuskriaustukai = stud;
    //nuskriaustukai.shrink_to_fit();
    //kietiakai.shrink_to_fit();
    auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
    std::chrono::duration<double> diff = end-start;
    cout << "Dividing file "<<name<<" was successful. Took: "<< diff.count() << " s"<<endl;
    print_metrics(filename, diff.count(), 0);
}*/

void divide_file(list<Student>& stud, list<Student>& nuskriaustukai, string filename) {
    auto start = std::chrono::high_resolution_clock::now();

    // Partition the students based on the result
    auto it = std::partition(stud.begin(), stud.end(), [](const Student& s) { return s.result >= 5.0; });

    // Move the failing students to nuskriaustukai
    nuskriaustukai.insert(nuskriaustukai.end(), std::make_move_iterator(it), std::make_move_iterator(stud.end()));
    stud.erase(it, stud.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Dividing file " << filename << " was successful. Took: " << diff.count() << " s" << std::endl;
    //print_metrics(filename, diff.count(), 0);
}


void sort_students (list<Student>& stud) {
    cout <<"There are: "<<stud.size()<<" Students"<<endl;
    cout << R"(Sort by:
1) student name
2) student surname
3) student mark (average)
4) student mark (median)
--> )";
    char choice1;
    while (true) {
    cin >> choice1;
    switch (choice1) {
        
            case '1': {
                stud.sort([](const Student& a, const Student& b) {
                
                return (a.name) < (b.name);});
                //print_marks(stud);            
                return;
            }
            case '2': {
                stud.sort([](const Student& a, const Student& b) {

                return a.surname < b.surname;});
                //print_marks(stud);            
                return;
            }
            case '3': {
                stud.sort([](const Student& a, const Student& b) {

                return a.result < b.result;});
                //print_marks(stud);            
                return;
            }
            case '4': {
                stud.sort([](const Student& a, const Student& b) {

                return a.median < b.median;});
                //print_marks(stud);            
                return;
            }
            default: {
                cout << "\n\nInvalid choice. Please try again.\n--> ";
                continue;
            }
            break;   
        }
        
    }
}

void print_metrics (string filename, float data, int num) {
    string const type = "list";
    std::ofstream out;

    std::string command = "mkdir -p data";
    system(command.c_str());
    string name = "data/"+extractNumbers(filename)+"."+type+".txt";
    
    out.open(name, std::fstream::app);
    //out<<"container type: "<<type<<endl;
    out <<"|" <<data;
    if (num == 1) out <<"|"<< endl;
}

string extractNumbers(const std::string& str) {
    std::string result;
    for (char ch : str) {
        if (std::isdigit(ch)) {
            result += ch;
        }
    }
    return result;
}

