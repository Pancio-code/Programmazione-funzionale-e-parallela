object B3 {
    // query1 produce una lista di coppie 
    // (esame, lista studenti con almeno 22 anni che l'hanno superato)
    def query1(q:List[Studente]):List[(String, List[String])] = {
        q.filter(_.età>=22)
         .map(s=>s.esami.map(e=>(e,s.nome)))
         .flatten
         .groupBy(t=>t._1)
         .toList
         .map(t=>(t._1, t._2.map(_._2)))
    }

    // query2 produce la lista di tutte le coppie di esami per cui esistono 
    // almeno due studenti che li hanno superati entrambi
    def query2(q:List[Studente]):List[(String,String)] = {
        val esami = q.map(_.esami).flatten.distinct
        for {
            i <- esami
            j <- esami
            if (i < j) // per non avere sia (a,b) che (b,a)
            if (q.count(s => s.esami.contains(i) && s.esami.contains(j)) >= 2)
        } yield (i,j)
    }
}
