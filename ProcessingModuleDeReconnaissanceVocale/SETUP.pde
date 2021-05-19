void SETUP (){
  
  
  listeBouton.put("base",new Bouton("base", 50, 50));
  listeBouton.put("positif",new Bouton("positif", 50, 120));
  listeBouton.put("nom",new Bouton("nom", 50, 190));
  
  listeBouton.put("vertical",new Bouton("vertical", 160, 50));
  listeBouton.put("negatif",new Bouton("negatif", 160, 120));
  listeBouton.put("veille",new Bouton("veille", 160, 190));
  
  listeBouton.put("horizontal",new Bouton("horizontal", 270, 50));
  listeBouton.put("stop",new Bouton("stop", 270, 120));
  listeBouton.put("tendu",new Bouton("tendu", 270, 190));
  
  listeBouton.put("poignet",new Bouton("poignet", 380, 50));
  listeBouton.put("mvt",new Bouton("mvt", 380, 120));
  listeBouton.put("proche",new Bouton("proche", 380, 190));
  
  listeBouton.put("main",new Bouton("main", 490, 50));
  listeBouton.put("fonction",new Bouton("fonction", 490, 120));
  listeBouton.put(" ",new Bouton(" ", 490, 190));
  
  
  listeEcran.put ("MCC",new Ecran("MCC",0,"(deg)",600,30));
  listeEcran.put ("petitVerin",new Ecran("petitVerin",0,"(mm)",750,30));
  listeEcran.put ("grandVerin",new Ecran("grandVerin",0,"(mm)",600,130));
  listeEcran.put ("servo1",new Ecran("servo1",0,"(deg)",750,130));
  listeEcran.put ("servoPoignet",new Ecran("servoPoignet",0,"(deg)",600,230));
  listeEcran.put ("servoMain",new Ecran("servoMain",0,"(deg)",750,230));
  
  listeEcran.put ("X",new Ecran("X",0,"(mm)",40,350));
  listeEcran.put ("Y",new Ecran("Y",0,"(mm)",240,350));
  
  cles = listeBouton.keySet();
  clesEcran = listeEcran.keySet(); 
  
  listeBouton.get("nom").autorise = true;
  
  delay(10);

}
