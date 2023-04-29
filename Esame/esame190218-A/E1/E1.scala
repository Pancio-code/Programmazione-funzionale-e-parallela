object E1 {
	implicit def ListToMyList[T](l : List[T]) = new MyList(l)
}

case class MyList[T](l : List[T]) {
	def getDup : Set[T] = {
			l.filter( e => l.count( e1 => e1 == e) > 1).toSet
	}
}
