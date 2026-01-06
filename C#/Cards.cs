internal class Cards
{
    public static void Main(string[] args)
    {
        const int numOfCards = 52;
        int people = 8;

        int cardsPerPerson = numOfCards / people;
        int leftoverCards = numOfCards % people;

        Console.WriteLine("A standard 52 card deck with " + people + " people means each person gets "
        + cardsPerPerson + " cards.");
        Console.WriteLine("There will be " + leftoverCards + " cards left over");
    }
    
}