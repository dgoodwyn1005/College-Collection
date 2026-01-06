internal class DayOfWeek
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter a year: ");
        int y = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter a month: ");
        int m = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter a day: ");
        int d = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter a hour: ");
        int h = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter a minute: ");
        int min = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter a second: ");
        int s = int.Parse(Console.ReadLine());

        DateTime dt = new DateTime(y, m, d, h, min, s);
        Console.WriteLine("This time and date is " + dt);
        Console.WriteLine(dt.DayOfWeek + " is the day of the week");

    }
}