internal class RemoveDupes{
    public static void Main(string[] args)
    {

        int[] ints = {11, 105, 77, 2, 105, 97, 9, 9, 28, 5};
        int[] removed_dupes = new int[10];
        int uniqueCount = 0;

        for (int i = 0; i < ints.Length; i++)
        {
            bool duplicate = false;

            for (int j = 0; j < uniqueCount; j++)
            {
                if (ints[i] == removed_dupes[j])
                {
                    duplicate = true;
                    break;
                }
            }

            if (!duplicate)
            {
                removed_dupes[uniqueCount] = ints[i];
                uniqueCount++;
            }
        }

        Console.WriteLine("With Duplicates:");        
        for (int i = 0; i < ints.Length; i++)
        {
            Console.Write(ints[i] + " ");
        }
        
        Console.WriteLine();

        Console.WriteLine("Removed Duplicates:");
        for (int i = 0; i < uniqueCount; i++)
        {
            Console.Write(removed_dupes[i] + " ");
        }
        
    }
}