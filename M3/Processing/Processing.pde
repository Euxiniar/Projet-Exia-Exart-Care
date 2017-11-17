//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*; // Importation de la bibliothèque "serial"
//declare
PrintWriter output; // Permet au charactères d'être écrit dans un fichier externe
Serial udSerial; // Définition du nom port série qu'on utilise

void setup() {
  udSerial = new Serial(this, Serial.list()[0], 115200); // Définition des paramètres du port série et d'une vitesse de données
  output = createWriter ("Battements.csv"); // Créer un fichier "Battements.csv" dans lequel sera marqué les résultats
}

  void draw() {
    if (udSerial.available() > 0) { // Si la disponibilité du port série est supérieure à 0 (donc le port est disponnible) alors ... 
      String SenVal = udSerial.readString(); // On lit les données venant du port série, écriture des données dans un string "SenVal"
      if (SenVal != null) { // Si "SenVal" n'est pas nul, alors ...
        output.println(SenVal); // On écrit les valeurs de "Senval" dans le fichier externe, à la ligne
        println(SenVal); // on écrit dans la console pour suivre l'avancement des données transmises
      }
    }
  }

  void keyPressed(){ //Lors de l'appuie d'une touche du clavier ...
    output.flush(); // Ouverture du fichier permettant l'écriture du fichier
    output.close(); // Fermeture du fichier
    exit(); // Sort de la fonction
  }