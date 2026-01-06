internal class MadLabs
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter a subject: ");
        String subject = Console.ReadLine();
        Console.WriteLine("Now enter a verb: ");
        String verb = Console.ReadLine();
        Console.WriteLine("Finally enter an object: ");
        String obj = Console.ReadLine();

        String finalSentence = subject + " went outside today. They saw an interesting looking " + obj +
            ". However, they left it alone. They just want to " + verb + " all day!";

        Console.WriteLine(finalSentence);
    }
}
