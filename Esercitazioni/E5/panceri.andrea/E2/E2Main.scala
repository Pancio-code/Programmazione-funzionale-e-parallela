object E2Main extends App{
    var test:Int = 0
    var punti:Int = 0

    def test[A,B](t1:Tree[A], t2:Tree[B], f:A=>B, corretto:Boolean) {
        test+=1
        val res:Boolean = t1.mapTree(t2,f)
        println("Test "+test+": "+res+" (corretto: "+corretto+")")
        punti += (if (res == corretto) 1 else 0)
    }

    val t1:Tree[Int] = T(T(E(),2,E()),1,E())
    val t2:Tree[Double] = T(T(E(),4.0,E()),2.0,E())
    val t3:Tree[Double] = T(T(E(),5.0,E()),2.0,E())
    val t4:Tree[Double] = T(E(),2.0,E())

    test(t1,t2,(v:Int)=>2.0*v, true)
    test(t1,t3,(v:Int)=>2.0*v, false)
    test(t1,t4,(v:Int)=>2.0*v, false)

    println("Punti: "+punti+"/"+test)
}
