using System.Text;

internal class BuildingStrings
{
    public static void Main(string[] args)
    {
        StringBuilder sb = new StringBuilder("Hello");

        sb.AppendLine(" World!");
        sb.Insert(6, "Beautiful ");
        sb.Replace("World", "Universe");
        sb.Remove(16, 8);
        String fullText = (sb.ToString());
        Console.WriteLine(fullText);
    }
}
