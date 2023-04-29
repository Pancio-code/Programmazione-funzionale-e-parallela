sealed abstract class Exp {
    def simplify:Exp = {
        this match {
            case And(a,b) => 
                (a.simplify,b.simplify) match {
                    case (True(),sb) => sb
                    case (sa,True()) => sa
                    case (_,False()) => False()
                    case (False(),_) => False()
                    case (sa,sb) => And(sa,sb)
                }
            case Or(a,b) => 
                (a.simplify,b.simplify) match {
                    case (True(),_) => True()
                    case (_,True()) => True()
                    case (sa,False()) => sa
                    case (False(),sb) => sb
                    case (sa,sb) => Or(sa,sb)
                }
            case Not(a) => a.simplify match {
                case True() => False()
                case False() => True()
                case as => Not(as)
            }
            case e => e
        }
    }
}

case class And(a:Exp, b:Exp) extends Exp
case class Or(a:Exp, b:Exp) extends Exp
case class Not(a:Exp) extends Exp
case class X() extends Exp
case class Y() extends Exp
case class True() extends Exp
case class False() extends Exp
