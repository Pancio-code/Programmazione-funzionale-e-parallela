object A1 {
	def select(l: List[Car]) : List[(Int,String)] = {
		l.map( c => (c.year,l.filter( a => a.year == c.year).minBy( _.owner.age).owner.name)).distinct
	}
}
