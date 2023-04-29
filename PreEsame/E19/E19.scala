object E19 extends App {
	def query(studenti:List[(String,Int)], esami:List[(String,String)]):Int = {
		studenti.groupBy(_._2).toList.map(studentiPerEta => (studentiPerEta._1,studentiPerEta._2.map(studente => esami.count( _._1 == studente._1)).reduce(_+_))).maxBy(_._2)._1 
	}
	val studenti = List(("Paola", 21), ("Luca", 22), ("Lucia", 21), ("Matteo",22))
	val esami = List(("Paola","PFP"), ("Luca","SC"), ("Paola","DB"), ("Lucia","LTW"), ("Matteo","SO"), ("Lucia","PFP"))
	println("Età studenti con più esami è: " + query(studenti,esami))
}
