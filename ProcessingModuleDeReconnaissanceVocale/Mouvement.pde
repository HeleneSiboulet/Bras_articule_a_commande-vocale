void Base (){
  Mouvement();
  
  if (listeBouton.get("positif").etat) {
      listeEcran.get("MCC").position ++ ;}
      
  if (listeBouton.get("negatif").etat) {
      listeEcran.get("MCC").position -- ;}
}
  

void Vertical (){
  Mouvement();
  
  if (listeBouton.get("positif").etat) {
      listeEcran.get("X").position ++ ;}
      
  if (listeBouton.get("negatif").etat) {
      listeEcran.get("X").position -- ;}
      
   Verin();
}

void Horizontal (){
  Mouvement();
  
  if (listeBouton.get("positif").etat) {
      listeEcran.get("Y").position ++ ;}
      
  if (listeBouton.get("negatif").etat) {
      listeEcran.get("Y").position -- ;}
      
   Verin();
}

void Poignet (){
  Mouvement();
  
  if (listeBouton.get("positif").etat) {
      listeEcran.get("servoPoignet").position ++ ;}
      
  if (listeBouton.get("negatif").etat) {
      listeEcran.get("servoPoignet").position -- ;}
}

void Main (){
  Mouvement();
  
  if (listeBouton.get("positif").etat) {
      listeEcran.get("servoMain").position ++ ;}
      
  if (listeBouton.get("negatif").etat) {
      listeEcran.get("servoMain").position -- ;}
}



void Mouvement (){
  Autorise [0] = "positif" ;
  Autorise [1] = "negatif" ;
  Autorise [2] = "stop" ;
  Autorise [3] = "." ;
  Autorise [4] = "." ;
  
if (listeBouton.get("stop").etat){
    Stop();}

  delay(100);
}

void Stop(){
Iterator it = cles.iterator();
  while (it.hasNext()){
     Object cle = it.next();
     listeBouton.get(cle).etat=false;
    }
    
  Autorise [0] = "mvt" ;
  Autorise [1] = "fonction" ;
  Autorise [2] = "." ;
  Autorise [3] = "." ;
  Autorise [4] = "." ;
    
}


void Verin(){

  float V1;
  float V2;
  float alpha;
  float beta;
  float r = 60;
  float t = 259;
  float s = 25;
  float z = 165;
  float k = 20;
  float betaS = 5.5;
  float a = 350 ;
  float x;
  float y;
  
  x = listeEcran.get("X").position;
  y = listeEcran.get("Y").position;
  
  beta = 180-2*acos((sqrt(x*x+y*y))/(2*a)); 
  V2 = sqrt(r*r+t*t+s*s-2*r*sqrt(t*t+s*s)*cos(beta+betaS));
  
  alpha = acos((sqrt(x*x+y*y))/2*a) + acos(x/(sqrt(x*x+y*y)));
  V1 = sqrt(z*z+k*k-2*z*k*cos(180-alpha));
  
  listeEcran.get("petitVerin").position = V1;
  listeEcran.get("grandVerin").position = V2;
  
  /*float w;
  w = (sqrt(x*x+y*y))/2*a;
  print (x);
  print("     ");
  println (y);
  println (w);
  delay(10);*/
}
