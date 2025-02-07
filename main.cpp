#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;

struct mok{
    string vard = "vardas";
    string pavarde = "pavarde";
    int* nd;
    int egz = 10;
};

int main() {
    int a, b, c, d;

    cout << "Kiek bus studentų?: ";
    cin >> a;

    while (a < 0) 
    {
        cout << "Tai turi buti teigiamas skaičius!"<<endl;
        cout << "Kiek bus studentų?: ";
        cin >> a;
    }

    cout << "Kiek studentai tures namų darbų: ";
    cin >> b;

    while (b < 0) 
    {
        cout << "Tai turi buti teigiamas skaičius!"<<endl;
        cout << "Kiek studentai turės namu darbų: ";
        cin >> b;
    }

    mok students[a];
    

    for (int i = 0; i < a; ++i) 
    {
        students[i].nd = new int [b];

        cout << endl << "Studento " << (i + 1) << " vardas: ";
        cin >> students[i].vard;

        while (students[i].vard == "")
        {
            cout << endl << "Studento " << (i + 1) << " vardas: ";
            cin >> students[i].vard;
        }

        cout << endl << "Studento " << (i + 1) << " pavardė: ";
        cin >> students[i].pavarde;

        while (students[i].pavarde == "") 
        {
            cout << endl << "Studento " << (i + 1) << " pavardė: ";
            cin >> students[i].pavarde;
        }

        cout << endl << "Studento " << (i + 1) << " egzamino pažymys: ";
        cin >> c;
        while (c < 0 || c > 10)
        {
            cout << "Tai turi buti skaičius tarp 0 ir 10";
            cout << endl << "Studento " << (i + 1) << " egzamino pažymys: ";
            cin >> c;
        }
         
        c = students[i].egz;


        for (int j = 0; j < b; ++j) 
        {
            cout << endl << "Studento " << (i + 1) << " " << (j + 1) << " pažymys už namų darbus: ";
            cin >> d;
            while (d < 0 || d > 10)
            {
                cout << "Tai turi buti skaičius tarp 0 ir 10"<< endl;
                cout << endl << "Studento " << (i + 1) << " " << (j + 1) << " pažymys už namų darbus: ";
                cin >> d;
            }
            students[i].nd[j] = d;
        }

    }
int g = 15;

    cout << endl << setw(g) << "Vardas: "<< setw(g) << "Pavardė: "<< setw(g) << "Pažymys(vid.): "<< setw(g+5) << "Pažymys(med.): " << setw(g+5)<< endl;
    cout<<"__________________________________________________________________________________"<<endl;
    for (int i = 0; i < a; i++)
    {
        cout << setw(g) << students[i].vard << setw(g) << students[i].pavarde << setw(g);
        double sum = 0;
        for (int j = 0; j < b; j++)
        {
            sum = sum + students[i].nd[j]; 
        }

        double med{};
        std::sort(students[i].nd,students[i].nd + b);
        //cout << endl;
        //for (int g = 0; g < b; g++)
          //  {
            //    cout <<students[i].nd[g]<<endl;
           // }

        if (b % 2 != 0)
        {
            med = students[i].nd[b/2];
            //cout <<endl << "b nelyginis: "<<b/2<< endl;
            
        }
        else 
        {
            med = (students[i].nd[(b-1)/2] + students[i].nd[b/2]) / 2.0;
            //cout << "b lyginis"<<endl;        
        }
    
        cout << std::setprecision(3)<< (0.4*(sum/b)+0.6*students[i].egz) << setw(g) << std::setprecision(3) << med << endl;

    }
    return 0;
}
