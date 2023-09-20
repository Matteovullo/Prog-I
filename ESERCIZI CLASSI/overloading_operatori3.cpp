/*Scrivere una classe Ora_giorno che permetta di rappresentare l’ora del giorno in ore e minuti 
(formato 24 ore). La classe deve sovraccaricare l’operatore << per stampare l’ora nel formato HH:MM 
e gli operatori ++ e -- (sia prefissi che postfissi) per incrementare/decrementare l’ora di minuti.*/

class Ora_giorno{
    int minuti;
    int ora;
    public:
        Ora_giorno();
        friend ostream& operator<<(ostream& o, Ora_giorno);
        friend Ora_giorno &operator++(Ora_giorno o);
        friend Ora_giorno &operator++(Ora_giorno o);
        friend Ora_giorno &operator--(Ora_giorno o);
        friend Ora_giorno &operator--(Ora_giorno o);
};

ostream& operator<<(ostream& o, Ora_giorno) {
    s << o.minuti << ":" << o.ora<<endl;
    return s; 
}

Ora_giorno &operator++(Ora_giorno o) { 
    o.minuti++;
    o.ora++;
    return p;
}

Ora_giorno operator++(Ora_giorno o, int) { 
    Point2D aux = p;
    o.minuti++;
    o.ora++;
    return aux;
}

Ora_giorno &operator--(Ora_giorno o) { 
    o.minuti--;
    o.ora--;
    return p;
}

Ora_giorno operator--(Ora_giorno o, int) { 
    Point2D aux = p;
    o.minuti--;
    o.ora--;
    return aux;
}



