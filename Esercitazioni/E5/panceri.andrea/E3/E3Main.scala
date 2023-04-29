import E3._

object E3Main extends App{
    var test:Int = 0
    var punti:Int = 0

    def test(x:Int, corretto:Boolean) {
        test+=1
        val res:Boolean = x.isPrime
        println("Test "+test+": "+res+" (corretto: "+corretto+")")
        punti += (if (res == corretto) 1 else 0)
    }

    test(13,true)
    test(50,false)
    test(191,true)
    test(21,false)

    println("Punti: "+punti+"/"+test)
}
