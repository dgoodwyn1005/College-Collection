import 'package:flutter/material.dart';

const backgroundURL = "https://upload.wikimedia.org/wikipedia/commons/7/7c/A_downtown_view_of_Richmond%2C_VA.jpg";
const mainAvatarURL = "https://img.freepik.com/free-vector/smiling-young-man-illustration_1308-174669.jpg";
const otherAvatarURL = "https://fiverr-res.cloudinary.com/images/q_auto,f_auto/gigs/15618284/original/d49dc4ed55985acb52b8004d47f70ee45dc7b968/create-an-avatar-headshot-of-your-picture.jpg";

class A17 extends StatelessWidget {
  A17({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: Center(
          child: Stack(
            children: [
              _background(),
              Center(
                child: _layer2(),
              ),
              Positioned.fill(
                top: 40,
                child: Align(
                  alignment: Alignment.topCenter,
                  child: Image.network(mainAvatarURL, width: 75, height: 75, fit: BoxFit.fill,)
                )
              ),
            ],
          ),
        )
      ),
    );
  }
}

Widget _background() {
  return Column(
    children: [
      Image.network(backgroundURL, width: double.infinity, height: 200, fit: BoxFit.fill,),
      Container(
        color: Colors.grey,
        width: double.infinity,
        height: 482,
      )
    ],
  );
}

Widget _layer2(){
  return Container(
    padding:EdgeInsets.all(10),
    margin: EdgeInsets.all(10),
    alignment: Alignment.center,
    color: Colors.white,
    width: 400,
    height: 550,
    child: Column(
      children: [
        SizedBox(height: 50,),
        Text("Easin Arafat", style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold),),
        Text("UI/UX Designer", style: TextStyle(fontSize: 18, fontWeight: FontWeight.w200),),
        SizedBox(height:25),
        _iconRow(),
        SizedBox(height:25),
        _followRow(),
        SizedBox(height:75),
        _knownFollowers(),
        Text("22 Followers You Know", style: TextStyle(fontSize: 16, fontWeight: FontWeight.w200),),
        SizedBox(height:100),
        ElevatedButton(
          onPressed: () {},
          style: ElevatedButton.styleFrom(
            backgroundColor: Colors.lightBlueAccent,
            foregroundColor: Colors.white,
            textStyle: TextStyle(fontSize: 15),
          ),
          child: Text("FOLLOW NOW"),
        ),
      ],
    ),
  );
}

Widget _iconRow() {
  return Padding(
    padding: EdgeInsets.only(
      left: 60,
      right: 60,
    ),
    child: Row(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Icon(Icons.person, color: Colors.blue, size: 28),
        Spacer(),
        Icon(Icons.person, color: Colors.blueGrey, size: 28),
        Spacer(),
        Icon(Icons.person, color: Colors.blueGrey, size: 28),
        Spacer(),
        Icon(Icons.person, color: Colors.blueGrey, size: 28),
        Spacer(),
        Icon(Icons.person, color: Colors.blueGrey, size: 28),
      ],
    ),
  );
}

Row _followRow() {
  return Row(
    mainAxisAlignment: MainAxisAlignment.center,
    children: [
      Column(
        children: [
          Text("240", style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
          Text("Following", ),
        ]
      ),
      SizedBox(width:50),
      Column(
        children: [
          Text("24K", style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
          Text("Followers", ),
        ]
      ),
    ],
  );
}

Widget _knownFollowers() {
  return Row(
    mainAxisAlignment: MainAxisAlignment.center,
    children: [
      Image.network(otherAvatarURL, width: 50, height: 50, fit: BoxFit.fill,),
      Image.network(otherAvatarURL, width: 50, height: 50, fit: BoxFit.fill,),
      Image.network(otherAvatarURL, width: 50, height: 50, fit: BoxFit.fill,),
      Image.network(otherAvatarURL, width: 50, height: 50, fit: BoxFit.fill,),
      Image.network(otherAvatarURL, width: 50, height: 50, fit: BoxFit.fill,),
      Image.network(otherAvatarURL, width: 50, height: 50, fit: BoxFit.fill,),
    ],
  );
}