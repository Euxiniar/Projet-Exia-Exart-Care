//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*; // Importation de la bibliothèque "serial"
//declare
PrintWriter outputPoulsTemps; // Permet au charactères d'être écrit dans un fichier externe
PrintWriter outputDate;
Serial udSerial; // Définition du nom port série qu'on utilise

void setup() {
  udSerial = new Serial(this, Serial.list()[0], 115200); // Définition des paramètres du port série et d'une vitesse de données
  outputPoulsTemps = createWriter ("../../M4/Battements.csv"); // Créer un fichier "Battements.csv" dans le reperetoire M4 dans lequel sera marqué les résultats
  outputDate = createWriter ("../../M4/Date.csv"); // Créer un fichier "Date.csv" dans le reperetoire M4 dans lequel sera marqué la date
}

  void draw() {
    if (udSerial.available() > 0) { // Si la disponibilité du port série est supérieure à 0 (donc le port est disponnible) alors ... 
      String SenVal = udSerial.readString(); // On lit les données venant du port série, écriture des données dans un string "SenVal"
      if (SenVal != null) { // Si "SenVal" n'est pas nul, alors ...
        outputPoulsTemps.println(SenVal); // On écrit les valeurs de "Senval" dans le fichier externe, à la ligne
        println(SenVal); // on écrit dans la console pour suivre l'avancement des données transmises
      }
    }
  }

  void keyPressed(){ //Lors de l'appuie d'une touche du clavier ...
    int s = second();  // Values from 0 - 59
    int m = minute();  // Values from 0 - 59
    int h = hour();    // Values from 0 - 23
    int d = day();
    int mo = month();
    int y = year();
    String heure = d + "/" + mo + "/" + y +" a " + h + ":" + m + ":" + s;
    outputDate.print(heure);
    outputDate.flush(); // Ouverture du fichier permettant l'écriture de la date 
    outputDate.close(); // Fermeture du fichier outputDate
    outputPoulsTemps.flush(); // Ouverture du fichier permettant l'écriture du pouls et du temps entre chaque pulsation en ms
    outputPoulsTemps.close(); // Fermeture du fichier outputPoulsTemps
    exit(); // Sort de la fonction
  }