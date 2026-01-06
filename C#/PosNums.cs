internal class PosNums{
    public static void Main(string[] args)
    {
        int sum = 0;
        while(true){
            Console.WriteLine("Enter positive number, negative to end loop: ");
            int num = int.Parse(Console.ReadLine());

            if(num >= 0)
            {
                sum += num;
            }
            else
            {
                break;
            }
        }
        Console.WriteLine("Total is: " + sum);
    }
}