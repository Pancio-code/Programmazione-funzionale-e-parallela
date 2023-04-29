object A3 {
	def test[T,S](l1 : List[T],l2 : List[S]) : Boolean = {
		!l1.exists( l2.contains(_))
	}
}
