object A2 {
	def query1(l : List[Studente]) : List[Studente] = {
		l.filter( e => (e.età < l.foldLeft(0)( _ + _.età) / l.length) && e.esami.length > 2)
	}
	def query2(l : List[Studente]) : List[String] = {
		l.map( s => s.esami.filter( e => l.exists( s1 => s1 != s && s1.esami.contains(e)))).flatten.distinct
	}
}
