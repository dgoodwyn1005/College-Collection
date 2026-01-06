internal class Absences{
    public static void Main(string[] args)
    {
        string[] enrolled_students = {"Deshawn", "Rob", "Bibble"};
        int totalClasses = 10;

        int[,] absences = new int[enrolled_students.Length, totalClasses];

        for(int i = 0; i < totalClasses; i++)
        {
            Console.WriteLine("Which student(s) missed class " + (i + 1));
            Console.WriteLine("Enter next to move to next class");
            while(true){
                string input = Console.ReadLine();

                if (input.ToLower() == "next") break;

                bool inArray = Array.Exists(enrolled_students, n => n.ToLower() == input.ToLower());

                if (inArray)
                {
                    // Find index to mark absent
                    for (int x = 0; x < enrolled_students.Length; x++)
                    {
                        if (enrolled_students[x].ToLower() == input.ToLower())
                        {
                            absences[x, i] = 1;
                            break;
                        }
                    }
                }
                else
                {
                    Console.WriteLine("Student does not exist. Try again");
                }
            }
        }

        Console.WriteLine("Enter name of student: ");
        string student_name = Console.ReadLine();

        bool found = Array.Exists(enrolled_students, n => n.ToLower() == student_name);

        if (!found)
        {
            Console.WriteLine("Student not found.");
        }
        else
        {
            // Get student index
            int index = -1;
            for (int i = 0; i < enrolled_students.Length; i++)
            {
                if (enrolled_students[i].ToLower() == student_name);
                {
                    index = i;
                    break;
                }
            }

            Console.WriteLine($"{enrolled_students[index]} missed these classes:");
            bool missed = false;

            for (int j = 0; j < totalClasses; j++)
            {
                if (absences[index, j] == 1)
                {
                    Console.WriteLine($"- Class {j + 1}");
                    missed = true;
                }
            }

            if (!missed)
            {
                Console.WriteLine("No classes were missed");
            }
        }
    }
}