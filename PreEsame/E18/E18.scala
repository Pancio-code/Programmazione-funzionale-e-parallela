object E18Main extends App {
	def filterByIndex[T](l:List[T],f: Int => Boolean) : List[T] = {
		l.zipWithIndex.filter(x => f(x._2)).map(x => x._1)
	}
	println(filterByIndex(List("zero", "uno", "due", "tre"), i=>i%2==0))
}
