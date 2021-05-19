import java.util.Map;
import java.util.Iterator;
import java.util.Set;
import processing.serial.*;
Map<String,Bouton> listeBouton = new HashMap<String,Bouton>();
Map<String,Ecran> listeEcran = new HashMap<String,Ecran>();
String recu;
String ordre;
Set cles;
Set clesEcran;
String [] Autorise = {"nom",".",".",".","." };


void setup(){
  size(1000,700);
  background(100);
  SETUP();
  }


void draw(){
  
Iterator ot = cles.iterator();                                  //Pour tous les boutons
  while (ot.hasNext()){
     Object cle = ot.next();
     if (listeBouton.get(cle).texte != Autorise[0] && listeBouton.get(cle).texte != Autorise[1] && listeBouton.get(cle).texte != Autorise[2]
         && listeBouton.get(cle).texte != Autorise[3]&& listeBouton.get(cle).texte != Autorise[4])
          {listeBouton.get(cle).autorise = false ;}
     else {listeBouton.get(cle).autorise = true ;}
     listeBouton.get(cle).couleur();
     listeBouton.get(cle).Apparait();
  }
  
  
Iterator at = clesEcran.iterator();                            //Pour tous les écrans    
  while (at.hasNext()){
     Object cle = at.next();
     listeEcran.get(cle).afficher();
  }
 

if (listeBouton.get("nom").etat == true){
Autorise [0] = "mvt" ;
Autorise [1] = "fonction" ;
Autorise [2] = "." ;
Autorise [3] = "." ;
Autorise [4] = "." ;
}

if (listeBouton.get("mvt").etat == true){
Autorise [0] = "base" ;
Autorise [1] = "vertical" ;
Autorise [2] = "horizontal" ;
Autorise [3] = "poignet" ;
Autorise [4] = "main" ;
}

if (listeBouton.get("fonction").etat == true){
Autorise [0] = "veille" ;
Autorise [1] = "tendu" ;
Autorise [2] = "proche" ;
Autorise [3] = "." ;
Autorise [4] = "." ;
}

if (listeBouton.get("base").etat == true){Base();}
if (listeBouton.get("vertical").etat == true){Vertical();}
if (listeBouton.get("horizontal").etat == true){Horizontal();}
if (listeBouton.get("poignet").etat == true){Poignet();}
if (listeBouton.get("main").etat == true){Main();}

if (listeBouton.get("tendu").etat == true){Tendu();}
if (listeBouton.get("proche").etat == true){Proche();}
if (listeBouton.get("veille").etat == true){Veille();}


  delay(50);
}


void mousePressed(){
  Iterator it = cles.iterator();
  while (it.hasNext()){
     Object cle = it.next();
     listeBouton.get(cle).EstClic();
    }
  }
