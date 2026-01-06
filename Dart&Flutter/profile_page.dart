import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';

class ProfilePage extends StatelessWidget {
  static final String page_name = "profile";
  final String username;
  const ProfilePage({super.key, required this.username});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Profile Page')),
      body: Center(
        child: Column(
          children: [
            Text('Welcome $username'),
            ElevatedButton(
              onPressed: ()  {
                context.pop();
              }, 
              child: Text("Go Back Home"))
          ]
          ),
        ),
    );
    }
  }
