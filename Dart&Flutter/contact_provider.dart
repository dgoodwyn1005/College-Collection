import 'package:flutter/foundation.dart';

class Contact {
  String name;
  String phone;
  String email;

  Contact({required this.name, required this.phone, required this.email});
}

class ContactProvider extends ChangeNotifier {
  final List<Contact> _contacts = [];

  List<Contact> get contacts => _contacts;

  void addContact(Contact contact) {
    _contacts.add(contact);
    notifyListeners();
  }

  void updateContact(int index, Contact contact) {
    _contacts[index] = contact;
    notifyListeners();
  }

  void deleteContact(int index) {
    _contacts.removeAt(index);
    notifyListeners();
  }
}