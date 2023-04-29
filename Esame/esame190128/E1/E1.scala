sealed abstract class Tree[T] {
	def map[S](f:T=>S):Tree[S] = this match {
		case E() => E()
		case L(e) => L(f(e))
		case N(l,e,r) => N(l.map(f),f(e),r.map(f))
	}	
}
case class E[T]() extends Tree[T]
case class L[T](e:T) extends Tree[T]
case class N[T](l:Tree[T], e:T, r:Tree[T]) extends Tree[T]

