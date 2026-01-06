internal class Quiz{
    public static void Main(string[] args)
    {
        MultipleChoiceQuiz john = new MultipleChoiceQuiz(['A', 'D', 'D']);
        MultipleChoiceQuiz ralph = new MultipleChoiceQuiz(['B', 'A', 'C']);
        MultipleChoiceQuiz bob = new MultipleChoiceQuiz(['E', 'E', 'E']);

        john.results(['A', 'C', 'D']); // One Wrong
        ralph.results(['B', 'A', 'C']); // None Wrong
        bob.results(['A', 'B', 'C']); // All Wrong
    }

    class MultipleChoiceQuiz {
        private char[] correctAnswers;

        public int Grade(char[] studentAnswers)
        {
            int score = 0;
            for (int i = 0; i < correctAnswers.Length && i < studentAnswers.Length; i++)
            {
                if (char.ToUpper(studentAnswers[i]) == char.ToUpper(correctAnswers[i]))
                {
                    score++;
                }
            }
            return score;
        }
        public double getPercentage(char[] studentAnswers)
        {
            int score = Grade(studentAnswers);
            return (double)score / correctAnswers.Length * 100;
        }
        
        public void results(char[] studentAnswers)
        {
            int score = Grade(studentAnswers);

            for (int i = 0; i < correctAnswers.Length && i < studentAnswers.Length; i++)
            {
                if (char.ToUpper(studentAnswers[i]) == char.ToUpper(correctAnswers[i]))
                {
                    Console.WriteLine($"Question {i + 1}: Correct");
                }
                else
                {
                    Console.WriteLine($"Question {i + 1}: Incorrect (Your Answer: {studentAnswers[i]}, Correct Answer: {correctAnswers[i]})");
                }
            }

            Console.WriteLine("Total Percentage: " + getPercentage(studentAnswers));
        }

        public MultipleChoiceQuiz(char[] correctAnswers)
        {
            this.correctAnswers = correctAnswers;
        }
    }
}