object E2 {
	def corrisp[A,B](a:List[A], b:List[B], f:A=>B):Boolean = {
		a.zip(b).forall(x => x._2 == f(x._1))
	}
}
