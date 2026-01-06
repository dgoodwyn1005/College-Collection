internal class TenMins
{   
    public static void Main(string[] args)
    {
        DateTime dt1 = new DateTime(1999, 3, 16, 8, 32, 15); //Year, Month, Day, Hour, Mins, Secs

        Console.WriteLine("The time is " + dt1);
        DateTime tenMinsEarly = dt1.AddMinutes(-10);

        Console.WriteLine("Ten mins earlier is " + tenMinsEarly);
        Console.WriteLine();

        DateTime dt2 = new DateTime(1000, 1, 1, 0, 0, 0); //Start of New Year

        Console.WriteLine("The time is " + dt2);
        DateTime previousYear = dt2.AddMinutes(-10);

        Console.WriteLine("Ten mins earlier is " + previousYear);
        Console.WriteLine();

        DateTime dt3 = new DateTime(1784, 8, 1, 0, 0, 0); //Start of New Month

        Console.WriteLine("The time is " + dt3);
        DateTime previousMonth = dt3.AddMinutes(-10);

        Console.WriteLine("Ten mins earlier is " + previousMonth);
        Console.WriteLine();

        DateTime dt4 = new DateTime(1933, 6, 22, 0, 0, 0); //Start of New Day

        Console.WriteLine("The time is " + dt4);
        DateTime previousDay = dt4.AddMinutes(-10);

        Console.WriteLine("Ten mins earlier is " + previousDay);
    }
}