object B1Main extends App {
    def test(e:Exp, c:Exp) {
        val s:Exp = e.simplify
        println(s + " ["+ (if (c==s) "ok" 
                           else "errore, dovrebbe essere: "+c) +"]")
    }
    test( And(Not(False()),X()), X() )
    test( And(X(),True()), X() )
    test( And(X(),False()), False() )
    test( And(False(),X()), False() )
    test( Or(False(),X()), X() )
    test( Or(X(),False()), X() )
    test( Or(X(),True()), True() )
    test( Or(True(),X()), True() )
    test( And(Not(And(False(),Not(Y()))), Not(Or(X(),False()))), Not(X()))
}
