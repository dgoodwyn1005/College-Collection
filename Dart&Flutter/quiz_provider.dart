import 'package:flutter/foundation.dart';

class Question {
  final String question;
  final List<String> choices;
  final int correctIndex;

  Question(this.question, this.choices, this.correctIndex);
}

class QuizProvider extends ChangeNotifier {
  final List<Question> questions = [
    Question("Who is the current president?", ['Donald Trump', 'Stephen Curry', 'Obama'], 0),
    Question('Who wrote the Declaration of Independence?', ['Joe Biden', 'Thomas Jefferson', 'Kanye West'], 1),
    Question('Who was the first black president?', ['Dr. M&M', 'Kanye West', 'Obama'], 2),
  ];

  int currentQuestion = 0;
  int score = 0;
  int? selectedAnswer;
  bool answered = false;

  Question get current => questions[currentQuestion];
  int get currentIndex => currentQuestion;
  int get totalQuestions => questions.length;
  bool get isLastQuestion => currentQuestion == questions.length - 1;

  // Methods
  void selectAnswer(int index) {
    if (answered) return;

    selectedAnswer = index;

    if (index == current.correctIndex) {
      score++;
    }

    answered = true;

    notifyListeners();
  }

  void nextQuestion() {
    if (currentQuestion < questions.length - 1) {
      currentQuestion++;
      selectedAnswer = null;
      answered = false;
      notifyListeners();
    }
  }

  void resetQuiz() {
    currentQuestion = 0;
    score = 0;
    selectedAnswer = null;
    answered = false;
    notifyListeners();
  }
}