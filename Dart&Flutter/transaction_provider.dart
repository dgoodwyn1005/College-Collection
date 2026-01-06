import 'package:flutter/foundation.dart';

class Transaction {
  final double amount;
  final String type;
  final String category;
  Transaction(this.amount, this.type, this.category);
}

class TransactionProvider extends ChangeNotifier {
  final List<Transaction> transactions = [];
  String filterType = 'All';
  String filterCategory = 'All';

  List<Transaction> get filtered {
    return transactions.where((t) {
      bool type = (filterType == 'All' || t.type == filterType);
      bool category = (filterCategory == 'All' || t.category == filterCategory);
      return type && category;
    }).toList();
  }

  // Calculates total balance, income, and expenses
  double get balance {
    double income = 0;
    double expenses = 0;
    for (var t in transactions) {
      if (t.type == 'Income') {
        income += t.amount;
      } else {
        expenses += t.amount;
      }
    }
    return income - expenses;
  }

  double get income {
    return transactions
        .where((tx) => tx.type == 'Income')
        .fold(0, (sum, tx) => sum + tx.amount);
  }

  double get expenses {
    return transactions
        .where((tx) => tx.type == 'Expense')
        .fold(0, (sum, tx) => sum + tx.amount);
  }

  void add(Transaction t) {
    transactions.add(t);
    notifyListeners();
  }

  void remove(int index) {
    transactions.removeAt(index);
    notifyListeners();
  }

  void setType(String type) {
    filterType = type;
    notifyListeners();
  }

  void setCategory(String category) {
    filterCategory = category;
    notifyListeners();
  }

}