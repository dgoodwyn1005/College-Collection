import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:go_router/go_router.dart';
import 'contact_provider.dart';

class DetailsPage extends StatelessWidget {
  final Contact contact;

  const DetailsPage({super.key, required this.contact});

  @override
  Widget build(BuildContext context) {
    return Consumer<ContactProvider>(
      builder: (context, contactProvider, child) {
        return Scaffold(
          appBar: AppBar(title: const Text("Contact Details")),
          body: Padding(
            padding: EdgeInsets.all(16.0),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text("Name: ${contact.name}", style: TextStyle(fontSize: 18)),
                SizedBox(height: 8),
                Text("Phone: ${contact.phone}", style: TextStyle(fontSize: 18)),
                SizedBox(height: 8),
                Text("Email: ${contact.email}", style: TextStyle(fontSize: 18)),
                ElevatedButton(
                  onPressed: () {
                    context.go('/');
                  }, 
                  child: Text('Go to Home Page'),
                ),
              ],
            ),
          ),
        );
      },
    );
  }
}