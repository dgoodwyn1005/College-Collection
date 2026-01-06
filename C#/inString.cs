internal class inString{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter a string: ");
        string s = Console.ReadLine();
        Console.WriteLine("Now enter a single character: ");
        string c = Console.ReadLine();

        if(s.Contains(c))
        {
            Console.WriteLine(c + " is in the string: " + s);
        }
        else
        {
            Console.WriteLine(c + " is NOT in the string: " + s);
        }
    }
}