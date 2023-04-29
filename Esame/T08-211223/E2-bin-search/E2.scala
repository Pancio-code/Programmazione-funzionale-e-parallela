sealed abstract class Tree {
    def treeTest:Boolean = this match {
        case E() => true
        case T(l,e,r) => e >= l.max && e <= r.min
    }
    def max:Int = this match {
		case E() => Int.MinValue
		case T(l,e,r) => List(l.max,e,r.max).max
	}
	def min :Int = this match {
		case E() => Int.MaxValue
		case T(l,e,r) => List(l.min,e,r.min).min
	}
}

// albero non vuoto
case class T(l:Tree, e:Int, r:Tree) extends Tree

// albero vuoto
case class E() extends Tree
