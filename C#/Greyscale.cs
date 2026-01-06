internal class Greyscale
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter Red Value: ");
        int red = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter Green Value: ");
        int green = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter Blue Value: ");
        int blue = int.Parse(Console.ReadLine());

        Console.WriteLine("R: " + red + " G: " + green + " B: " + blue);
        
        int greyValue = Convert.ToInt32((0.299 * red) + (0.587 * green) + (0.114 * blue));
        Console.WriteLine("The greyscale value is " + greyValue);
    }
}

