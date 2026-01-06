internal class MagicSquare{
    public static void Main(string[] args)
    {
        int[,] square = {
            { 16, 3, 2, 13 },
            { 5, 10, 11, 8 },
            { 9, 6, 7, 12 },
            { 4, 15, 14, 1 }
        };

        bool isMagic = checkMagicSquare(square);

        if (isMagic)
        {
            Console.WriteLine("This is a magic square!");
        } 
        else
        {
            Console.WriteLine("This is not a magic square.");   
        }

    bool checkMagicSquare(int[,] matrix)
    {
        int size = 4;
        int magicSum = 0;

        // First row sum
        for (int j = 0; j < size; j++)
        {
            magicSum += matrix[0, j];
        }

        // Check rows
        for (int i = 0; i < size; i++)
        {
            int rowSum = 0;
            for (int j = 0; j < size; j++)
            {
                rowSum += matrix[i, j];
            }
            if (rowSum != magicSum)
                return false;
        }

        // Check columns
        for (int j = 0; j < size; j++)
        {
            int colSum = 0;
            for (int i = 0; i < size; i++)
            {
                colSum += matrix[i, j];
            }
            if (colSum != magicSum)
                return false;
        }

        // Check main diagonal
        int diag1 = 0;
        for (int i = 0; i < size; i++)
        {
            diag1 += matrix[i, i];
        }
        if (diag1 != magicSum)
            return false;

        // Check secondary diagonal
        int diag2 = 0;
        for (int i = 0; i < size; i++)
        {
            diag2 += matrix[i, size - 1 - i];
        }
        if (diag2 != magicSum)
            return false;

        return true;
        }
    }
}