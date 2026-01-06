internal class Grading{

    public static void Main(string[] args)
    {
        Console.WriteLine("What score did you get on the test? 1-100");
        int score = int.Parse(Console.ReadLine());
        int minimumScore = 60;

        if (score >= minimumScore)
        {
            Console.WriteLine("You passed!");
        }
        else
        {
            Console.WriteLine("You failed, dummy.");
        }
    }

}
