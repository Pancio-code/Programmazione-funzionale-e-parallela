case class Option[T](x: T,n: Int)

object E31Main extends App {
	def piùFrequente[T](l:Seq[T]):Option[(T,Int)] = {
		if(l.isEmpty) None
		Option(l.map( x => (x,l.count(_ == x))).maxBy(_._2)._1,l.map( x => (x,l.count(_ == x))).maxBy(_._2)._2)
	}

    val s1 = Seq(1,2,4,2,1,1,5,2,4,2,5)
    val t1 = piùFrequente(s1) getOrElse "errore"
    println(t1 + " (corretto: (2,4))")

    val s2 = Seq()
    val t2 = piùFrequente(s2) getOrElse "errore"
    println(t2 + " (corretto: errore)")

    val s3 = Vector("uno", "due", "uno")
    val t3 = piùFrequente(s3) getOrElse "errore"
    println(t3 + " (corretto: (uno,2))")
}
