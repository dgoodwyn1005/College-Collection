internal class PiSeries{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter number of terms to include in computations: ");
        int computations = int.Parse(Console.ReadLine());

        int looped = 0;
        double pi = 0.0;
        int sign = 1;
        int bottomNum = 1;
        do{
            pi += sign * (1.0 / bottomNum);
            bottomNum += 2;
            sign *= -1;
            looped++;

        }while(looped < computations);

        pi *= 4; // Multiply by 4

        Console.WriteLine(pi);
    }
}