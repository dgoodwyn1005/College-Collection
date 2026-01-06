import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';

class WelcomePage extends StatelessWidget{
  const WelcomePage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("Welcome Page")),
      body: Center(
        child: ElevatedButton(
          onPressed: () {
            context.go('/login');
          }, 
          child: Text('Go to login page'),
        ),
      )
    );
  }

}