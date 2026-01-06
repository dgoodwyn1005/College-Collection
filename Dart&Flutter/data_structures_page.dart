import 'package:flutter/material.dart';

class DataStructuresPage extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return Scaffold(
      appBar: AppBar(title:Text("Data Structures and Algorithms")),
      body:Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children:[
            Text("Data Structures and Algorithms",
            style: TextStyle(fontSize: 24.0, fontWeight:FontWeight.bold),),
            Text("This course studies different way to arrange data in collections and" +
             " different methods to process that data",
             style: TextStyle(fontSize:16.0),),
          ]
        ),
      ),
      );
  }

}