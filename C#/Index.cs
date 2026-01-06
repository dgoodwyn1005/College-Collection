internal class Index{
    public static void Main(string[] args)
    {
        int[] ints = {1, 5, 83, 2, 24, 9, 63, 22};
        Console.WriteLine("Enter an index number between 0 and 7: ");
        int index = int.Parse(Console.ReadLine());

        try
        {
            Console.WriteLine("The number at index " + index + " is " + ints[index]);
        }
        catch(IndexOutOfRangeException)
        {
            Console.WriteLine("Index was not within the required range.");
        }
    }
}