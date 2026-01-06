internal class Pattern2{
    public static void Main(string[] args)
    {
        for(int i = 0;i < 9;i++)
        {
            for(int x = 0;x < i; x++)
            {
                Console.Write("#");
            }

            for (int y = 0; y < (2 * (8 - i)); y++)
            {
                Console.Write(" ");
            }

            for(int x = 0;x < i; x++)
            {
                Console.Write("#");
            }
            Console.WriteLine();
        }
    }
}