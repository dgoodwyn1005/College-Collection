import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';
import 'package:provider/provider.dart';
import 'contact_provider.dart';

class ContactPage extends StatelessWidget {
  const ContactPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Consumer<ContactProvider>(
      builder: (context, contactProvider, child) {
        return Scaffold(
          appBar: AppBar(title: const Text('View All Contacts')),
          body: ListView.builder(
            itemCount: contactProvider.contacts.length,
            itemBuilder: (context, index) {
              final contact = contactProvider.contacts[index];
              return ListTile(
                title: Text(contact.name),
                subtitle: Text('${contact.phone} | ${contact.email}'),
                onTap: () => context.go('/details', extra: index),
                trailing: IconButton(
                  icon: const Icon(Icons.delete),
                  onPressed: () => contactProvider.deleteContact(index),
                ),
              );
            },
          ),
          floatingActionButton: FloatingActionButton(
            onPressed: () => context.go('/edit'),
            child: const Icon(Icons.add),
          ),
        );
      },
    );
  }
}