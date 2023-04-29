object A2 {
    def query1(l:List[Studente]) = {
        // estrarre la lista di tutti gli studenti che hanno un'eta' inferiore alla media
        // e hanno sostenuto almeno tre esami
        val mediaEtà = l.map(_.età).sum.toDouble / l.size
        l.filter(s => s.età < mediaEtà && s.esami.size >= 3)
    }
    def query2(l:List[Studente]) = {
        // estrarre la lista di tutti gli esami che sono stati sostenuti da almeno due studenti
        l.map(_.esami).flatten.groupBy(identity).filter(t=>t._2.size>2).map(_._1).toList
    }
}
