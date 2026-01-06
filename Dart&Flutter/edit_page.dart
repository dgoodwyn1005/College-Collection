import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:go_router/go_router.dart';
import 'contact_provider.dart';

class EditPage extends StatefulWidget {
  final Map<String, dynamic>? contact;

  const EditPage({super.key, this.contact});

  @override
  State<EditPage> createState() => _EditPageState();
}

class _EditPageState extends State<EditPage> {
  final nameController = TextEditingController();
  final phoneController = TextEditingController();
  final emailController = TextEditingController();

  @override
  void initState() {
    super.initState();
    final existing = widget.contact?['contact'];
    nameController.text = existing?.name ?? '';
    phoneController.text = existing?.phone ?? '';
    emailController.text = existing?.email ?? '';
  }

  @override
  Widget build(BuildContext context) {
    return Consumer<ContactProvider>(
      builder: (context, contactProvider, child) {
        return Scaffold(
          appBar: AppBar(
            title: Text(widget.contact == null ? 'Add Contact' : 'Edit Contact'),
          ),
          body: Padding(
            padding: const EdgeInsets.all(16.0),
            child: Column(
              children: [
                TextField(
                  controller: nameController,
                  decoration: const InputDecoration(labelText: 'Name'),
                ),
                TextField(
                  controller: phoneController,
                  decoration: const InputDecoration(labelText: 'Phone'),
                ),
                TextField(
                  controller: emailController,
                  decoration: const InputDecoration(labelText: 'Email'),
                ),
                const SizedBox(height: 20),
                ElevatedButton(
                  onPressed: () {
                    final newContact = Contact(
                      name: nameController.text,
                      phone: phoneController.text,
                      email: emailController.text,
                    );

                    if (widget.contact == null) {
                      contactProvider.addContact(newContact);
                    } else {
                      contactProvider.updateContact(widget.contact!['index'], newContact);
                    }

                    context.go('/');
                  },
                  child: Text(widget.contact == null ? 'Add' : 'Save'),
                ),
                ElevatedButton(
                  onPressed: () {
                    context.go('/');
                  },
                  child: const Text('Go to Home Page'),
                ),
              ],
            ),
          ),
        );
      },
    );
  }
}