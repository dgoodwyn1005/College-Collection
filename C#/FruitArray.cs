internal class FruitArray{
    public static void Main(string[] args)
    {
        string[] fruits = {"apple", "banana", "cherry"};
        Console.WriteLine("Enter a fruit name: ");
        string chosen_fruit = Console.ReadLine().ToLower();

        bool inArray = Array.Exists(fruits, n => n == chosen_fruit);

        if(inArray)
        {
            Console.WriteLine("Yes, we have that!");
        }
        else
        {
            Console.WriteLine("Sorry, not available.");
            Console.Write("But these are: ");
            Array.ForEach(fruits, n => Console.WriteLine(n));
        }

    }
}