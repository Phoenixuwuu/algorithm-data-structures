/*
id: 24006779
name: Aniq Haikal
contact: 0163906960
email: aniqhaikalsaharuddin@gmail.com
*/

#include <iostream>
using namespace std;

struct student
{
    char name[20];
    int phone;
    int id;
    string email;
};

int main()
{
    student student[5];
    for (int i = 0; i < 5; i++) {
        cout << "Name? ";
        cin >> student[i].name;
        cout << endl << "Phone number? ";
        cin >> student[i].phone;
        cout << endl << "ID? ";
        cin >> student[i].id;
        cout << endl << "Email? ";
        cin >> student[i].email;
    }

    for (int i = 0; i < 5; i++) {
        cout << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "Phone number: " << student[i].phone << endl;
        cout << "ID: " << student[i].id << endl;
        cout << "Email: " << student[i].email << endl;
    }

    return 0;
}