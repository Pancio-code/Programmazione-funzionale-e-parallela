case class Studente(val nome:String, val età:Int, val esami:List[String])

object A2Main extends App {
    val q = List(
              Studente("Marco", 24, List("PFP","SC")),
              Studente("Laura", 19, List("SC", "FI1", "PFP", "DB")),
              Studente("Stefano", 23, List("SC", "FI1")),
              Studente("Marco", 25, List("SC", "FI1", "FI2")),
              Studente("Paola", 21, List("SC", "PFP")),
              Studente("Lucia", 18, List("SC", "PFP", "OOP"))
            )

    // query1 estrae la lista di tutti gli studenti che hanno
    // età inferiore alla media e hanno sostenuto almeno tre esami
    val query1:List[Studente] = A2.query1(q)
    println(query1.map(_.nome))
    println("--> [corretto: Laura e Lucia]")

    // query2 estrae la lista di tutti gli esami che sono stati
    // sostenuti da almeno due studenti
    val query2:List[String] = A2.query2(q)
    println(query2)
    println("--> [corretto: SC, FI1 e PFP]")
}
