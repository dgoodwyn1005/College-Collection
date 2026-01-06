internal class Game{
    public static void Main(string[] args)
    {
        GameScore game = new GameScore(0, 0);

        //Score & HighScore = 50
        game.Score = 50;
        game.DisplayScores(); 

        //Score & HighScore = 70
        game.Score = 70;
        game.DisplayScores();

        //Only Score is 25
        game.Score = 25;
        game.DisplayScores();

        //25 & 100
        game.HighScore = 100;
        game.DisplayScores(); 
    }

    class GameScore {
        private int _score;
        private int _highScore;

        // Property for Score
        public int Score
        {
            get { return _score; }
            set { 
                _score = value;
                if (_score > _highScore)
                {
                    _highScore = _score;
                }
            }
        }

        // Property for HighScore
        public int HighScore
        {
            get { return _highScore; }
            set { _highScore = value; }
        }

        public void DisplayScores()
        {
            Console.WriteLine("Score: " + _score);
            Console.WriteLine("High Score: " + _highScore);
        }

        public GameScore(int score, int highScore)
        {
            Score = score;
            HighScore = highScore;
        }
    }
}