object A1 {
	def select(cars: List[Car],owners: List[String]) : List[String] = {
		owners.map( o => cars.filter( c => c.owner == o).maxBy(_.year).model)
	}
}
