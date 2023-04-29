object E1Main extends App {

    var punti = 0
    var test = 0

    def doTest[T,S](t:Tree[T], c:Tree[S], f:T=>S) = {
        test += 1
        val r:Tree[S] = t.map(f)
        println("Test " + test + ": " + r + " [corretto: "+ c + "]")
        if (r == c) punti += 1
    }

    doTest[Int,Int](E(), E(), _*2)
    doTest[Int,Int](L(7), L(14), _*2)
    doTest[Int,String](N(E(), 7, L(2)), N(E(), "v7", L("v2")), x => "v"+x)
    doTest[String,Int](N(L("one"), "three", L("zero")), N(L(3), 5, L(4)), _.size)
    doTest[Int,String](N(L(12),2,N(E(),49,L(6))), N(L("12|12"),"2|2",N(E(),"49|49",L("6|6"))), x => x+"|"+x)

    println("*** Result: " + punti + "/" + test)
}
