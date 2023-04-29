sealed abstract class Tree {
    def max(l:Tree,e:Int,r:Tree) : Int = (l,r) match{
	case (E(),E()) => e
	case (T(l1,e1,r1),T(l2,e2,r2)) => List(e,e1,max(l1,e1,r1),max(l2,e2,r2)).max
    }
    def min(l:Tree,e:Int,r:Tree) : Int = (l,r) match{
	case (E(),E()) => e
	case (T(l1,e1,r1),T(l2,e2,r2)) => List(e,e1,max(l1,e1,r1),max(l2,e2,r2)).min
    }
    def treeTest:Boolean = this match {
        case E() => true
	case T(l,e,r) => (l,r) match {
		case (E(),E()) => true
		case (T(l1,e1,r1),E()) => e >= max(l1,e1,r1) && l.treeTest
		case (E(),T(l1,e1,r1)) => e <= min(l1,e1,r1) && r.treeTest
		case (T(l1,e1,r1),T(l2,e2,r2)) => e >= max(l1,e1,r1)	&& e <= min(l2,e2,r2) && l.treeTest && r.treeTest	
	}
    }
}

// albero non vuoto
case class T(l:Tree, e:Int, r:Tree) extends Tree

// albero vuoto
case class E() extends Tree
