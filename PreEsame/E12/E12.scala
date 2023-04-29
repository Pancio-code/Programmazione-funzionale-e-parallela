object E12 {
	def max1(l:List[String]): Int = {
		l.map(_.length).reduce(_ max _)
	} 
}
