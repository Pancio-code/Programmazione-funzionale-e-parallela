object E1 {
	def scalarProd(a1: Seq[Double],a2: Seq[Double]):Double = {
		//versione usando ricorsione
		/*if(a1.isEmpty || a2.isEmpty) 0.0
		else a1.head * a2.head + scalarProd(a1.tail,a2.tail)*/

		//versione con metodi delle liste
		(a1 zip a2).foldLeft(0)( (x,y) => x._1 * x._2 + y._1 * y._2)		
	}
}
