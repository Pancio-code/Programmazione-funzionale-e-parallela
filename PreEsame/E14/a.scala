object a {
	def myMap(l : List[Int],f:Int => Any) : List[Any] = {
		if(l == Nil) Nil
		else f(l.head) :: myMap(l.tail,f)
	}
}
