sealed abstract class Exp {
    def apply(x:Boolean, y:Boolean):Boolean = this match {
        case And(a,b) => a(x,y) && b(x,y)
        case Or(a,b) => a(x,y) || b(x,y)
        case Not(a) => !a(x,y)
        case X() => x
        case Y() => y
        case True() => true
        case False() => false
    }
    override def toString:String = this match {
        case And(a,b) => "and("+a.toString+","+b.toString+")"
        case Or(a,b) => "or("+a.toString+","+b.toString+")"
        case Not(a) => "not("+a.toString+")"
        case X() => "x"
        case Y() => "y"
        case True() => "true"
        case False() => "false"
    }
    def <=>(b:Exp) =
        this(false,false) == b(false,false) &&
        this(false,true)  == b(false,true)  &&
        this(true,false)  == b(true,false)  &&
        this(true,true)   == b(true,true)
}

case class And(a:Exp, b:Exp) extends Exp
case class Or(a:Exp, b:Exp) extends Exp
case class Not(a:Exp) extends Exp
case class X() extends Exp
case class Y() extends Exp
case class True() extends Exp
case class False() extends Exp
