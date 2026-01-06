import 'package:flutter/foundation.dart';
import 'package:english_words/english_words.dart' as words;
import 'dart:math';
import "wordle.dart";

class HurdleProvider extends ChangeNotifier {
  final random = Random.secure();
  List<String> totalWords = [];
  List<String> rowInput = [];
  List<String> excludedLetters = [];
  List<Wordle> hurdleBoard = [];
  String targetWord = '';
  int count = 0;
  int index = 0;
  int attempts = 0;
  final lettersPerRow = 5;
  final totalAttempts = 6;
  bool wins = false;

  bool get isAValidWord => totalWords.contains(rowInput.join('').toLowerCase());
  bool get shouldCheckForAnswer => rowInput.length == lettersPerRow;
  bool get noAttemptsLeft => attempts == totalAttempts;

  init() {
    totalWords = words.all.where((element) => element.length == 5).toList();
    generateRandomWord();
    generateBoard();
  }

  generateBoard() {
    hurdleBoard = List.generate(30, (index) => Wordle(letter:''));
  }

  generateRandomWord() {
    targetWord = totalWords[random.nextInt(totalWords.length)].toUpperCase();
    print(targetWord);
  }

  inputLetter(String letter) {
    if(count < lettersPerRow) {
      rowInput.add(letter);
      hurdleBoard[index] = Wordle(letter:letter);
      count++;
      index++;
      notifyListeners();
    }
  }

  deleteLetters() {
    if(rowInput.isNotEmpty) {
      rowInput.removeAt(rowInput.length-1);
    }

    if(count > 0) {
      hurdleBoard[index-1] = Wordle(letter:'');
      index--;
      count--;
      notifyListeners();
    }
  }

  void checkAnswer() {
    final input = rowInput.join('');
    if(input == targetWord) {
      wins = true;
    }
    else {
      _markLettersOnBoard();
      if(attempts < totalAttempts){
        _goToNextRow();
      }
    }
  }

  void reset() {
    count = 0;
    index = 0;
    rowInput.clear();
    hurdleBoard.clear();
    wins = false;
    targetWord = '';
    excludedLetters.clear();
    generateBoard();
    generateRandomWord();
    notifyListeners();
  }

  void _markLettersOnBoard() {
    for(int i = 0; i < hurdleBoard.length; i++){
      if (hurdleBoard[i].letter.isNotEmpty && targetWord.contains(hurdleBoard[i].letter)) {
        hurdleBoard[i].existsInTarget = true;
      }else if(hurdleBoard[i].letter.isNotEmpty && !targetWord.contains(hurdleBoard[i].letter)){
        hurdleBoard[i].doesNotExistInTarget = true;
        excludedLetters.add(hurdleBoard[i].letter);
      }
    }

    notifyListeners();
  }

  void _goToNextRow() {
    attempts++;
    count = 0;
    rowInput.clear();
  }
}