sealed abstract class Tree {
    def treeTest : Boolean = this match {
		case E() => true
		case T(l,e,r) =>(l,r) match {
			case (E(),E()) =>  true
			case (E(),T(l1,e1,r1)) => e <= e1 && l.treeTest && r.treeTest
			case (T(l1,e1,r1),E()) => e >= e1 && l.treeTest && r.treeTest
			case (T(l1,e1,r1),T(l2,e2,r2)) => e >= e1 && e <= e2 && l.treeTest && r.treeTest
		}
	}
}

// albero non vuoto
case class T(l:Tree, e:Int, r:Tree) extends Tree 

// albero vuoto
case class E() extends Tree
