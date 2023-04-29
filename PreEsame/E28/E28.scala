import scala.language.implicitConversions

class Cifrario(s: String) {
	def rot(k:Int):String = {
		def convert(c: Char) : Char = {
			if(c >= 'A' && c <= 'Z') (('A').toInt + (c.toInt - 'A'.toInt + k) % 26).toChar
			else if(c >= 'a' && c <= 'z') (('a').toInt + (c.toInt - 'a'.toInt + k) % 26).toChar
			else c
		}
		s.map(convert(_))
	}
}

object E28 {
	implicit def String2Cifrario(s: String) = new Cifrario(s)
}
