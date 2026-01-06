internal class Ticket{
    public static void Main(string[] args)
    {
        Console.WriteLine("What's your age: ");
        int age = int.Parse(Console.ReadLine());
        
        int ticketPrice = 0;

        if (age < 5)
        {
            ticketPrice = 0;
        }
        else if(age >= 5 && age < 13)
        {
            ticketPrice = 5;
        }
        else if(age >= 13 && age < 60)
        {
            ticketPrice = 10;
        }
        else{
            ticketPrice = 7;
        }

        if(ticketPrice == 0)
        {
            Console.WriteLine("Your ticket is free!");
        }
        else
        {
            Console.WriteLine("Your ticket costs $" + ticketPrice + ".");
        }
    }
}