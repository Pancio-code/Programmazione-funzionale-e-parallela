sealed abstract class Tree[A] {
    	def mapTree[B](t:Tree[B], f:A=>B):Boolean = this match {
		case E() => t match {
				case E() => true
				case _ => false
			}
		case T(l,e,r) =>(l,r) match {
			case (E(),E()) =>  t match {
				case T(E(),eB,E()) => f(e) == eB && r.mapTree(E(),f) && l.mapTree(E(),f)
				case _ => false
			}
			case (E(),T(l1,e1,r1)) => t match {
				case T(E(),eB,T(lB,e1,rB)) => f(e) == eB && r.mapTree(T(lB,e1,rB),f) && l.mapTree(E(),f)
				case _ => false
			}
			case (T(l1,e1,r1),E()) => t match {
				case T(T(lB,e1,rB),eB,E()) => f(e) == eB && l.mapTree(T(lB,e1,rB),f) && r.mapTree(E(),f)
				case _ => false
			}
			case (T(l1,e1,r1),T(l2,e2,r2)) => t match {
				case T(T(lB,e1,rB),eB,T(lB2,e2,rB2)) => f(e) == eB && l.mapTree(T(lB,e1,rB),f) && r.mapTree(T(lB2,e2,rB2),f)
				case _ => false
			}
		}
	}
}

case class T[S](l:Tree[S], e:S, r:Tree[S]) extends Tree[S]
case class E[S]() extends Tree[S]
