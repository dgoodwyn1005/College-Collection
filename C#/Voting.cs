internal class Voting{
    public static void Main(string[] args)
    {
        Console.WriteLine("What's the legal voting age in your country? ");
        int maxAge = int.Parse(Console.ReadLine());
        Console.WriteLine("Now enter your age: ");
        int age = int.Parse(Console.ReadLine());

        if (age >= maxAge)
        {
            Console.WriteLine("You can legally vote!");
        }
        else
        {
            Console.WriteLine("You are too young to vote.");
        }
    }

}
