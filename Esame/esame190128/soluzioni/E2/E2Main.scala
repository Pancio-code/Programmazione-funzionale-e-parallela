object E2Main extends App {

    var punti = 0
    var test = 0

    def doTest[T](l:Seq[T], idx:Set[Int], c:Seq[T]) = {
        test += 1
        val r = E2.extract(l, idx)
        println("Test " + test + ": " + r + " [corretto: "+ c + "]")
        if (r == c) punti += 1
    }

    doTest(Seq("zero", "one", "two", "three", "four", "five"),
           Set(1,3,4),
           Seq("one", "three", "four"))

    doTest(Seq(true, false, true),
           Set(0,2),
           Seq(true, true))

    doTest(Seq(1, 2, 3),
           Set(),
           Seq())

    println("*** Result: " + punti + "/" + test)
}
