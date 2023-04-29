// Scrivi la soluzione qui...
object E4 {
	def piuGiovane(s:Vector[Studente], e:Vector[Eta]): Option[String] = {
		if(s.isEmpty) None
		else Some(s.find( _.id == e.minBy( _.eta).id).get.nome)
	}
}
