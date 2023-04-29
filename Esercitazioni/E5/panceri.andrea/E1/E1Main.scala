case class Produttore(idProd:Int, nome:String)
case class Vitigno(idVitigno:Int, nome:String)
case class Vino(idProd:Int,idVitigno:Int,annata:Int)

object E1Main extends App{
    var test:Int = 0
    var punti:Int = 0
    val produttori:List[Produttore] = List(
        Produttore(1,"Rotaliano"),
        Produttore(2,"Sella e Mosca"),
        Produttore(3,"Casale del Giglio")
    )
    val vitigni:List[Vitigno] = List(
        Vitigno(1,"Teroldego"),
        Vitigno(2,"Cabernet"),
        Vitigno(3,"Nero d'Avola")
    )
    val vini:List[Vino] = List(
        Vino(1,1,2016),
        Vino(1,3,2014),
        Vino(2,2,2018),
        Vino(2,3,2010),
        Vino(3,2,2011),
        Vino(3,3,2013)
    )
    def test(produttore:String,annataCorretta:Option[Int]) {
        test+=1
        val vecchio:Option[Int] = E1.annataPiuVecchia(produttori,vitigni,vini,produttore)
        println("Test "+test+": "+produttore+", "+vecchio+" (corretto: "+annataCorretta+")")
        punti += (if (vecchio == annataCorretta) 1 else 0)
    }
    test("Rotaliano",Some(2014))
    test("Sella e Mosca",Some(2010))
    test("Casale del Giglio",Some(2011))
    test("Le Tre Teste",None)
    println("Punti: "+punti+"/"+test)
}
