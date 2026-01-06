internal class Interpolation
{
    public static void Main(string[] args)
    {
        Console.WriteLine("What is your name?: ");
        String name = Console.ReadLine();
        Console.WriteLine("And how old are you?: ");
        int age = int.Parse(Console.ReadLine());

        Console.WriteLine($"So your name is {name} and you are {age} years old. Nice!");
    }
}