internal class ArrayEvenOdd{
    public static void Main(string[] args)
    {
        int[] ints = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 0; i < ints.Length; i++)
        {
            Console.WriteLine("Enter integer number " + (i+1) + ": ");
            int new_num = int.Parse(Console.ReadLine());
            ints[i] = new_num;
        }

        int even = 0;
        int odd = 0;
        for(int i = 0; i < ints.Length; i++)
        {
            if(ints[i] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        Console.WriteLine("Evens: " + even + "\nOdds: " + odd);
        
    }
}