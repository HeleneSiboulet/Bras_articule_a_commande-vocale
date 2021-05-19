class Ecran{
  String actionneur;
  float position;
  String unite;
  int Positionx;
  int Positiony;
  int largeur;
  int hauteur;
 Ecran (String a, float p,String u, int x, int y){
   actionneur = a;
   position = p;
   unite =u;
   Positionx = x;
   Positiony = y;
   largeur = 140;
   hauteur = 80;
   }
void afficher(){
    fill(255);
    textSize(19);
    rect(Positionx, Positiony, largeur, hauteur);
    fill(0);
    text(position, Positionx + 7, Positiony + hauteur - 5);
    textSize (21);
    text(actionneur, Positionx + 2, Positiony + hauteur - 50);
    textSize (10);
    text(unite, Positionx + 7, Positiony + hauteur - 30);
  }

}
