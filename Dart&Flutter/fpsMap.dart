void main() {
  Map<String, dynamic> player = {
    "name": "Master Chief",
    "health": 100,
    "kills": 24,
    "gun": "Gen 5",
    "maxAmmo": 30,
    "currentAmmo": 17,
  };

  print("Original Map");
  print(player);
  
  print("Remove Name from Map");
  player.remove("name");
  print(player);

  print("Add Deaths to Map");
  player["deaths"] = 4;
  print(player);
  
}
