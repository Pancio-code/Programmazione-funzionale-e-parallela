case class Studente(val nome:String, val età:Int, val esami:List[String])

object B3Main extends App {
    val q = List(
              Studente("Marco", 24, List("PFP","SC")),
              Studente("Laura", 19, List("SC", "FI1", "PFP", "DB")),
              Studente("Stefano", 23, List("SC", "FI1")),
              Studente("Marina", 25, List("SC", "FI1", "FI2")),
              Studente("Paola", 21, List("SC", "PFP")),
              Studente("Lucia", 18, List("SC", "PFP", "OOP"))
            )

    // query1 produce una lista di coppie 
    // (esame, lista nomi studenti con almeno 22 anni che l'hanno superato)
    val query1:List[(String, List[String])] = B3.query1(q)
    println(query1)
    println("--> [corretto: List((SC,List(Marco, Stefano, Marina)), "+
                  "(FI1,List(Stefano, Marina)), (PFP,List(Marco)), "+
                  "(FI2,List(Marina))) (in qualsiasi ordine)]")

    // query2 produce la lista di tutte le coppie di esami per cui esistono 
    // almeno due studenti che li ha superati entrambi
    val query2:List[(String,String)] = B3.query2(q)
    println(query2)
    println("--> [corretto: List((PFP,SC), (FI1,SC))]")
}
