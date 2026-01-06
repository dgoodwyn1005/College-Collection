internal class firstVowel{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter literally any word: ");
        string s = Console.ReadLine();

        int aIndex = s.IndexOf("a");
        int eIndex = s.IndexOf("e");
        int iIndex = s.IndexOf("i");
        int oIndex = s.IndexOf("o");
        int uIndex = s.IndexOf("u");

        Console.WriteLine(aIndex + " " + eIndex + " " + iIndex + " " + oIndex + " " + uIndex);

        int smallest = s.Length + 1;
        if(aIndex > 0){
            if(aIndex < smallest){smallest = aIndex;}
        }
        if(eIndex > 0){
            if(aIndex < smallest){smallest = eIndex;}
        }
        if(iIndex > 0){
            if(aIndex < smallest){smallest = iIndex;}
        }
        if(oIndex > 0){
            if(aIndex < smallest){smallest = oIndex;}
        }
        if(uIndex > 0){
            if(aIndex < smallest){smallest = uIndex;}
        }

        if(smallest == s.Length + 1){smallest = -1;} //NO VOWELS, NOT A WORD
        
        Console.WriteLine(smallest);
    }
}