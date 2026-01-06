internal class CoffeeMachine{
    public static void Main(string[] args)
    {
        //Menu
        Console.WriteLine("Welcome to the greatest coffee machine in the world!");
        Console.WriteLine("Enter # to make a selection-");
        Console.WriteLine("1: Espresso");
        Console.WriteLine("2: Cappuccino");
        Console.WriteLine("3: Latte");
        Console.WriteLine("4: Exit");

        int option = int.Parse(Console.ReadLine());
        
        switch(option)
        {
        case 1:
                Console.WriteLine("Here's your fresh Espresso!");
            break;
        case 2:
                Console.WriteLine("Here's your fresh Cappuccino!");
            break;
        case 3:
                Console.WriteLine("Here's your fresh Latte!");
            break;
        case 4:
                Console.WriteLine("See you next time!");
            break;
        default:
            Console.WriteLine("Invalid Choice. Try again next time");
            break;
        }
    }

}