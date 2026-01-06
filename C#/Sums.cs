internal class Sums{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter a positive number: ");
        int num = int.Parse(Console.ReadLine());

        int sum = 0;
        for(int i = 0; i <= num; i++)
        {
            sum += i;
        }

        Console.WriteLine("The sum all nums(inclusive) is " + sum);
    }
}