import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';
import 'profile_page.dart';

class HomePage extends StatelessWidget {
  static final String page_name = "home";
  const HomePage({super.key});

  @override
  Widget build(BuildContext context) {
    final List<String> usernames = ['John','Bob','Alice','Anne'];
    return Scaffold(
      appBar: AppBar(title: Text('Home Page')),
      body: ListView.builder(
        itemCount:usernames.length,
        itemBuilder:(context,index){
          final username = usernames[index];
          return ListTile(
            title: Text(username),
            onTap: (){
              context.pushNamed(ProfilePage.page_name,
              pathParameters:{'username':username});
            });
        }
      )
    );
  }
}