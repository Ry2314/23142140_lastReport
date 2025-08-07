#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student_MSE {
private:
    string name;
    string grade;

public:
    Student_MSE(const string& name, const string& grade)
        : name(name), grade(grade) {}

    string getName() const {
        return name;
    }

    string getGrade() const {
        return grade;
    }

    void display() const {

        cout << "名前: " << name << '\n';
    }
};

void search_show(vector<Student_MSE> students, string search_name) {
    bool found = false;
    for (auto i = students.begin(); i != students.end(); ++i) {
        if (i->getName() == search_name) {
            cout << search_name << "さんの成績は " << i->getGrade() << " です。\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << search_name << "さんの成績は見つかりませんでした。\n";
    }
}

int main() {
    const string filename = "students_kikai.txt";

    {
        ofstream outfile(filename);
        if (!outfile) {
            cerr << "ファイルを作成できませんでした。\n";
            return 1;
        }

        outfile << "一郎 可\n";
        outfile << "二郎 良\n";
        outfile << "三郎 優\n";
        outfile << "四郎 可\n";
        outfile << "五郎 優\n";
        outfile << "六郎 良\n";
        outfile << "七郎 不可\n";
        outfile << "八郎 可\n";
        outfile << "九郎 優\n";
        outfile << "遠藤瞭汰 秀\n";

        outfile.close();
    }

    ifstream infile(filename);
    if (!infile) {
        cerr << "ファイルを開けませんでした。\n";
        return 2;
    }

    vector<Student_MSE> students;
    string name, grade;

    while (infile >> name >> grade) {
        students.emplace_back(name, grade);
    }
    infile.close();

    cout << "プログラミング演習IIの受講者:\n";
    for (const auto& student : students) {
        student.display();
    }

    cout << "成績を知りたい学生の名前を入力してください。 \n";
    string search_name;
    cin >> search_name;
    search_show(students, search_name);

    return 0;
}