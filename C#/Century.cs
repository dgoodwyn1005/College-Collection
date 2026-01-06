internal class Century
{
    public static void Main(string[] args)
    {
        //Must be 20th or 21st Century
        DateTime dt = new DateTime(1999, 3, 16); //Year, Month, Day

        Console.WriteLine("The date and time is " + dt);

        DateTime century = new DateTime(2001, 1, 1); //Beginning of 21st Century

        if(dt >= century)
        {
            Console.WriteLine("This is in the 21st century");
        }
        else
        {
            Console.WriteLine("This is in the 20st century");
        }
    }
}