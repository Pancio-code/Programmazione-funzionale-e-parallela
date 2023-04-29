import java.awt.{Color}

object E2Main extends App {

    var punti = 0
    var test  = 0

    def doTest[T](hour:Int, min:Int, c:List[Shape]) = {
        test += 1
        val r:List[Shape] = E2.getClock(hour, min)
        println("Test " + test + ": " + r + " [corretto: "+ c + "]")
        if (r == c) punti += 1
        Frame2D.display(r, 300, 300)
    }

    doTest(12, 0, List(Circle(0.5,0.5,0.5,Color.GRAY), Line(0.5,0.5,0.5,1.0,Color.RED), Line(0.5,0.5,0.5,0.9,Color.BLUE)))
    doTest(10, 30, List(Circle(0.5,0.5,0.5,Color.GRAY), Line(0.5,0.5,0.5,0.0,Color.RED), Line(0.5,0.5,0.1536,0.7,Color.BLUE)))
    doTest(1, 15, List(Circle(0.5,0.5,0.5,Color.GRAY), Line(0.5,0.5,1.0,0.5,Color.RED), Line(0.5,0.5,0.7,0.8464,Color.BLUE)))
    
    println("*** Result: " + punti + "/" + test)
}
