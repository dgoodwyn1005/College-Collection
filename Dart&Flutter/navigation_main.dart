import 'package:flutter/material.dart';
import 'data_structures_page.dart';

void main() {
  runApp(MainApp());
}

class MainApp extends StatelessWidget {

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title:"Computer Science Courses",
      home: HomePage(),
    );
  }
}

class HomePage extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return Scaffold(
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children:[
              ElevatedButton(
                onPressed:(){
                  Navigator.push(context, 
                  MaterialPageRoute(builder:(context)=>DataStructuresPage()),);
                },
                child: Text("Data Structures and Algorithms"),)
            ]),
        ),
      );
  }
}
