#include "header.h"

bool isValid ( string number ) {
    try {
        int mark = stoi(number);
        if (mark >= 0 && mark <= 10) return true;
        else return false;
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
    //-----------------------Writing-to-file-----------------------
    std::ofstream out ("output.txt");
    out << endl << setw(g) << left<< "Vardas: "<< setw(g) << left<< "Pavardė: "<< setw(g) << left<< "Pažymys(vid.): "<< setw(g) << left<< "Pažymys(med.): "<< endl;
     out<<"__________________________________________________________________________________"<<endl;
    for (int i = 0; i < stud.size(); i++) {
        out <<setw(g)<< left<< stud[i].name << setw(g)<< left<< stud[i].surname; 
        out << setw(g) <<left<<std::setprecision(3)<< stud[i].result << setw(g)<< left << std::setprecision(3) <<  stud[i].median << endl; // kur mediana vietoj vidurkio imti mediana
    }
    out.close();
    //-------------------------------------------------------------



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
