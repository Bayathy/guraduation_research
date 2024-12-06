#include <iostream>
#include <string>

using namespace std;

// 学生クラスの定義
class Student
{
private:
  string name;   // 名前
  int age;       // 年齢
  int studentID; // 学籍番号（整数型）

public:
  // データをセットするメンバ関数
  void setData(string name, int age, int studentID)
  {
    this->name = name;
    this->age = age;
    this->studentID = studentID;
  }

  // データを出力するメンバ関数
  void displayData() const
  {
    cout << name << " " << age << " " << studentID << endl;
  }

  // 年齢を取得するメンバ関数
  int getAge() const
  {
    return this->age;
  }

  // 学生データを入れ替えるためのコピー演算
  void copyFrom(const Student &other)
  {
    this->name = other.name;
    this->age = other.age;
    this->studentID = other.studentID;
  }
};

// バブルソートの実装
void bubbleSort(Student students[], int size)
{
  for (int i = 0; i < size - 1; ++i)
  {
    for (int j = 0; j < size - i - 1; ++j)
    {
      if (students[j].getAge() > students[j + 1].getAge())
      {
        // 年齢が大きい場合、データを入れ替える
        Student temp(students[j]);
        temp.copyFrom(students[j]);
        students[j].copyFrom(students[j + 1]);
        students[j + 1].copyFrom(temp);
      }
    }
  }
}

int main()
{
  int NUM_STUDENTS; // 学生の人数
  cin >> NUM_STUDENTS;

  Student students[NUM_STUDENTS]; // 学生情報を格納する配列

  // データをセットするメンバ関数
  for (int i = 0; i < NUM_STUDENTS; ++i)
  {
    string name;
    int age, studentID;
    cin >> name >> age >> studentID;
    students[i].setData(name, age, studentID);
  }

  // 学生のデータをソートする
  bubbleSort(students, NUM_STUDENTS);

  // ソートした後のデータを憑依
  for (int i = 0; i < NUM_STUDENTS; i++)
  {
    students[i].displayData();
  }

  return 0;
}
