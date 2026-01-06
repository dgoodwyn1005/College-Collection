internal class SqrtRt{
    public static void Main(string[] args)
    {
        try
        {
            Console.Write("Enter an integer: ");
            string input = Console.ReadLine();
            double number = double.Parse(input);

            if (number < 0)
            {
                throw new ArgumentOutOfRangeException("number", "Cannot get the square root of a negative number.");
            }

            double result = Math.Sqrt(number);
            Console.WriteLine($"The square root of {number} is {result}");
        }
        catch (FormatException)
        {
            Console.WriteLine("Input must be a number.");
        }
        catch (ArgumentOutOfRangeException)
        {
            Console.WriteLine("Cannot take the square root of a negative number.");
        }
    }
}