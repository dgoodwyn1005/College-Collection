void main() {
  Map<String,double> student = {
    "Deshawn":3.7,
    "Isaiah":1.3,
    "Kara":3.4,
    "Lebron":4.0,
    "Isyss":2.6,
    "Steph":4.0
  };

  double highest = 0;
  for(double gpa in student.values)
  {
    if(gpa > highest)
    {
      highest = gpa;
    }
  }
  print("Highest GPA is $highest");

  print("Student(s) with this GPA: ");
  for(var s in student.keys)
  {
    if(student[s] == highest){
      print(s);
    }
  }
}
