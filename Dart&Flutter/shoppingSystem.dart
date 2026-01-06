void main() {
  Book hg = Book("The Hunger Games", 22.99, "Suzanne Collins");
  Electronics ps5 = Electronics("Playstation 5", 375.00, 1);

  hg.displayInfo();
  ps5.displayInfo();
}

class Product{
  String name;
  double price;

  Product(this.name, this.price);

  void displayInfo() => print("$name - \$$price");
}

class Book extends Product{
  String author;

  Book(String name, double price, this.author) : super(name, price);

  @override
  void displayInfo() => print("$name by $author - \$$price");
}

class Electronics extends Product{
  int warranty;

  Electronics(String name, double price, this.warranty) : super(name, price);

  @override
  void displayInfo() => print("$name - \$$price, lasts for $warranty year(s)");
}

