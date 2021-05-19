float MCCTendu = 10;
float grandVerinTendu = 10;
float petitVerinTendu = 10;
float MCCProche = -10;
float grandVerinProche = -10;
float petitVerinProche = -10;
float MCCVeille = 0;
float grandVerinVeille = 0;
float petitVerinVeille = 0;


void Fonction(){
  Autorise[0] = "stop" ;
  Autorise[1] = "." ;
  Autorise[2] = "." ;
  Autorise[3] = "." ;
  Autorise[4] = "." ;
  
  if (listeBouton.get("stop").etat){
    Stop();}

  delay(100);
}


void Atteindre(float M, float G,float P){
  if (listeEcran.get("MCC").position < M)
     {listeEcran.get("MCC").position ++;}
  if (listeEcran.get("MCC").position > M)
     {listeEcran.get("MCC").position --;}

  if (listeEcran.get("grandVerin").position < G)
     {listeEcran.get("grandVerin").position ++;}
  if (listeEcran.get("grandVerin").position > G)
     {listeEcran.get("grandVerin").position --;}
     
  if (listeEcran.get("petitVerin").position < P)
     {listeEcran.get("petitVerin").position ++;}
  if (listeEcran.get("petitVerin").position > P)
     {listeEcran.get("petitVerin").position --;}
     
  if (listeEcran.get("MCC").position == M && listeEcran.get("grandVerin").position == G && listeEcran.get("petitVerin").position == P)
     {Stop();}
     
}


void Tendu(){
  Fonction();
  Atteindre(MCCTendu,grandVerinTendu,petitVerinTendu);
}

void Proche(){
  Fonction();
  Atteindre(MCCProche,grandVerinProche,petitVerinProche);
}

void Veille(){
  Fonction();
  Atteindre(MCCVeille,grandVerinVeille,petitVerinVeille);
  
  if (listeEcran.get("MCC").position == MCCVeille && listeEcran.get("grandVerin").position == grandVerinVeille && listeEcran.get("petitVerin").position == petitVerinVeille){
    Autorise [0] = "nom" ;
    Autorise [1] = "." ;
    Autorise [2] = "." ;
    Autorise [3] = "." ;
    Autorise [4] = "." ;   }
  
}
