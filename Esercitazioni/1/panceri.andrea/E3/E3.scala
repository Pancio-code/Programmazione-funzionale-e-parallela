object E3 {
	def sommaQuadrati(x:Int,y:Int) : Int = {
		if(y == x) x*x else y*y + sommaQuadrati(x,y-1)
	}
}
