import 'package:flutter/material.dart';

class Contact {
  String name;
  String phone;
  String image = "https://t3.ftcdn.net/jpg/00/57/04/58/360_F_57045887_HHJml6DJVxNBMqMeDqVJ0ZQDnotp5rGD.jpg";

  Contact({required this.name, required this.phone, image});
}

class A18 extends StatelessWidget {
  A18({super.key});

  @override
  Widget build(BuildContext context) {
    List<dynamic> contacts = List.generate(5, (index) => Contact(
        name: 'Contact ${index + 1}',
        phone: '555-010${index + 1}',
      ),
    );

    return MaterialApp(
      home: Scaffold(
        body: ListView.builder(
          itemCount: contacts.length,
          itemBuilder: (context, index) {
            final contact = contacts[index];
            return ListTile(  
              leading: Image.network(contact.image),
              title: Text(contact.name),
              subtitle: Text(contact.phone),
            );
          },
        ),
      ),
    );
  }
}
