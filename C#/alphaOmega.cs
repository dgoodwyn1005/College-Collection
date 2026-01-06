internal class alphaOmega{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter a string: ");
        string s = Console.ReadLine();

        char firstLetter = s[0];
        char lastLetter = s[s.Length-1];

        if(s.StartsWith(lastLetter) && s.EndsWith(firstLetter))
        {
            Console.WriteLine("This string starts and ends with the same letter.");
        }
        else
        {
            Console.WriteLine("This string DOES NOT start and end with the same letter.");
        }
    }
}