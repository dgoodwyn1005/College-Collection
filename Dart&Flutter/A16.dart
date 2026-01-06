import 'package:flutter/material.dart';

const productURL = "https://m.media-amazon.com/images/I/51nyOPcCrwL._AC_UF1000,1000_QL80_.jpg";

class A16 extends StatelessWidget {
  const A16({
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Column(
        children: [
          Row(
            children: [
              Image.network(productURL, width: 400, height: 400, fit: BoxFit.fill,),
              Column(
                children: [
                  _information(),
                ]
              ),
            ],
          ),
          Row(
            children: [
              TextButton(
              child: Text("Remove", style: TextStyle(fontSize: 20)),
              onPressed: () {},
              ),
              Text("Total Price = 1,087,172.82 USD", style: TextStyle(fontSize: 25), textDirection: TextDirection.ltr,),
            ],
          )

        ],
      )
    );
  }
}

Column _information() {
  return Column(
    children: [
      Text("Playstation 5", style: TextStyle(fontSize: 30), textDirection: TextDirection.ltr,),
      Text("Price: 399.99 USD", style: TextStyle(fontSize: 30), textDirection: TextDirection.ltr,),
      Text("Quantity: 2718 in stock", style: TextStyle(fontSize: 30), textDirection: TextDirection.ltr,),
    ],
  );
}