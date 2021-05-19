class Bouton{
  String texte;
  int Positionx;
  int Positiony;
  int largeur;
  int hauteur;
  int r;
  int g;
  int b;
  boolean etat;
  boolean autorise;
  Bouton(String t, int x, int y){ //constructeur
    etat = false;
    texte = t;
    Positionx = x;
    Positiony = y;
    largeur = 100;
    hauteur = 60;
    autorise = false ;
    couleur();
  }
  void Apparait(){
    if (autorise){fill(200);} 
    else {fill(100);}
    rect(Positionx-5, Positiony-5, largeur+10, hauteur+10);
    fill(r,g,b);
    textSize(18);
    rect(Positionx, Positiony, largeur, hauteur);
    fill(0);
    text(texte, Positionx + 7, Positiony + hauteur - 5);
  }
  void EstClic(){
    if((mouseX > Positionx && mouseX < (Positionx + largeur) && mouseY > Positiony && mouseY < Positiony + hauteur) && autorise == true){
      if(etat){etat =false;}
      else{etat=true;}
      if (texte == "positif" && etat){listeBouton.get("negatif").etat = false;}
      if (texte == "negatif" && etat){listeBouton.get("positif").etat = false;}
     couleur();
    }
  }
  void couleur(){
    if(etat == false){
        r = 255;
        g = 0;
        b = 0;
      }
    else {
      r = 0;
      g = 255;
      b = 0;
    }
    } 
 
}
