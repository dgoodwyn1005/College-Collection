internal class swapName{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter first name and last name: ");
        string name = Console.ReadLine();

        int spaceIndex = name.IndexOf(" ");

        string fName = name.Substring(0, spaceIndex);
        string lName = name.Substring(spaceIndex + 1);

        Console.WriteLine(lName + " " + fName);
                
    }
}