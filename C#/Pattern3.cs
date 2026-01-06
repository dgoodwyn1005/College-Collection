internal class Pattern3{
    public static void Main(string[] args)
    {
        for (int i = 0; i < 7; i++)
        {
            for (int x = 0; x < 7 - i; x++)
            {
                Console.Write("@");
            }
            for (int x = 0; x <= i; x++)
            {
                Console.Write("%");
            }

            Console.WriteLine();
        }

        for (int i = 7 - 2; i >= 0; i--)
        {
            for (int x = 0; x < 7 - i; x++)
            {
                Console.Write("@");
            }
            for (int x = 0; x <= i; x++)
            {
                Console.Write("%");
            }
            
            Console.WriteLine();
        }
    }
}