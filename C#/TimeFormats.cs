internal class TimeFormats
{
    public static void Main(string[] args)
    {
        DateTime dt = DateTime.Now;

        string str1 = dt.ToString("MM/dd/yyyy"); 
        Console.WriteLine("MM/dd/yyyy - " + str1);

        string str2 = dt.ToString("dddd, MMMM dd, yyyy");
        Console.WriteLine("dddd, MMMM dd, yyyy - " + str2);

        string str3 = dt.ToString("HH:mm:ss tt");
        Console.WriteLine("HH:mm:ss tt - " + str3); 
    }
}