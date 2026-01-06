void main() {
  Animal a = Animal("Teddy the Bear");
  Bird b = Bird("Big Bird");
  Fish f = Fish("Nemo");
  Duck d = Duck("Donald");
  a.display_info();
  b.display_info();
  b.fly(b.name);
  f.display_info();
  f.swim(f.name);
  d.display_info();
  d.fly(d.name);
  d.swim(d.name);
}

class Animal{
  String name;

  Animal(this.name);

  void display_info()=>print("$name is an animal");
}

mixin Flyable{
  void fly(String name)=>print("$name is flying");
}

mixin Swimmable{
  void swim(String name)=>print("$name is swimming");
}

class Bird extends Animal with Flyable{
  Bird(String n):super(n);

  @override
  void display_info()=>print("$name is a bird");
}

class Fish extends Animal with Swimmable{
  Fish(String n):super(n);

  @override
  void display_info()=>print("$name is a fish");
}

class Duck extends Animal with Flyable, Swimmable{
  Duck(String n):super(n);

  @override
  void display_info()=>print("$name is a duck");
}