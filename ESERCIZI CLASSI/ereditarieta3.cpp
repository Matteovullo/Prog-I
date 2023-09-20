/*
Progettare una gerarchia di classi con la classe base Sport, dalla quale derivano 
le clasis Calcio, Pallacanestro, Pallavvolo.
*/

class Sport{
    int giocatori;
};

class Calcio: public Sport{
    public:
        Calcio(int giocatori){
            this->giocatori=giocatori;
        }
}

class Pallacanestro: public Sport{
    public:
        Pallacanestro(int giocatori){
            this->giocatori=giocatori;
        }
}

class Pallavolo: public Sport{
    public:
        Pallavolo(int giocatori){
            this->giocatori=giocatori;
        }
}