using System.Globalization;

internal class FloatFormats
{
    public static void Main(string[] args)
    {
        CultureInfo.CurrentCulture = CultureInfo.CreateSpecificCulture("en-US");
        Console.WriteLine("Enter a floating point number: ");
        float f = float.Parse(Console.ReadLine());

        Console.WriteLine($"Two Decimals: {f:F2}");
        Console.WriteLine($"Percentage: {f:F2}%");
        Console.WriteLine($"Currency: {f:C}");
    }
}