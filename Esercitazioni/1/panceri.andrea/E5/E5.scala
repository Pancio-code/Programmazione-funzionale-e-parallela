object E5 {
	 def somma(f: Int => Int) : (Int,Int) => Int = {
		def funzioneDaRestituire(a: Int,b: Int) : Int = { // metodo definito localmente (ispirarsi all'esercizio 3)
			if(a == b) f(a) else f(b) + funzioneDaRestituire(a,b-1) 
		}
		funzioneDaRestituire _                  // restituisce metodo locale convertito a funzione con _ 
	}
}
