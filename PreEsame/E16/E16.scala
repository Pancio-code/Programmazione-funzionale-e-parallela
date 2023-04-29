object E16 {
	def mediaVeicoli(l:List[Int]) : Double = {
		l.span(_ > 0)._1.reduce(_+_).toDouble/l.span(_ > 0)._1.length
	}
}
