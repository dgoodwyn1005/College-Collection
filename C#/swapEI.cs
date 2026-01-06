internal class swapEI{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter a string: ");
        string s = Console.ReadLine();

        //Step 1
        string swappedNums = s.Replace("e", "1");
        swappedNums = swappedNums.Replace("i", "2");
        string swapped = swappedNums.Replace("1", "i");
        swapped = swapped.Replace("2", "e");

        Console.WriteLine("Before swapping e & i: ");
        Console.WriteLine(s);

        Console.WriteLine("After swapping e & i: ");
        Console.WriteLine(swapped);
    }
}