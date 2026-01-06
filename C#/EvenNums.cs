internal class EvenNums{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter a positive number: ");
        int num1 = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter a larger positive number: ");
        int num2 = int.Parse(Console.ReadLine());

        Console.WriteLine();
        for(int i = num1; i <= num2; i++)
        {
            if(i % 2 == 0)
            {
                Console.WriteLine(i);
            }
        }
    }
}