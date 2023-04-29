object E2 {
	def corrisp[A,B](a:List[A], b:List[B], f:A=>B):Boolean = {
		//a.zip(b).forall(x =>. x_2 == f(x._1))
		if(a == Nil || b == Nil) true
		else b.head == f(a.head) && corrisp(a.tail,b.tail,f)
	}
}
