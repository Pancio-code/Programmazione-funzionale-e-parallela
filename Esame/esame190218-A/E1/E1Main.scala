import E1._

object E1Main extends App {

    var punti = 0
    var test  = 0

    def doTest[T](l:List[T], c:Set[T]) = {
        test += 1
        val r:Set[T] = l.getDup
        println("Test " + test + ": " + r + " [corretto: "+ c + "]")
        if (r == c) punti += 1
    }

    doTest(List(), Set())
    doTest(List(9,2,1,3,3,6,3,9,1), Set(9,1,3))
    doTest(List('a','b','c','d','b','d'), Set('b','d'))
    doTest(List(false, true), Set())
    doTest(List("three", "two", "one", "three"), Set("three"))
    println("*** Result: " + punti + "/" + test)
}
