internal class Pattern1{
    public static void Main(string[] args)
    {
        for(int i = 0;i < 4;i++)
        {
            for(int x = 0;x < 3; x++)
            {
                Console.Write("$");
                Console.Write("&");
            }
            Console.WriteLine();
        }

    }
}