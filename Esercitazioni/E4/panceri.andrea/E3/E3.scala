object E3 {
	def noobSort[T](v : Vector[T])(implicit cmp:T => Ordered[T]) = {
		v.permutations.find(x=> x == x.sorted).get
	}
}
